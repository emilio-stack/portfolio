
import 'package:devo_quotes_package/quote.dart';
import 'package:flutter/foundation.dart';
import 'package:async/async.dart';

///
/// save_community_quote.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/4/21
/// Copyright 2021 Porter McGary.  All rights reserved.
///

mixin SaveCommunityQuoteUseCase {
  @required
  Future<Result<bool>> execute(CommunityQuote quote);
}

class DefaultSaveCommunityQuoteUseCase implements SaveCommunityQuoteUseCase {
  QuoteRepo _quoteRepo;

  DefaultSaveCommunityQuoteUseCase(this._quoteRepo);

  @override
  Future<Result<bool>> execute(CommunityQuote quote) {
    return _quoteRepo.store(quote);
  }
}
