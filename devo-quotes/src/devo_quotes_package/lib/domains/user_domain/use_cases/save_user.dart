import 'package:devo_quotes_package/user.dart';
import 'package:async/async.dart';
import 'package:flutter/foundation.dart';

///
/// save_user.dart
/// devo-quotes
///
/// Created by Po on 10/4/21
/// Copyright 2021 Po. All rights reserved.
///

mixin SaveUserUseCase {
  @required
  Future<Result<User>> execute(User user);
}

class DefaultSaveUserUseCase implements SaveUserUseCase {
  UserRepo _userRepo;
  DefaultSaveUserUseCase(this._userRepo);

  @override
  Future<Result<User>> execute(User user) async {
    if (await _userRepo.store(user)) return Result.value(user);
    return Result.error("Failed to store user");
  }
}