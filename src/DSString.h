#ifndef PA01_SENTIMENT_DSSTRING_H
#define PA01_SENTIMENT_DSSTRING_H

#include <iostream>
#include <cstring>

class DSString
{
private:
    char* str;
public:
    // constructors
    DSString();
    DSString(const char*);
    DSString(const DSString&);
    ~DSString();

    // overloaded assignment operators
    DSString& operator= (const char*);
    DSString& operator= (const DSString&);

    // overloaded relational operators
    bool operator< (const DSString&) const;
    bool operator< (const char*) const;
    bool operator> (const DSString&) const;
    bool operator> (const char*) const;
    bool operator== (const char*) const;
    bool operator== (const DSString&) const;

    // string concat
    DSString operator+ (const DSString&);

    // access particular character
    char& operator[] (const int);

    int getLength();
    DSString substring(int start, int numChars);
    // returns null-terminated c-string holding contents of this object
    char* c_str();

    // print contents to output stream
    friend std::ostream& operator<< (std::ostream&, const DSString&);
};



#endif //PA01_SENTIMENT_DSSTRING_H
