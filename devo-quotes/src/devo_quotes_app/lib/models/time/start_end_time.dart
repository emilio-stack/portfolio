import 'my_time.dart';

///
/// start_end_time.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/5/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

abstract class StartEndTime {
  final MyTime start;
  final MyTime end;

  const StartEndTime(this.start, this.end);
}
