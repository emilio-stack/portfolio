import 'package:devo_quotes_app/components/error_displays/error_404.dart';
import 'package:devo_quotes_app/models/theme/colors.dart';
import 'package:devo_quotes_app/models/theme/fonts.dart';
import 'package:devo_quotes_package/talk.dart';
import 'package:flutter/cupertino.dart';
import 'package:intl/intl.dart';

///
/// speaker.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/7/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

class Speaker extends StatelessWidget {
  final Talk _talk;

  const Speaker(this._talk, {Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    DateFormat formatter = DateFormat.MMMd();

    return Padding(
      padding: const EdgeInsets.only(top: 8.0, bottom: 32.0),
      child: Container(
        decoration: BoxDecoration(
            color: byuIDarkGrey.withOpacity(.9),
            borderRadius: BorderRadius.circular(20),
            boxShadow: [
              BoxShadow(
                  color: byuIBlack.withOpacity(.5),
                  spreadRadius: 2,
                  blurRadius: 7,
                  offset: Offset(4, 5))
            ]),
        child: Padding(
          padding: const EdgeInsets.symmetric(vertical: 8.0, horizontal: 32),
          child: Column(
            children: [
              Text("Your listening to", style: lightText),
              Text(_talk.talk.author, style: lightTitleText),
              Flexible(
                  child: Padding(
                padding: const EdgeInsets.symmetric(vertical: 16.0),
                child: Image.network(_talk.talk.image,
                    errorBuilder: (context, exception, stack) {
                  return Error404(
                    msg: "Failed to load image",
                    background: byuIDarkGrey,
                  );
                }),
              )),
              Text(_talk.talk.title,
                  textAlign: TextAlign.left, style: lightTextItalicized),
              Text(formatter.format(_talk.talk.dateGiven) + " at 11:30 am",
                  textAlign: TextAlign.left, style: lightCaptionText)
            ],
          ),
        ),
      ),
    );
  }
}
