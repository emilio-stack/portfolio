import 'package:devo_quotes_app/models/time/my_time.dart';
import 'package:flutter_test/flutter_test.dart';

///
/// my_time_test.dart
///
///
/// Created by Porter McGary on 10/5/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

class MyTimeTest {
  static void equivalent() {
    MyTime time = MyTime(11, 30, 0, 2);
    bool result = time == time;
    expect(result, true);
  }

  static void lessThan() {
    // [hour, minute, sec, day]
    MyTime earlier = MyTime(11, 30, 1, 2);

    expect(earlier < MyTime(13, 0, 0, 2), true);
    expect(earlier < MyTime(11, 30, 2, 2), true);
    expect(earlier < MyTime(11, 30, 1, 3), true);
    expect(earlier < MyTime(11, 31, 1, 2), true);
    expect(earlier < MyTime(10, 30, 1, 2), false);
    expect(earlier < MyTime(11, 29, 1, 2), false);
    expect(earlier < MyTime(11, 30, 0, 2), false);
    expect(earlier < MyTime(11, 30, 1, 1), false);
    expect(earlier < earlier, false);
  }

  static void greaterThan() {
    // [hour, minute, sec, day]
    MyTime earlier = MyTime(11, 30, 1, 2);

    expect(earlier > MyTime(10, 30, 1, 2), true);
    expect(earlier > MyTime(11, 29, 1, 2), true);
    expect(earlier > MyTime(11, 30, 0, 2), true);
    expect(earlier > MyTime(11, 30, 1, 1), true);
    expect(earlier > MyTime(13, 0, 0, 2), false);
    expect(earlier > MyTime(11, 30, 2, 2), false);
    expect(earlier > MyTime(11, 30, 1, 3), false);
    expect(earlier > MyTime(11, 31, 1, 2), false);
    expect(earlier > earlier, false);
  }

  static void lessOrEqualThan() {
    // [hour, minute, sec, day]
    MyTime earlier = MyTime(11, 30, 1, 2);

    expect(earlier <= MyTime(13, 0, 0, 2), true);
    expect(earlier <= MyTime(11, 30, 2, 2), true);
    expect(earlier <= MyTime(11, 30, 1, 3), true);
    expect(earlier <= MyTime(11, 31, 1, 2), true);
    expect(earlier <= MyTime(10, 30, 1, 2), false);
    expect(earlier <= MyTime(11, 29, 1, 2), false);
    expect(earlier <= MyTime(11, 30, 0, 2), false);
    expect(earlier <= MyTime(11, 30, 1, 1), false);
    expect(earlier <= earlier, true);
  }

  static void greaterOrEqualThan() {
    // [hour, minute, sec, day]
    MyTime earlier = MyTime(11, 30, 1, 2);

    expect(earlier >= MyTime(10, 30, 1, 2), true);
    expect(earlier >= MyTime(11, 29, 1, 2), true);
    expect(earlier >= MyTime(11, 30, 0, 2), true);
    expect(earlier >= MyTime(11, 30, 1, 1), true);
    expect(earlier >= MyTime(13, 0, 0, 2), false);
    expect(earlier >= MyTime(11, 30, 2, 2), false);
    expect(earlier >= MyTime(11, 30, 1, 3), false);
    expect(earlier >= MyTime(11, 31, 1, 2), false);
    expect(earlier >= earlier, true);
  }

  static void checkForNegatives() {
    throw UnimplementedError();
  }

  static void checkCorrectTimeCreated() {
    int dayOfTheWeek = 2;
    int hour = 11;
    int min = 30;
    int sec = 25;
    DateTime time = DateTime(2021, 10, 5, 11, 30, 25);
    MyTime actual = MyTime.dateTime(time);
    expect(actual.day, dayOfTheWeek);
    expect(actual.hour, hour);
    expect(actual.minute, min);
    expect(actual.second, sec);

    DateTime sunday = DateTime(2021, 10, 3);
    actual = MyTime.dateTime(sunday);
    expect(actual.day, 7);

    DateTime monday = DateTime(2021, 10, 4);
    actual = MyTime.dateTime(monday);
    expect(actual.day, 1);

    DateTime tuesday = DateTime(2021, 10, 5);
    actual = MyTime.dateTime(tuesday);
    expect(actual.day, 2);

    DateTime wednesday = DateTime(2021, 10, 6);
    actual = MyTime.dateTime(wednesday);
    expect(actual.day, 3);

    DateTime thursday = DateTime(2021, 10, 7);
    actual = MyTime.dateTime(thursday);
    expect(actual.day, 4);

    DateTime friday = DateTime(2021, 10, 8);
    actual = MyTime.dateTime(friday);
    expect(actual.day, 5);

    DateTime saturday = DateTime(2021, 10, 9);
    actual = MyTime.dateTime(saturday);
    expect(actual.day, 6);
  }
}

main() {
  group("My Time Tests", () {
    test("time == time", MyTimeTest.equivalent);
    test("time < time", MyTimeTest.lessThan);
    test("time > time", MyTimeTest.greaterThan);
    test("time <= time", MyTimeTest.lessOrEqualThan);
    test("time >= time", MyTimeTest.greaterOrEqualThan);
    test("Day of the Week, Hour, Minute, Second are stored correctly",
        MyTimeTest.checkCorrectTimeCreated);
    // test("no negative values", MyTimeTest.checkForNegatives);
  });
}
