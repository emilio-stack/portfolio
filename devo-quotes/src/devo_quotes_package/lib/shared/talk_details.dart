import 'package:devo_quotes_package/shared/ddd.dart';
import 'package:flutter/cupertino.dart';

///
/// talk_details.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/4/21
/// Copyright 2021 Porter McGary.  All rights reserved.
///

class TalkDetails extends ValueObject<TalkDetails> {
  late final String _author;
  late final String _title;
  late final String _image;
  late final DateTime dateGiven;

  TalkDetails(
      {required String author,
      required String title,
      required String image,
      required this.dateGiven})
      : super.decode({
          "author": author,
          "title": title,
          "image": image,
          "dateGiven": dateGiven
        }) {
    __author = author;
    __title = title;
    __image = image;
  }

  TalkDetails.decode(Map<String, dynamic> map) : super.decode({}) {
    throw ErrorDescription(map['date_given'].toString());
  }

  set __author(String author) {
    if (author.isEmpty) throw ErrorDescription("Empty Author String");
    _author = author;
  }

  set __title(String title) {
    if (title.isEmpty) throw ErrorDescription("Empty Title String");
    _title = title;
  }

  set __image(String image) {
    if (image.isEmpty) throw ErrorDescription("Empty Image String");
    _image = image;
  }

  String get author => _author;

  String get title => _title;

  String get image => _image;

  @override
  bool sameValueAs(TalkDetails other) {
    return other.dateGiven == this.dateGiven &&
        other.image == this.image &&
        other.title == this.title &&
        other.author == this.author;
  }

  @override
  bool operator ==(Object other) {
    if (other.runtimeType == TalkDetails)
      return sameValueAs(other as TalkDetails);
    return false;
  }

  @override
  Map<String, dynamic> toJson() => {
        "image": image,
        "title": title,
        "author": author,
        "dateGiven": dateGiven
      };
}
