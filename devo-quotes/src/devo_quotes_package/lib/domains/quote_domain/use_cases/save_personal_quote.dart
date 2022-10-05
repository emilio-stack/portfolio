import 'package:async/async.dart';
import 'package:devo_quotes_package/quote.dart';
import 'package:flutter/foundation.dart';

///
/// save_community_quote.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/4/21
/// Copyright 2021 Porter McGary.  All rights reserved.
///

mixin SavePersonalQuoteUseCase {
  @required
  Future<Result<bool>> execute(PersonalQuote quote);
}

class DefaultSavePersonalQuoteUseCase implements SavePersonalQuoteUseCase {
  QuoteRepo _quoteRepo;
  DefaultSavePersonalQuoteUseCase(this._quoteRepo);

  @override
  Future<Result<bool>> execute(PersonalQuote quote) {
    return _quoteRepo.store(quote);
  }
}
