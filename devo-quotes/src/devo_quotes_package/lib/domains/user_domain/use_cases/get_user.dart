import 'package:devo_quotes_package/user.dart';
import 'package:flutter/foundation.dart';
import 'package:async/async.dart';

///
/// get_user.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/4/21
/// Copyright 2021 Porter McGary.  All rights reserved.
///

mixin GetUserUseCase {
  @required
  Future<Result<User>> execute();
}

class DefaultGetUserUseCase implements GetUserUseCase {
  UserRepo _userRepo;
  DefaultGetUserUseCase(this._userRepo);

  @override
  Future<Result<User>> execute() async {
    String? userStr = await _userRepo.find();
    if (userStr == null) return Result.error("Failed to get User");
    User user = User(userStr);
    return Result.value(user);
  }
}
