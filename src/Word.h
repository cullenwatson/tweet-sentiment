#ifndef PA01_SENTIMENT_WORD_H
#define PA01_SENTIMENT_WORD_H


#include"DSString.h"
using namespace std;

// word class that stores string of word and number of occurrences
class Word {
public:
    int quantity;
    DSString word;

    Word(const char*);
    bool operator==(const Word& obj2) const;
};


#endif //PA01_SENTIMENT_WORD_H
