import 'package:devo_quotes_app/models/theme/colors.dart';
import 'package:flutter/cupertino.dart';

///
/// loading_indicator.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/5/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

class LoadingIndicator extends StatelessWidget {
  final Color background;
  const LoadingIndicator({this.background = byuIWhite, Key? key})
      : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Container(
        color: background,
        child: CupertinoActivityIndicator(
          radius: 35,
        ));
  }
}
