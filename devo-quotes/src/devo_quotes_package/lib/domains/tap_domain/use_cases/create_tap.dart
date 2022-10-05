import 'package:devo_quotes_package/domains/tap_domain/tap_repo.dart';
import 'package:devo_quotes_package/tap.dart';
import 'package:flutter/foundation.dart';
import 'package:async/async.dart';

///
/// create_tap.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/4/21
/// Copyright 2021 Porter McGary.  All rights reserved.
///

mixin CreateTapUseCase {
  @required
  Future<Result<bool>> execute(Tap tap);
}

class DefaultCreateTapUseCase implements CreateTapUseCase {
  TapRepo _tapRepo;

  DefaultCreateTapUseCase(this._tapRepo);

  @override
  Future<Result<bool>> execute(Tap tap) async {
    return _tapRepo.store(tap);
  }
}
