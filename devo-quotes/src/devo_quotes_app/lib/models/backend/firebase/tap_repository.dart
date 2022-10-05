import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:devo_quotes_package/tap.dart';

///
/// tap_repository.dart
/// devo-quotes
///
/// Created by Po on 10/4/21
/// Copyright 2021 Po. All rights reserved.
///

class TapRepository implements TapRepo {
  FirebaseFirestore _firestore = FirebaseFirestore.instance;

  @override
  Future<List<Tap>?> findAllByDate(DateTime date) {
    // TODO: implement findAllByDate
    throw UnimplementedError("Not needed at the moment");
  }

  @override
  Future<List<Tap>?> findAllByDateAndID(User user, DateTime date) {
    // TODO: implement findAllByDateAndID
    throw UnimplementedError("Not needed at the moment");
  }

  @override
  Future<Result<bool>> store(Tap tap) async {
    if (tap.user.id == "N/A") return Result.error("User ID not assigned");
    try {
      String docID = _firestore.collection("taps").doc().id;
      Map<String, dynamic> map = tap.encode();
      map["time_stamp"] = Timestamp.fromDate(tap.timeStamp);
      _firestore.collection("taps").doc(docID).set(map);
      Tap? tapFromBeyond = await _find(docID);
      if (tapFromBeyond == null)
        return Result.error("Failed to store tap in Firebase");
      return Result.value(true);
    } catch (error) {
      print(error);
      return Result.error(error);
    }
  }

  Future<Tap?> _find(String docID) async {
    DocumentSnapshot<Map<String, dynamic>> snapshot =
        await _firestore.collection("taps").doc(docID).get();
    if (snapshot.data() == null) return null;
    Map<String, dynamic> map = snapshot.data()!;
    return Tap(
        timeStamp: map["time_stamp"]?.toDate(), user: User(map["user_id"]));
  }
}
