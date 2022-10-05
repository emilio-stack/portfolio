import 'package:devo_quotes_app/notifications/notification_api.dart';

///
/// devotional_ended_notification.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/8/21
/// Copyright 2021 Porter McGary. All rights reserved.
///
class DevotionalEndedNotification extends NotificationAPI {
  DevotionalEndedNotification()
      : super("Thanks!", "Devotional has ended. Thank you for watching!");
}
