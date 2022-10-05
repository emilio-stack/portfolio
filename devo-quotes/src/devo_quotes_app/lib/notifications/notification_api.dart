import 'package:devo_quotes_app/main.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter_local_notifications/flutter_local_notifications.dart';
import 'package:timezone/timezone.dart';

///
/// notification_api.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/7/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

// TODO: Notifications id? should there be more than one?
abstract class NotificationAPI {
  static final AndroidNotificationDetails _androidPlatformChannelSpecifics =
      AndroidNotificationDetails('notification', 'notification',
          icon: 'taylor_building',
          largeIcon: DrawableResourceAndroidBitmap('taylor_building'));
  static final IOSNotificationDetails _iOSPlatformChannelSpecifics =
      IOSNotificationDetails(
          presentAlert: true, presentBadge: true, presentSound: true);

  final NotificationDetails _platformChannelSpecifics = NotificationDetails(
      android: _androidPlatformChannelSpecifics,
      iOS: _iOSPlatformChannelSpecifics);

  late final String _title;
  late final String _msg;
  int _notificationID = -1;

  NotificationAPI(String title, String msg) {
    __title = title;
    __msg = msg;
  }

  set __title(String str) {
    if (str.isEmpty) throw ErrorDescription("Empty Title in Notification");
    _title = str;
  }

  set __msg(String str) {
    if (str.isEmpty) throw ErrorDescription("Empty Message in Notification");
    _msg = str;
  }

  int get _nextID => _notificationID++;

  Future<void> schedule(TZDateTime scheduledTime) async {
    await flutterLocalNotificationsPlugin.zonedSchedule(
        _nextID, _title, _msg, scheduledTime, _platformChannelSpecifics,
        androidAllowWhileIdle: true,
        uiLocalNotificationDateInterpretation:
            UILocalNotificationDateInterpretation.absoluteTime);
  }

  Future<void> notify() async {
    await flutterLocalNotificationsPlugin.show(
        _nextID, _title, _msg, _platformChannelSpecifics);
  }

  Future<void> repeat(
      TZDateTime scheduledTime, DateTimeComponents repeatOn) async {
    await flutterLocalNotificationsPlugin.zonedSchedule(
        _nextID, _title, _msg, scheduledTime, _platformChannelSpecifics,
        androidAllowWhileIdle: true,
        matchDateTimeComponents: repeatOn,
        uiLocalNotificationDateInterpretation:
            UILocalNotificationDateInterpretation.absoluteTime);
  }
}
