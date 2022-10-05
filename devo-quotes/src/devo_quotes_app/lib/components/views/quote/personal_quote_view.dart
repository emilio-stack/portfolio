import 'package:devo_quotes_app/components/views/quote/quote_view.dart';
import 'package:devo_quotes_package/domains/quote_domain/personal_quote.dart';
import 'package:flutter/cupertino.dart';

///
/// personal_quote_view.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/6/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

class PersonalQuoteView extends QuoteView<PersonalQuote> {
  const PersonalQuoteView(PersonalQuote quote, {Key? key})
      : super(quote: quote, key: key);
}
