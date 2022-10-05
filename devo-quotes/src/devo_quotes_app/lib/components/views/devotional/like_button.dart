import 'dart:math';

import 'package:devo_quotes_app/models/backend/firebase/tap_repository.dart';
import 'package:devo_quotes_app/models/theme/colors.dart';
import 'package:devo_quotes_app/models/theme/fonts.dart';
import 'package:devo_quotes_package/domains/tap_domain/use_cases/create_tap.dart';
import 'package:devo_quotes_package/tap.dart';
import 'package:flutter/cupertino.dart';

///
/// like_button.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/7/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

class LikeButton extends StatelessWidget {
  final TapRepository _tapRepo = TapRepository();
  final User user;
  LikeButton(this.user, {Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
      decoration:
          BoxDecoration(borderRadius: BorderRadius.circular(20), boxShadow: [
        BoxShadow(
            color: byuIBlack.withOpacity(.3),
            spreadRadius: -2,
            offset: Offset(-4, -6),
            blurRadius: 6)
      ]),
      child: CupertinoButton(
          minSize: double.infinity,
          padding: EdgeInsets.symmetric(horizontal: 8.0),
          borderRadius: BorderRadius.vertical(top: Radius.circular(20)),
          child: Stack(
            children: [
              Padding(
                padding: const EdgeInsets.all(16.0),
                child: Center(
                  child: LayoutBuilder(builder: (context, constraint) {
                    return Transform.rotate(
                      angle: pi * 4 / 3,
                      child: Icon(
                        CupertinoIcons.hand_point_right_fill,
                        color: byuIWhite,
                        size: constraint.biggest.height,
                      ),
                    );
                  }),
                ),
              ),
              Padding(
                padding: const EdgeInsets.all(8.0),
                child: Align(
                  alignment: Alignment.topCenter,
                  child: Text(
                    "TAP when you hear something you like",
                    style: lightText,
                    textAlign: TextAlign.center,
                  ),
                ),
              ),
            ],
          ),
          onPressed: _createTap,
          color: byuIBlue.withOpacity(.75)),
    );
  }

  _createTap() async {
    DefaultCreateTapUseCase create = DefaultCreateTapUseCase(_tapRepo);
    Tap tap = Tap(user: user, timeStamp: DateTime.now());
    Result<bool> result = await create.execute(tap);
    if (result.isError) print(result.asError!.error);
  }
}
