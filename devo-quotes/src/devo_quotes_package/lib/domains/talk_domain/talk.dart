import 'package:devo_quotes_package/domains/talk_domain/transcript.dart';
import 'package:devo_quotes_package/shared/ddd.dart';
import 'package:devo_quotes_package/shared/talk_details.dart';
import 'package:flutter/foundation.dart';

///
/// talk.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/4/21
/// Copyright 2021 Porter McGary.  All rights reserved.
///

/// MUST HAVE
/// - Transcript
/// - Author
/// - Date Given
/// - Image
class Talk extends Entity<Talk> {
  final TalkDetails talk;
  late final List<Transcript> _transcripts;

  Talk({required this.talk, required List<Transcript> transcripts}) {
    __transcripts = transcripts;
  }

  set __transcripts(List<Transcript> list) {
    if (list.isEmpty) throw ErrorDescription("Empty List");
    _transcripts = list;
  }

  List<Transcript> get transcripts => _transcripts;

  @override
  bool sameIdentityAs(Talk other) {
    return other.talk == this.talk && other.transcripts == this.transcripts;
  }

  @override
  bool operator ==(Object other) {
    if (other.runtimeType == Talk) return sameIdentityAs(other as Talk);
    return false;
  }
}
