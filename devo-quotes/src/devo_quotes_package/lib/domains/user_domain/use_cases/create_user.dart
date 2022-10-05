import 'package:async/async.dart';
import 'package:devo_quotes_package/user.dart';
import 'package:flutter/foundation.dart';

///
/// create_user.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/4/21
/// Copyright 2021 Porter McGary.  All rights reserved.
///

mixin CreateUserUseCase {
  @required
  Future<Result<User>> execute();
}

class DefaultCreateUserUseCase implements CreateUserUseCase {
  UserRepo _userRepo;

  DefaultCreateUserUseCase(this._userRepo);

  @override
  Future<Result<User>> execute() async {
    final String? id = await _userRepo.getNewID();
    if (id == null)
      return Result.error("Failed to get UserID from local storage");
    if (kDebugMode) {
      String debugID = "Debug User $id";
      return Result.value(User(debugID));
    }
    return Result.value(User(id));
  }
}
