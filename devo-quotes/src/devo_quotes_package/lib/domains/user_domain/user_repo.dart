import 'package:devo_quotes_package/user.dart';

///
/// user_repo.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/4/21
/// Copyright 2021 Porter McGary.  All rights reserved.
///

mixin UserRepo {
  Future<String?> getNewID();
  Future<bool> store(User user);
  Future<String?> find();
}
