import 'package:devo_quotes_package/quote.dart';
import 'package:devo_quotes_package/user.dart';
import 'package:flutter/foundation.dart';
import 'package:async/async.dart';

///
/// get_personal_quotes.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/4/21
/// Copyright 2021 Porter McGary.  All rights reserved.
///

mixin GetPersonalQuotesUseCase {
  @required
  Future<Result<List<PersonalQuote>>> execute(User user);
}

class DefaultGetPersonalQuotesUseCase implements GetPersonalQuotesUseCase {
  QuoteRepo _quoteRepo;

  DefaultGetPersonalQuotesUseCase(this._quoteRepo);

  @override
  Future<Result<List<PersonalQuote>>> execute(User user) async {
    List<PersonalQuote>? quotes = await _quoteRepo.findAllByID(user);
    if (quotes == null) return Result.error("List is null");
    return Result.value(quotes);
  }
}
