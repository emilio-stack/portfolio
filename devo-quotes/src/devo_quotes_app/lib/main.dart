import 'package:devo_quotes_app/notifications/devotional_notification.dart';
import 'package:devo_quotes_app/notifications/devotional_starting_notification.dart';
import 'package:devo_quotes_package/user.dart';
import 'package:flutter/material.dart';
import 'package:flutter_local_notifications/flutter_local_notifications.dart';
import 'package:flutter_native_timezone/flutter_native_timezone.dart';
import 'package:timezone/data/latest.dart' as tz;
import 'package:timezone/timezone.dart';

import 'components/views/devotional_widget.dart';
import 'init_app.dart';

FlutterLocalNotificationsPlugin flutterLocalNotificationsPlugin =
    FlutterLocalNotificationsPlugin();

void main() async {
  WidgetsFlutterBinding.ensureInitialized();

  // Android notifications init
  const AndroidInitializationSettings initializationSettingsAndroid =
      AndroidInitializationSettings('launch_background');

  // iOS notifications init
  final IOSInitializationSettings initializationSettingsIOS =
      IOSInitializationSettings(
          onDidReceiveLocalNotification: _onDidReceiveLocalNotification);
  final InitializationSettings initializationSettings = InitializationSettings(
      android: initializationSettingsAndroid, iOS: initializationSettingsIOS);
  await flutterLocalNotificationsPlugin.initialize(initializationSettings,
      onSelectNotification: _selectNotification);

  tz.initializeTimeZones();
  final String currentTimeZone = await FlutterNativeTimezone.getLocalTimezone();
  setLocalLocation(getLocation(currentTimeZone));

  _initializeNotifications();

  runApp(InitApp());
}

void _onDidReceiveLocalNotification(
    int id, String? title, String? body, String? payload) async {}

void _selectNotification(String? payload) async {
  if (payload != null) print('notification payload: $payload');
  // uncomment when using deep-dive links
  // if (payload == "devotional")
  //   Navigator.push(, MaterialPageRoute<void>(builder: (context) => ()))
}

// TODO: Implement
void _selectNotificationWithContext(
    BuildContext context, String? payload) async {
  if (payload != null) print('notification payload: $payload');
  // uncomment when using deep-dive links
  if (payload == "devotional")
    Navigator.push(
        context,
        MaterialPageRoute<void>(
            builder: (context) => DevotionalWidget(User("Dead"))));
}

void _initializeNotifications() {
  // Devotional Reminder
  DevotionalNotification devotionalNotification = DevotionalNotification();
  DateTime tuesday = DateTime(2021, 10, 5, 11, 15, 0);
  TZDateTime scheduledTime = TZDateTime.from(tuesday, local);
  devotionalNotification.repeat(
      scheduledTime, DateTimeComponents.dayOfWeekAndTime);

  // Devotional is starting Reminder
  DevotionalStartingNotification devotionalStartingNotification =
      DevotionalStartingNotification();
  tuesday = DateTime(2021, 10, 5, 11, 30, 0);
  scheduledTime = TZDateTime.from(tuesday, local);
  devotionalStartingNotification.repeat(
      scheduledTime, DateTimeComponents.dayOfWeekAndTime);
}
