import 'package:async/async.dart';
import 'package:devo_quotes_package/quote.dart';
import 'package:devo_quotes_package/user.dart';
import 'package:flutter/foundation.dart';

///
/// quote_repo.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/4/21
/// Copyright 2021 Porter McGary.  All rights reserved.
///

mixin QuoteRepo {
  @required
  Future<Result<bool>> store(Quote quote);

  @required
  Future<List<CommunityQuote>?> findAll();

  @required
  Future<List<PersonalQuote>?> findAllByID(User user);
}