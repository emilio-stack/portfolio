import 'package:flutter/foundation.dart';

///
/// entity.dart
/// bishopric-assistant
///
/// Created by Porter McGary on 9/17/21
/// Copyright 2021 Porter McGary.  All rights reserved.
///

/// An [Entity], as explained in the DDD book.
abstract class Entity<T> {
  /// Entities compare by identity, not by attributes.
  ///
  /// The [other] entity.
  /// Returns `true` if the identities are the same, regardless of other attributes.
  @required
  bool sameIdentityAs(T other);

  @required
  bool operator ==(Object other);
}
