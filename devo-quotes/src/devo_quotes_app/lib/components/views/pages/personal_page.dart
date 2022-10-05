import 'package:devo_quotes_app/components/views/pages/quote_page.dart';
import 'package:devo_quotes_app/components/views/pages/quote_page_model.dart';
import 'package:devo_quotes_package/quote.dart';

///
/// personal_page.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/6/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

class PersonalPage extends QuotePage<PersonalQuote> {
  final User user;

  PersonalPage(this.user, {bool quotesArePending = false})
      : super(PersonalQuotePageModel(user), quotesArePending: quotesArePending);
}
