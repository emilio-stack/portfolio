import 'package:devo_quotes_package/talk.dart';
import 'package:flutter/foundation.dart';
import 'package:async/async.dart';

///
/// get_talk.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/4/21
/// Copyright 2021 Porter McGary.  All rights reserved.
///

mixin GetTalkUseCase {
  @required
  Future<Result<Talk>> execute(String url);
}

class DefaultGetTalkUseCase implements GetTalkUseCase {
  TalkRepo _talkRepo;

  DefaultGetTalkUseCase(this._talkRepo);

  @override
  Future<Result<Talk>> execute(String url) async {
    Talk? talk = await _talkRepo.find(url);
    if (talk == null) return Result.error("Talk is Null");
    return Result.value(talk);
  }
}
