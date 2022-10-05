import 'package:devo_quotes_app/components/views/pages/quote_page.dart';
import 'package:devo_quotes_app/components/views/pages/quote_page_model.dart';
import 'package:devo_quotes_package/domains/quote_domain/community_quote.dart';
import 'package:devo_quotes_package/quote.dart';

///
/// community_page.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/6/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

class CommunityPage extends QuotePage<CommunityQuote> {
  CommunityPage({bool quotesArePending = false})
      : super(CommunityQuotePageModel(), quotesArePending: quotesArePending);
}
