import 'package:async/async.dart';
import 'package:devo_quotes_package/user.dart';
import 'package:flutter/foundation.dart';

import 'tap.dart';

///
/// tap_repo.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/4/21
/// Copyright 2021 Porter McGary.  All rights reserved.
///

mixin TapRepo {
  @required
  Future<Result<bool>> store(Tap tap);

  @required
  Future<List<Tap>?> findAllByDateAndID(User user, DateTime date);

  @required
  Future<List<Tap>?> findAllByDate(DateTime date);
}
