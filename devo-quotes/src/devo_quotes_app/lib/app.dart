import 'package:devo_quotes_app/components/loading_indicators/loading_indicator.dart';
import 'package:devo_quotes_app/components/views/base/base_page_view.dart';
import 'package:devo_quotes_app/components/views/devotional_widget.dart';
import 'package:devo_quotes_app/models/theme/colors.dart';
import 'package:devo_quotes_app/notifications/error_notification.dart';
import 'package:devo_quotes_package/domains/user_domain/use_cases/get_user.dart';
import 'package:devo_quotes_package/domains/user_domain/use_cases/save_user.dart';
import 'package:devo_quotes_package/user.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

import 'components/error_displays/error_404.dart';
import 'components/views/quotes_widget.dart';
import 'models/backend/firebase/user_repository.dart';
import 'models/time/devotional_time.dart';

///
/// app.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/5/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

class App extends StatefulWidget {
  const App({Key? key}) : super(key: key);

  @override
  _AppState createState() => _AppState();
}

class _AppState extends State<App> {
  DateTime time = DateTime.now();
  DevotionalTime devotionalTime = DevotionalTime();
  UserRepository userRepo = UserRepository();
  bool hasAssignedID = false;
  User user = User("N/A");

  @override
  Widget build(BuildContext context) {
    return FutureBuilder(
        future: _userID(),
        builder: (context, snapshot) {
          if (snapshot.hasError) {
            return BasePage(child: Error404(msg: snapshot.error.toString()));
          }
          if (snapshot.hasData) {
            if (devotionalTime.isDuringDevotional(time)) {
              return DevotionalWidget(user);
            }
            return QuotesWidget(user);
          }
          return BasePage(child: LoadingIndicator(background: byuILightGrey));
        });
  }

  Future<bool> _verifyAssignedID() async {
    print("Verifying User ID");
    UserRepository _userRepo = UserRepository();
    DefaultGetUserUseCase getUserUseCase = DefaultGetUserUseCase(_userRepo);
    Result<User> useCaseResult = await getUserUseCase.execute();
    if (useCaseResult.isError) {
      ErrorNotification error =
          ErrorNotification(useCaseResult.asError!.error.toString());
      error.notify();
      return false;
    }
    setState(() {
      user = useCaseResult.asValue!.value;
    });
    return true;
  }

  Future<bool> _userID() async {
    if (!hasAssignedID) {
      try {
        if (await _verifyAssignedID()) {
          hasAssignedID = true;
          print("User ID was already Created!");
          return true;
        } else {
          print("Failed to verify User ID");
          User user = await _generateID();
          bool finished = false;
          while (!finished) {
            finished = await _saveUser(user);
          }
          this.user = user;
        }
      } catch (error) {
        throw error;
      }
      return false;
    } else {
      print("User has ID ${user.id}");
    }

    return true;
  }

  Future<User> _generateID() async {
    print("Generating User ID");
    DefaultCreateUserUseCase userUseCase = DefaultCreateUserUseCase(userRepo);
    Result<User> result = await userUseCase.execute();
    if (result.isError) throw result.asError!.error;
    return result.asValue!.value;
  }

  Future<bool> _saveUser(User user) async {
    print("Saving User ID ${user.id}");
    DefaultSaveUserUseCase saveUserUseCase = DefaultSaveUserUseCase(userRepo);
    Result result = await saveUserUseCase.execute(user);
    if (result.isError) {
      ErrorNotification error =
          ErrorNotification(result.asError!.error.toString());
      error.notify();
      return false;
    }
    return true;
  }
}
