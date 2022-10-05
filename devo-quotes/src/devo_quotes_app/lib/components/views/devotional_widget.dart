import 'package:devo_quotes_app/components/error_displays/error_404.dart';
import 'package:devo_quotes_app/components/loading_indicators/loading_indicator.dart';
import 'package:devo_quotes_app/components/views/devotional/like_button.dart';
import 'package:devo_quotes_app/components/views/quotes_widget.dart';
import 'package:devo_quotes_app/models/backend/firebase/talk_repository.dart';
import 'package:devo_quotes_app/models/backend/firebase/user_repository.dart';
import 'package:devo_quotes_app/models/theme/colors.dart';
import 'package:devo_quotes_app/notifications/devotional_ended_notification.dart';
import 'package:devo_quotes_app/notifications/error_notification.dart';
import 'package:devo_quotes_package/domains/user_domain/use_cases/get_user.dart';
import 'package:devo_quotes_package/talk.dart';
import 'package:devo_quotes_package/tap.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:timezone/timezone.dart';

import 'devotional/speaker.dart';

///
/// devotional_widget.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/5/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

class DevotionalWidget extends StatelessWidget {
  final TalkRepository _talkRepo = TalkRepository();
  final User _user;
  final Talk _mockTalk = Talk(
      talk: TalkDetails(
          author: "Porter McGary",
          title: "God Be with You Always",
          image:
              "https://images.unsplash.com/photo-1506794778202-cad84cf45f1d?ixid=MnwxMjA3fDB8MHxzZWFyY2h8Mnx8bWVufGVufDB8fDB8fA%3D%3D&ixlib=rb-1.2.1&auto=format&fit=crop&w=400&q=60",
          dateGiven: DateTime.now()),
      transcripts: [
        Transcript(
            content: "Some words",
            start: DateTime.now(),
            end: DateTime.now().add(Duration(seconds: 1)))
      ]);

  DevotionalWidget(this._user, {Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return CupertinoPageScaffold(
      backgroundColor: byuIDarkGrey.withOpacity(.5),
      child: SafeArea(
        bottom: false,
        child: Column(
          mainAxisSize: MainAxisSize.max,
          children: [
            Expanded(
                child: FutureBuilder<Talk?>(
                    future: _getTalk(),
                    builder: (context, snapshot) {
                      if (kDebugMode)
                        return GestureDetector(
                            child: Speaker(_mockTalk),
                            onDoubleTap: () => _switchBetween(context));
                      if (snapshot.hasError)
                        return Container(
                            child: Error404(
                                msg: snapshot.error.toString(),
                                background: byuIDarkGrey));
                      if (snapshot.hasData) {
                        if (snapshot.data == null)
                          return Container();
                        else
                          return Speaker(snapshot.data!);
                      }
                      return LoadingIndicator(
                        background: byuIDarkGrey,
                      );
                    })),
            Expanded(child: LikeButton(_user)),
          ],
        ),
      ),
    );
  }

  Future<Talk?> _getTalk() async {
    DefaultGetTalkUseCase getTalkUseCase = DefaultGetTalkUseCase(_talkRepo);
    Result<Talk?> result = await getTalkUseCase.execute("url");
    if (result.isError) throw result.asError!.error;
    return result.asValue!.value;
  }

  void _switchBetween(BuildContext context) async {
    UserRepository _userRepo = UserRepository();
    DefaultGetUserUseCase getUserUseCase = DefaultGetUserUseCase(_userRepo);
    Result<User> result = await getUserUseCase.execute();
    if (result.isError) {
      ErrorNotification error = ErrorNotification("Failed to get user");
      error.notify();
      return;
    }
    Navigator.pushReplacement(
        context,
        CupertinoPageRoute(
            builder: (context) =>
                QuotesWidget(result.asValue!.value, quotesArePending: true)));
    DevotionalEndedNotification devotionalEnded = DevotionalEndedNotification();
    TZDateTime scheduledTime =
        TZDateTime.from(DateTime.now().add(Duration(seconds: 2)), local);
    devotionalEnded.schedule(scheduledTime);
  }
}
