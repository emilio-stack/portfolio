import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:devo_quotes_package/quote.dart';

///
/// quote_repository.dart
/// devo-quotes
///
/// Created by Po on 10/4/21
/// Copyright 2021 Po. All rights reserved.
///

class QuoteRepository implements QuoteRepo {
  FirebaseFirestore _firestore = FirebaseFirestore.instance;

  @override
  Future<List<CommunityQuote>?> findAll() async {
    QuerySnapshot<Map<String, dynamic>> communityTable =
        await _firestore.collection("community").get();
    List<QueryDocumentSnapshot<Map<String, dynamic>>> communityRows =
        communityTable.docs;

    List<CommunityQuote> quotes = [];
    for (QueryDocumentSnapshot<Map<String, dynamic>> row in communityRows) {
      if (row.exists) {
        Map<String, dynamic> map = row.data();
        TalkDetails details = TalkDetails(
            author: map["author"],
            title: map["title"],
            image: map["image"],
            dateGiven: map["date_given"]?.toDate());
        CommunityQuote quote = CommunityQuote(
            content: map["content"], taps: map["taps"], talkDetails: details);
        quotes.add(quote);
      }
    }

    if (quotes.isEmpty) return null;
    return quotes;
  }

  @override
  Future<List<PersonalQuote>?> findAllByID(User user) async {
    QuerySnapshot<Map<String, dynamic>> communityTable =
        await _firestore.collection("personal").get();
    List<QueryDocumentSnapshot<Map<String, dynamic>>> communityRows =
        communityTable.docs;

    List<PersonalQuote> quotes = [];
    for (QueryDocumentSnapshot<Map<String, dynamic>> row in communityRows) {
      if (row.exists && row.get("user_id") == user.id) {
        Map<String, dynamic> map = row.data();
        TalkDetails details = TalkDetails(
            author: map["author"],
            title: map["title"],
            image: map["image"],
            dateGiven: map["date_given"]?.toDate());
        PersonalQuote quote = PersonalQuote(
            content: map["content"],
            user: User(map["user_id"]),
            talkDetails: details);
        quotes.add(quote);
      }
    }

    if (quotes.isEmpty) return null;
    return quotes;
  }

  @override
  Future<Result<bool>> store(Quote quote, {User? user, int? taps}) {
    throw UnimplementedError("Not needed at the moment");
  }
}
