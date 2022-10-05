import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:devo_quotes_package/user.dart';
import 'package:shared_preferences/shared_preferences.dart';

///
/// user_repository.dart
/// devo-quotes
///
/// Created by Po on 10/4/21
/// Copyright 2021 Po. All rights reserved.
///

class UserRepository implements UserRepo {
  final FirebaseFirestore _firestore = FirebaseFirestore.instance;
  final String _key = "id";
  final Future<SharedPreferences> _pref = SharedPreferences.getInstance();

  @override
  Future<String?> find() async {
    SharedPreferences prefs = await _pref;
    return prefs.getString(_key);
  }

  @override
  Future<String?> getNewID() async {
    DocumentSnapshot<Map<String, dynamic>> counters =
        await _firestore.collection("util").doc("counters").get();
    if (counters.exists) {
      int nextID = counters.get("user");
      _firestore.collection("util").doc("counters").set({"user": nextID + 1});
      return nextID.toString();
    }
  }

  @override
  Future<bool> store(User user) async {
    SharedPreferences prefs = await _pref;
    return prefs.setString(_key, user.id);
  }
}
