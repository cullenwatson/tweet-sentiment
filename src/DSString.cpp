#include "DSString.h"

DSString::DSString() {
    str = NULL;
}
DSString::DSString(const char* s) {
    str = new char[strlen(s) + 1];
    strcpy(str, s);
}
DSString::DSString(const DSString& s) {
    str = new char[strlen(s.str) + 1];
    strcpy(str, s.str);
}
DSString::~DSString() {
    delete[]str;
    str = NULL;
}

DSString& DSString::operator= (const char* s) {
    str = new char[strlen(s) + 1];
    strcpy(str, s);
    return *this;
}
DSString& DSString::operator= (const DSString& s) {
    str = new char[strlen(s.str) + 1];
    strcpy(str, s.str);
    return *this;
}
bool DSString::operator< (const DSString& s) const{
    return strcmp(str, s.str) < 0;
}
bool DSString::operator< (const char* s) const{
    return strcmp(str, s) < 0;
}
bool DSString::operator> (const DSString& s) const{
    return strcmp(str, s.str) > 0;
}
bool DSString::operator> (const char* s) const{
    return strcmp(str, s) > 0;
}
bool DSString::operator== (const char* s) const {
    return strcmp(str, s) == 0;
}
bool DSString::operator== (const DSString& s) const{
    return strcmp(str, s.str) == 0;
}
DSString DSString::operator+ (const DSString& s) {
    DSString temp;
    temp.str = new char[strlen(str) + strlen(s.str) + 1];

    strcpy(temp.str, str);
    strcat(temp.str, s.str);

    return temp;
}
char& DSString::operator[] (const int i) {
    // return first char if index is out of bounds
    if (i > strlen(str))
        return str[0];

    return str[i];
}
int DSString::getLength() {
    return strlen(str);
}
DSString DSString::substring(int start, int numChars) {
    DSString temp;
    // return object invoker if index is out of bounds
    if (start > strlen(str) + 1)
        return *this;

    temp.str = new char[numChars + 1];

    for (int i = 0; i < numChars; i++)
        temp.str[i] = str[start + i];

    temp.str[numChars] = '\0';
    return temp;
}
char* DSString::c_str() {
    char* s = str;
    return s;
}
std::ostream& operator<< (std::ostream& os, const DSString& s) {
    os << s.str;
    return os;
}