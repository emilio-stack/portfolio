import 'package:devo_quotes_package/domains/user_domain/user.dart';
import 'package:devo_quotes_package/shared/talk_details.dart';

import 'quote.dart';

///
/// personal_quote.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/4/21
/// Copyright 2021 Porter McGary.  All rights reserved.
///

class PersonalQuote extends Quote<PersonalQuote> {
  final User user;

  PersonalQuote(
      {required this.user,
      required String content,
      required TalkDetails talkDetails})
      : super(content, talkDetails);

  PersonalQuote.decode(Map<String, dynamic> map)
      : this.user = User(map["user"]),
        super(
            map["content"],
            TalkDetails(
                author: map["author"],
                title: map["title"],
                image: map["image"],
                dateGiven: map["date_given"]));

  @override
  bool sameIdentityAs(PersonalQuote other) {
    return this.talkDetails == other.talkDetails &&
        this.content == other.content &&
        this.user == other.user;
  }

  @override
  bool operator ==(Object other) {
    if (other.runtimeType == PersonalQuote)
      return sameIdentityAs(other as PersonalQuote);
    return false;
  }
}
