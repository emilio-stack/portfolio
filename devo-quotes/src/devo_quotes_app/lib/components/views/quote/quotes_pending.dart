import 'package:devo_quotes_app/models/theme/fonts.dart';
import 'package:flutter/cupertino.dart';

///
/// quotes_pending.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/8/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

class QuotesPending extends StatelessWidget {
  const QuotesPending({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.only(bottom: 8.0),
      child: Container(
        child: Text(
            "Quotes are processing...\nWe will notify you when they are done",
            style: darkGreyCaptionText,
            textAlign: TextAlign.center),
      ),
    );
  }
}
