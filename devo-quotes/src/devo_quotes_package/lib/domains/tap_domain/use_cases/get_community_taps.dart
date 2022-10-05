import 'package:devo_quotes_package/tap.dart';
import 'package:flutter/foundation.dart';
import 'package:async/async.dart';

///
/// get_community_taps.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/4/21
/// Copyright 2021 Porter McGary.  All rights reserved.
///

mixin GetCommunityTapsUseCase {
  @required
  Future<Result<List<Tap>>> execute(DateTime date);
}

class DefaultGetCommunityTapsUseCase implements GetCommunityTapsUseCase {
  TapRepo _tapRepo;

  DefaultGetCommunityTapsUseCase(this._tapRepo);

  @override
  Future<Result<List<Tap>>> execute(DateTime date) async {
    List<Tap>? taps = await _tapRepo.findAllByDate(date);
    if (taps == null) return Result.error("Taps are null");
    return Result.value(taps);
  }
}
