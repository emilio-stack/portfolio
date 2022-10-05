import 'package:devo_quotes_package/domains/tap_domain/tap_repo.dart';
import 'package:devo_quotes_package/tap.dart';
import 'package:devo_quotes_package/user.dart';
import 'package:flutter/foundation.dart';
import 'package:async/async.dart';

///
/// get_personal_taps.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/4/21
/// Copyright 2021 Porter McGary.  All rights reserved.
///

mixin GetPersonalTapsUseCase {
  @required
  Future<Result<List<Tap>>> execute(DateTime date, User user);
}

class DefaultGetPersonalTapsUseCase implements GetPersonalTapsUseCase {
  TapRepo _tapRepo;

  DefaultGetPersonalTapsUseCase(this._tapRepo);

  @override
  Future<Result<List<Tap>>> execute(DateTime date, User user) async {
    List<Tap>? taps = await _tapRepo.findAllByDateAndID(user, date);
    if (taps == null) return Result.error("Taps is null");
    return Result.value(taps);
  }
}
