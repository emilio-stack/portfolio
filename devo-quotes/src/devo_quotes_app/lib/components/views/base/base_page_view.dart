import 'package:devo_quotes_app/components/views/devotional_widget.dart';
import 'package:devo_quotes_app/models/backend/firebase/user_repository.dart';
import 'package:devo_quotes_app/models/theme/colors.dart';
import 'package:devo_quotes_app/notifications/devotional_notification.dart';
import 'package:devo_quotes_app/notifications/devotional_starting_notification.dart';
import 'package:devo_quotes_app/notifications/error_notification.dart';
import 'package:devo_quotes_package/domains/user_domain/user.dart';
import 'package:devo_quotes_package/user.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:timezone/timezone.dart';

///
/// base_page_view.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/6/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

class BasePage extends StatelessWidget {
  final Widget child;
  final Color background;

  const BasePage(
      {required this.child, this.background = byuILightGrey, Key? key})
      : super(key: key);

  @override
  Widget build(BuildContext context) {
    return SafeArea(
        child: Container(
      color: background,
      child: Center(
        child: Column(
          mainAxisSize: MainAxisSize.max,
          children: [
            Row(
              mainAxisSize: MainAxisSize.max,
              children: [
                Expanded(
                  child: Container(
                    decoration:
                        BoxDecoration(color: CupertinoColors.white, boxShadow: [
                      BoxShadow(
                          color: CupertinoColors.black.withOpacity(.3),
                          offset: Offset(0, 4),
                          spreadRadius: -2,
                          blurRadius: 4)
                    ]),
                    child: Padding(
                      padding: const EdgeInsets.all(8.0),
                      child: GestureDetector(
                        onDoubleTap: () => _switchBetween(context),
                        child: Text("Devo",
                            style: TextStyle(
                                color: Color.fromRGBO(0, 110, 182, 1),
                                fontSize: 20),
                            textAlign: TextAlign.center),
                      ),
                    ),
                  ),
                ),
              ],
            ),
            Expanded(
              child: Stack(
                children: [
                  Align(alignment: Alignment.center, child: child),
                  Align(
                      alignment: Alignment.bottomCenter,
                      child: GestureDetector(
                        child: Image.asset("imgs/taylor_building.png"),
                        onDoubleTap: _notifyDevoStarting,
                        onTap: _notifyDevoIn15Minutes,
                      ))
                ],
              ),
            ),
          ],
        ),
      ),
    ));
  }

  void _switchBetween(BuildContext context) async {
    if (kDebugMode) {
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
              builder: (context) => DevotionalWidget(result.asValue!.value)));
    }
  }

  void _notifyDevoIn15Minutes() {
    if (kDebugMode) {
      DevotionalNotification devo = DevotionalNotification();
      TZDateTime scheduledTime =
          TZDateTime.from(DateTime.now().add(Duration(seconds: 30)), local);
      devo.schedule(scheduledTime);
    }
  }

  void _notifyDevoStarting() {
    if (kDebugMode) {
      DevotionalStartingNotification devo = DevotionalStartingNotification();
      TZDateTime scheduledTime =
          TZDateTime.from(DateTime.now().add(Duration(seconds: 30)), local);
      devo.schedule(scheduledTime);
    }
  }
}
