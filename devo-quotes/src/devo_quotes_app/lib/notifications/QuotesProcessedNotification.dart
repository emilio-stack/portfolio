import 'package:devo_quotes_app/notifications/notification_api.dart';

///
/// QuotesProcessedNotification.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/8/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

class QuotesProcessedNotification extends NotificationAPI {
  QuotesProcessedNotification(String speaker)
      : super("New Quotes", "Checkout NEW quotes from $speaker");
}
