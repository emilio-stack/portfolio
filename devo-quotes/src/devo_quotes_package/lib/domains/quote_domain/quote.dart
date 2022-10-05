import 'package:devo_quotes_package/shared/ddd.dart';
import 'package:devo_quotes_package/shared/talk_details.dart';
import 'package:flutter/foundation.dart';

///
/// quote.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/4/21
/// Copyright 2021 Porter McGary.  All rights reserved.
///

/// MUST HAVES:
/// - Content
/// - Date Given
/// - Speaker
/// - Time of Quote
abstract class Quote<T> extends Entity<T> {
  late final String _content;
  final TalkDetails talkDetails;

  Quote(String context, this.talkDetails) {
    __context = context;
  }

  set __context(String context) {
    if (context.isEmpty) throw ErrorDescription("Empty String");
    _content = context;
  }

  String get content => _content;
}
