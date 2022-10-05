import 'package:devo_quotes_package/shared/ddd.dart';
import 'package:flutter/cupertino.dart';

///
/// talk_with_tap.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/4/21
/// Copyright 2021 Porter McGary.  All rights reserved.
///

class TalkWithTap extends ValueObject<TalkWithTap> {
  late final int _taps;
  late final String _content;

  TalkWithTap({required int taps, required String content})
      : super.decode({"taps": taps, "content": content}) {
    __taps = taps;
    __content = content;
  }

  TalkWithTap.decode(Map<String, dynamic> json) : super.decode(json);

  set __taps(int taps) {
    if (taps < 0) throw ErrorDescription("Negative number of taps");
    _taps = taps;
  }

  set __content(String content) {
    if (content.isEmpty) throw ErrorDescription("Empty talk with taps content");
    _content = content;
  }

  String get content => _content;

  int get taps => _taps;

  @override
  bool sameValueAs(TalkWithTap other) {
    return this.taps == other.taps && this.content == other.content;
  }

  @override
  bool operator ==(Object other) {
    if (other.runtimeType == TalkWithTap)
      return sameValueAs(other as TalkWithTap);
    return false;
  }

  @override
  Map<String, dynamic> toJson() => {"taps": taps, "content": content};
}
