import 'package:devo_quotes_app/components/error_displays/error_404.dart';
import 'package:devo_quotes_app/components/loading_indicators/loading_indicator.dart';
import 'package:devo_quotes_app/components/views/base/base_page_view.dart';
import 'package:devo_quotes_app/components/views/pages/quote_page_model.dart';
import 'package:devo_quotes_app/components/views/quote/quotes_pending.dart';
import 'package:devo_quotes_app/models/theme/colors.dart';
import 'package:devo_quotes_app/models/theme/fonts.dart';
import 'package:devo_quotes_app/notifications/QuotesProcessedNotification.dart';
import 'package:flutter/cupertino.dart';
import 'package:flutter/foundation.dart';
import 'package:flutter/material.dart';
import 'package:timezone/timezone.dart';

///
/// quote_page.dart
/// devo-quotes
///
/// Created by Porter McGary on 10/6/21
/// Copyright 2021 Porter McGary. All rights reserved.
///

class QuotePage<Q> extends StatelessWidget {
  final QuotePageModel<Q> pageModel;
  final bool quotesArePending;

  const QuotePage(this.pageModel, {required this.quotesArePending, Key? key})
      : super(key: key);

  @override
  Widget build(BuildContext context) {
    // return BasePage(child: StreamBuilder(stream: pageModel.getStream(), builder: (context, snapshot) {
    // TODO: Implement
    // }));
    return BasePage(
        background: byuILightGrey,
        child: FutureBuilder(
            future: pageModel.getQuotes(),
            builder: (context, AsyncSnapshot<List<Q>> snapshot) {
              if (snapshot.hasError)
                return Error404(msg: snapshot.error.toString());
              if (snapshot.hasData) {
                final List<Q>? quotes = snapshot.data;
                if (quotes == null || quotes.isEmpty) {
                  String msg = "No Personal Quotes! 😲";
                  if (pageModel.runtimeType == PersonalQuotePageModel &&
                      kDebugMode)
                    msg += "\n${(pageModel as PersonalQuotePageModel).user.id}";
                  return Padding(
                    padding: const EdgeInsets.all(8.0),
                    child: Text(
                      msg,
                      style: darkText,
                      textAlign: TextAlign.center,
                    ),
                  );
                }
                return Scrollbar(
                  child: ListView.builder(
                    itemCount: quotes.length,
                    itemBuilder: (context, int index) {
                      if (index == 0) {
                        return _firstEntry(pageModel.quoteView(quotes[index]));
                      }
                      if (index == quotes.length - 1)
                        return Padding(
                          padding: const EdgeInsets.only(bottom: 70.0),
                          child: pageModel.quoteView(quotes[index]),
                        );
                      return pageModel.quoteView(quotes[index]);
                    },
                  ),
                );
              }
              return LoadingIndicator(background: byuILightGrey);
            }));
  }

  Widget _firstEntry(Widget quote) {
    Widget child = quote;

    if (quotesArePending)
      child = Column(children: [
        GestureDetector(
            child: QuotesPending(), onDoubleTap: _notifyQuotesUpdated),
        quote
      ]);

    return Padding(padding: const EdgeInsets.only(top: 16.0), child: child);
  }

  void _notifyQuotesUpdated() {
    if (kDebugMode) {
      QuotesProcessedNotification processedNotification =
          QuotesProcessedNotification("Brother McGary");
      TZDateTime scheduledTime =
          TZDateTime.from(DateTime.now().add(Duration(seconds: 10)), local);
      processedNotification.schedule(scheduledTime);
    }
  }
}
