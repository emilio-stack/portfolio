import 'package:devo_quotes_package/shared/talk_details.dart';
import 'package:devo_quotes_package/talk.dart';
import 'package:flutter/foundation.dart';

import 'quote.dart';

///
/// community_quote.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/4/21
/// Copyright 2021 Porter McGary.  All rights reserved.
///

class CommunityQuote extends Quote<CommunityQuote> {
  late final int _taps;

  CommunityQuote(
      {required int taps,
      required String content,
      required TalkDetails talkDetails})
      : super(content, talkDetails) {
    __taps = taps;
  }

  CommunityQuote.decode(Map<String, dynamic> map)
      : super(
            map["content"],
            TalkDetails(
                author: map["author"],
                title: map["title"],
                image: map["image"],
                dateGiven: map["date_given"])) {
    __taps = map["taps"];
  }

  set __taps(int taps) {
    if (taps < 0) throw ErrorDescription("Invalid number of taps");
    _taps = taps;
  }

  int get taps => _taps;

  @override
  bool sameIdentityAs(CommunityQuote other) {
    return this.talkDetails == other.talkDetails &&
        this.content == other.content &&
        this.taps == other.taps;
  }

  @override
  bool operator ==(Object other) {
    if (other.runtimeType == CommunityQuote)
      return sameIdentityAs(other as CommunityQuote);
    return false;
  }
}
