import 'package:devo_quotes_app/models/theme/colors.dart';
import 'package:flutter/cupertino.dart';

///
/// tab_bar.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/5/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

class MyTabBar extends StatelessWidget {
  final List<Widget> children;

  const MyTabBar(this.children, {Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return CupertinoTabScaffold(
        backgroundColor: CupertinoColors.white,
        tabBar: CupertinoTabBar(backgroundColor: CupertinoColors.white, items: <
            BottomNavigationBarItem>[
          BottomNavigationBarItem(
              icon: Icon(
                CupertinoIcons.person,
                color: byuIGrey,
              ),
              activeIcon: Icon(CupertinoIcons.person_fill, color: byuIBlue)),
          BottomNavigationBarItem(
              icon: Icon(
                CupertinoIcons.person_2,
                color: byuIGrey,
              ),
              activeIcon: Icon(CupertinoIcons.person_2_fill, color: byuIBlue))
        ]),
        tabBuilder: (BuildContext context, int index) => children[index]);
  }
}
