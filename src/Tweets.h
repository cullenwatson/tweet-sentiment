#ifndef PA01_SENTIMENT_TWEETS_H
#define PA01_SENTIMENT_TWEETS_H


#include"DSString.h"
using namespace std;

class Tweets {
public:
    DSString Id;
    int Sentiment;
    Tweets(DSString id, int sentiment);
};


#endif //PA01_SENTIMENT_TWEETS_H
