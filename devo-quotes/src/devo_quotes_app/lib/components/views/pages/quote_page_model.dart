import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:devo_quotes_app/components/views/quote/community_quote_view.dart';
import 'package:devo_quotes_app/components/views/quote/personal_quote_view.dart';
import 'package:devo_quotes_app/components/views/quote/quote_view.dart';
import 'package:devo_quotes_app/models/backend/firebase/quote_repository.dart';
import 'package:devo_quotes_package/quote.dart';

///
/// quote_page_model.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/6/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

final FirebaseFirestore _firestore = FirebaseFirestore.instance;

mixin QuotePageModel<T> {
  final QuoteRepo quoteRepo = QuoteRepository();

  Future<List<T>> getQuotes();

  QuoteView quoteView(T quote);

  Stream<List<T>> getStream();
}

class CommunityQuotePageModel implements QuotePageModel<CommunityQuote> {
  @override
  Future<List<CommunityQuote>> getQuotes() async {
    DefaultGetCommunityQuotesUseCase useCase =
        DefaultGetCommunityQuotesUseCase(quoteRepo);
    Result<List<CommunityQuote>?> result = await useCase.execute();
    if (result.isError) {
      print(
          "There was an Error Getting Community Quotes: ${result.asError!.error}");
      return [];
    } else if (result.isValue && result.asValue != null) {
      List<CommunityQuote>? list = result.asValue!.value;
      if (list == null) return [];
      return result.asValue!.value!;
    }
    return [];
  }

  @override
  QuoteView quoteView(CommunityQuote quote) => CommunityQuoteView(quote);

  @override
  QuoteRepo get quoteRepo => QuoteRepository();

  @override
  Stream<List<CommunityQuote>> getStream() {
    // TODO: implement getStream
    throw UnimplementedError();
  }
}

class PersonalQuotePageModel implements QuotePageModel<PersonalQuote> {
  final User user;

  PersonalQuotePageModel(this.user);

  @override
  Future<List<PersonalQuote>> getQuotes() async {
    DefaultGetPersonalQuotesUseCase useCase =
        DefaultGetPersonalQuotesUseCase(quoteRepo);
    Result<List<PersonalQuote>?> result = await useCase.execute(user);
    if (result.isError) {
      print(
          "There was an Error Getting Personal Quotes: ${result.asError!.error}");
      return [];
    } else if (result.isValue && result.asValue != null) {
      List<PersonalQuote>? list = result.asValue!.value;
      if (list == null) return [];
      return result.asValue!.value!;
    }
    return [];
  }

  @override
  QuoteView quoteView(PersonalQuote quote) => PersonalQuoteView(quote);

  @override
  QuoteRepo get quoteRepo => QuoteRepository();

  @override
  Stream<List<PersonalQuote>> getStream() async* {
    throw UnimplementedError();
    // _firestore.collection("personal").withConverter(
    //     fromFirestore: (snapshots, _) =>
    //         PersonalQuote.decode(snapshots.data()!),
    //     toFirestore: (quote, _) => quote.toJson());
  }
}
