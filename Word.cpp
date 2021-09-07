#include "Word.h"

Word::Word(const char*x) {
    word = x; quantity = 1;
}
bool Word::operator==(const Word& obj2) const {
    if (this->word == obj2.word)
        return true;
    else
        return false;
}
