import 'package:devo_quotes_package/quote.dart';
import 'package:flutter/foundation.dart';
import 'package:async/async.dart';

///
/// get_community_quotes.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/4/21
/// Copyright 2021 Porter McGary.  All rights reserved.
///

mixin GetCommunityQuotesUseCase {
  @required
  Future<Result<List<CommunityQuote>>> execute();
}

class DefaultGetCommunityQuotesUseCase implements GetCommunityQuotesUseCase {
  QuoteRepo _quoteRepo;
  DefaultGetCommunityQuotesUseCase(this._quoteRepo);

  @override
  Future<Result<List<CommunityQuote>>> execute() async {
    List<CommunityQuote>? quotes = await _quoteRepo.findAll();
    if (quotes == null) return Result.error("List is null");
    return Result.value(quotes);
  }
}
