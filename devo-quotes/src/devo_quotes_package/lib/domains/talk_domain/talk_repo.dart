import 'talk.dart';

///
/// talk_repo.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/4/21
/// Copyright 2021 Porter McGary.  All rights reserved.
///

mixin TalkRepo {
  Future<Talk?> find(String url);
}
