import 'package:devo_quotes_app/models/time/devotional_time.dart';
import 'package:flutter_test/flutter_test.dart';

///
/// devotional_time_test.dart
///
///
/// Created by Porter McGary on 10/5/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

class DevotionalTimeTest {
  static DateTime oneSecAfterDevo = DateTime(2021, 10, 5, 12, 30, 1);
  static DateTime oneMinAfterDevo = DateTime(2021, 10, 5, 12, 31, 0);
  static DateTime oneHourAfterDevo = DateTime(2021, 10, 5, 13, 30, 0);
  static DateTime oneDayAfterDevo = DateTime(2021, 10, 6, 11, 30, 0);
  static DateTime endOfDevo = DateTime(2021, 10, 5, 12, 30, 0);
  static DateTime duringDevo = DateTime(2021, 10, 5, 11, 35, 25);
  static DateTime startOfDevo = DateTime(2021, 10, 5, 11, 30, 0);
  static DateTime oneSecBeforeDevo = DateTime(2021, 10, 5, 11, 29, 59);
  static DateTime oneMinBeforeDevo = DateTime(2021, 10, 5, 11, 29, 0);
  static DateTime oneHourBeforeDevo = DateTime(2021, 10, 5, 10, 30, 0);
  static DateTime oneDayBeforeDevo = DateTime(2021, 10, 4, 11, 30, 0);
  static DevotionalTime devo = DevotionalTime();

  static void isDevotionalTime() {
    // DevotionalTime == DateTime
    expect(devo == startOfDevo, true);
    expect(devo == duringDevo, true);
    expect(devo == endOfDevo, true);
    // DateTime == DevotionalTime
    // expect(startOfDevo == devo, true);
    // expect(duringDevo == devo, true);
    // expect(endOfDevo == devo, true);
  }

  static void isNotDevotionalTime() {
    // DateTime == DevotionalTime
    // expect(oneDayBeforeDevo == devo, false);
    // expect(oneHourBeforeDevo == devo, false);
    // expect(oneMinBeforeDevo == devo, false);
    // expect(oneSecBeforeDevo == devo, false);
    // expect(oneSecAfterDevo == devo, false);
    // expect(oneMinAfterDevo == devo, false);
    // expect(oneHourAfterDevo == devo, false);
    // expect(oneDayAfterDevo == devo, false);
    // DevotionalTime == DateTime
    expect(devo == oneDayBeforeDevo, false);
    expect(devo == oneHourBeforeDevo, false);
    expect(devo == oneMinBeforeDevo, false);
    expect(devo == oneSecBeforeDevo, false);
    expect(devo == oneSecAfterDevo, false);
    expect(devo == oneMinAfterDevo, false);
    expect(devo == oneHourAfterDevo, false);
    expect(devo == oneDayAfterDevo, false);
  }
}

main() {
  group("Devotional Time Tests", () {
    test("Is during devotional time", DevotionalTimeTest.isDevotionalTime);
    test("Is NOT during devotional time",
        DevotionalTimeTest.isNotDevotionalTime);
  });
}
