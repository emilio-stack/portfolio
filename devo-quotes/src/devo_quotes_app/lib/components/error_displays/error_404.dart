import 'package:devo_quotes_app/models/theme/colors.dart';
import 'package:devo_quotes_app/models/theme/fonts.dart';
import 'package:flutter/cupertino.dart';

///
/// error_404.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/6/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

class Error404 extends StatelessWidget {
  final String? msg;
  final Color background;

  const Error404({this.msg, this.background = byuIWhite, Key? key})
      : super(key: key);

  @override
  Widget build(BuildContext context) {
    String text = "Error404 ☹️";
    TextStyle style = darkText;

    if (msg != null) text += "\n\n" + msg!;
    if (background == byuIDarkGrey) style = TextStyle(color: byuIWhite);

    return Container(
        color: background,
        child: Center(
            child: Text(
          text,
          textAlign: TextAlign.center,
          style: style,
        )));
  }
}
