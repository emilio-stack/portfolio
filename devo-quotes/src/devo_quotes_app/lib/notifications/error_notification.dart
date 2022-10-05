import 'package:devo_quotes_app/notifications/notification_api.dart';

///
/// error_notification.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/8/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

class ErrorNotification extends NotificationAPI {
  ErrorNotification(String msg) : super("ERROR!", msg);
}
