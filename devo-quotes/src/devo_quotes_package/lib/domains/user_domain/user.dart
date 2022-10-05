import 'package:devo_quotes_package/shared/ddd.dart';
import 'package:flutter/cupertino.dart';

///
/// user.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/4/21
/// Copyright 2021 Porter McGary.  All rights reserved.
///

/// MUST HAVE
/// - ID that is unique
class User extends Entity<User> {
  late final String _id;

  User(String id) {
    __id = id;
  }

  set __id(String id) {
    if (id.isEmpty) throw ErrorDescription("Empty String");
    _id = id;
  }
  String get id => _id;

  @override
  bool sameIdentityAs(User other) {
    return other.id == this.id;
  }

  @override
  bool operator ==(Object other) {
    if (other.runtimeType == User) return sameIdentityAs(other as User);
    return false;
  }
}
