import 'package:devo_quotes_app/components/error_displays/error_404.dart';
import 'package:devo_quotes_app/components/loading_indicators/loading_indicator.dart';
import 'package:devo_quotes_app/components/views/base/base_page_view.dart';
import 'package:firebase_core/firebase_core.dart';
import 'package:flutter/cupertino.dart';

///
/// firebase.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/5/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

class FirebaseWidget extends StatelessWidget {
  final Future<FirebaseApp> _fbApp = Firebase.initializeApp();
  final Widget child;

  FirebaseWidget(this.child, {Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return CupertinoApp(
      home: FutureBuilder(
          future: _fbApp,
          builder: (context, snapshot) {
            if (snapshot.hasError) {
              return BasePage(child: Error404(msg: snapshot.error.toString()));
            } else if (snapshot.hasData) {
              return child;
            }
            return BasePage(child: LoadingIndicator());
          }),
    );
  }
}
