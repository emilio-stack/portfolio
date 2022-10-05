import 'my_time.dart';
import 'start_end_time.dart';

export 'my_time.dart';

///
/// devotional_time.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/5/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

class DevotionalTime extends StartEndTime {
  DevotionalTime() : super(MyTime(11, 30, 0, 2), MyTime(12, 30, 0, 2));

  bool isDuringDevotional(DateTime other) {
    MyTime time = MyTime.dateTime(other);
    return (time >= start && time <= end);
  }

  bool sameAs(DevotionalTime time) {
    return time.start == this.start && time.end == this.end;
  }

  @override
  bool operator ==(Object other) {
    if (other.runtimeType == DateTime)
      return isDuringDevotional(other as DateTime);
    if (other.runtimeType == DevotionalTime)
      return sameAs(other as DevotionalTime);
    return false;
  }
}
