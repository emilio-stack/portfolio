import 'package:flutter/cupertino.dart';

///
/// my_time.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/5/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

class MyTime {
  late final int _hour;
  late final int _minute;
  late final int _second;
  late final int _day;

  final ErrorDescription negative = ErrorDescription("Negative Integer");

  MyTime(int hour, int minute, int second, int day) {
    __hour = hour;
    __minute = minute;
    __second = second;
    __day = day;
  }

  MyTime.dateTime(DateTime time) {
    __day = time.weekday;
    __hour = time.hour;
    __minute = time.minute;
    __second = time.second;
  }

  set __hour(int num) {
    if (num < 0) throw negative;
    _hour = num;
  }

  set __minute(int num) {
    if (num < 0) throw negative;
    _minute = num;
  }

  set __second(int num) {
    if (num < 0) throw negative;
    _second = num;
  }

  set __day(int num) {
    if (num < 0) throw negative;
    _day = num;
  }

  int get hour => _hour;
  int get minute => _minute;
  int get second => _second;
  int get day => _day;

  @override
  String toString() {
    return "Day = $day Time = $hour:$minute:$second";
  }

  @override
  bool operator ==(Object object) {
    if (object.runtimeType != MyTime) return false;
    MyTime other = object as MyTime;
    return this.hour == other.hour &&
        this.minute == other.minute &&
        this.second == other.second &&
        this.day == other.day;
  }

  operator <=(Object object) {
    if (object.runtimeType != MyTime) return false;
    MyTime other = object as MyTime;

    if (this.day > other.day) return false;

    if (this.hour > other.hour && this.day >= other.day) return false;

    if (this.minute > other.minute &&
        this.hour >= other.hour &&
        this.day >= other.day) return false;

    if (this.second > other.second &&
        this.minute >= other.minute &&
        this.hour >= other.hour &&
        this.day >= other.day) return false;

    return true;
  }

  operator >=(Object object) {
    if (object.runtimeType != MyTime) return false;
    MyTime other = object as MyTime;

    if (this.day < other.day) return false;

    if (this.hour < other.hour && this.day <= other.day) return false;

    if (this.minute < other.minute &&
        this.hour <= other.hour &&
        this.day <= other.day) return false;

    if (this.second < other.second &&
        this.minute <= other.minute &&
        this.hour <= other.hour &&
        this.day <= other.day) return false;

    return true;
  }

  operator >(Object object) {
    if (object.runtimeType != MyTime) return false;
    MyTime other = object as MyTime;

    if (this == other) return false;

    return this >= other;
  }

  operator <(Object object) {
    if (object.runtimeType != MyTime) return false;
    MyTime other = object as MyTime;

    if (this == other) return false;

    return this <= other;
  }
}
