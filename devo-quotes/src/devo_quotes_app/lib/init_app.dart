import 'package:devo_quotes_app/app.dart';
import 'package:devo_quotes_app/components/tools/firebase.dart';
import 'package:flutter/cupertino.dart';

///
/// init_app.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/5/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

class InitApp extends StatelessWidget {
  const InitApp({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return FirebaseWidget(CupertinoApp(
      title: "DevoQuotes",
      theme: CupertinoThemeData(),
      home: App(),
    ));
  }
}
