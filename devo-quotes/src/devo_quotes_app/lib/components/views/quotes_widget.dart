import 'package:devo_quotes_app/components/navigation/tab_bar.dart';
import 'package:devo_quotes_app/components/views/pages/community_page.dart';
import 'package:devo_quotes_app/components/views/pages/personal_page.dart';
import 'package:devo_quotes_package/quote.dart';
import 'package:flutter/cupertino.dart';

///
/// quotes_widget.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/5/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

class QuotesWidget extends StatelessWidget {
  final User user;
  final bool quotesArePending;

  QuotesWidget(this.user, {this.quotesArePending = false, Key? key})
      : super(key: key);

  @override
  Widget build(BuildContext context) {
    return MyTabBar([
      PersonalPage(
        user,
        quotesArePending: quotesArePending,
      ),
      CommunityPage(quotesArePending: quotesArePending)
    ]);
  }
}
