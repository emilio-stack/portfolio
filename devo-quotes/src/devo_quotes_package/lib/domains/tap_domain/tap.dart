import 'package:devo_quotes_package/shared/ddd.dart';

import '../../user.dart';

///
/// tap.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/4/21
/// Copyright 2021 Porter McGary.  All rights reserved.
///

/// MUST HAVE
/// - Time Stamp between 11:30 and 12:30 on a Tuesday
/// - User
class Tap extends Entity<Tap> {
  final DateTime timeStamp;
  final User user;

  Tap({required this.user, required this.timeStamp});

  Map<String, dynamic> encode() =>
      {"time_stamp": timeStamp, "user_id": user.id};

  @override
  bool sameIdentityAs(Tap other) {
    return this.user == other.user && this.timeStamp == other.timeStamp;
  }

  @override
  bool operator ==(Object other) {
    if (other.runtimeType == Tap) return sameIdentityAs(other as Tap);
    return false;
  }
}
