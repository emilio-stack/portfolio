import 'package:devo_quotes_app/models/theme/colors.dart';
import 'package:devo_quotes_app/models/theme/fonts.dart';
import 'package:devo_quotes_package/quote.dart';
import 'package:flutter/cupertino.dart';
import 'package:intl/intl.dart';

///
/// quote_view.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/6/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

class QuoteView<T> extends StatelessWidget {
  final Quote<T> quote;

  const QuoteView({required this.quote, Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    DateFormat formatter = DateFormat.yMMMMEEEEd();
    String dateOfTalk = formatter.format(quote.talkDetails.dateGiven);

    return Padding(
      padding: const EdgeInsets.only(bottom: 8.0, left: 8.0, right: 8.0),
      child: Container(
        decoration: BoxDecoration(
            boxShadow: [
              BoxShadow(
                  color: byuIBlack.withOpacity(.2),
                  spreadRadius: -2,
                  blurRadius: 4,
                  offset: Offset(5, 5))
            ],
            // border: Border.all(color: CupertinoColors.black),
            color: byuIWhite,
            borderRadius: BorderRadius.circular(20)),
        child: Padding(
          padding: const EdgeInsets.all(16.0),
          child: Column(
            mainAxisSize: MainAxisSize.max,
            children: [
              Align(
                  alignment: Alignment.topRight,
                  child: Text(dateOfTalk, style: greyCaptionText)),
              Text('"${quote.content}"',
                  textAlign: TextAlign.center, style: darkText),
              Row(
                children: [
                  if (quote.runtimeType == CommunityQuote)
                    Text((quote as CommunityQuote).taps.toString(),
                        style: darkText),
                  if (quote.runtimeType == CommunityQuote)
                    Icon(
                      CupertinoIcons.hand_thumbsup_fill,
                      color: byuIBlue,
                      size: 16,
                    ),
                  Expanded(
                    child: Text(
                      '- ${quote.talkDetails.author}',
                      textAlign: TextAlign.right,
                      style: darkText,
                    ),
                  ),
                ],
              )
            ],
          ),
        ),
      ),
    );
  }
}
