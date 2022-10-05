import 'package:devo_quotes_package/shared/ddd.dart';
import 'package:flutter/cupertino.dart';

///
/// transcript.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/4/21
/// Copyright 2021 Porter McGary.  All rights reserved.
///

/// MUST HAVE
/// - Start Time
/// - End Time
/// - Content
class Transcript extends ValueObject<Transcript> {
  late final String _content;
  final DateTime start;
  final DateTime end;

  Transcript({required String content, required this.start, required this.end})
      : super.decode({"content": content, "start": start, "end": end}) {
    __content = content;
  }

  set __content(String content) {
    if (content.isEmpty) throw ErrorDescription("Empty String");
    _content = content;
  }

  String get content => _content;

  @override
  bool sameValueAs(Transcript other) {
    return this.content == other.content &&
        this.start == other.start &&
        this.end == other.end;
  }

  @override
  bool operator ==(Object other) {
    if (other.runtimeType == Transcript)
      return sameValueAs(other as Transcript);
    return false;
  }

  @override
  Map<String, dynamic> toJson() =>
      {"content": content, "start": start, "end": end};
}
