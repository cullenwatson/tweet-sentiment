//
// Created by pc on 9/7/21.
//

#ifndef PA01_SENTIMENT_FUNCTIONS_H
#define PA01_SENTIMENT_FUNCTIONS_H


#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include"Word.h"
#include "Tweets.h"
#include"DSString.h"
using namespace std;

// vector of positive and negative tweets after reading training file
extern vector<DSString>positiveTweets;
extern vector<DSString>negativeTweets;
//put tweets into positive and negative vector based on their sentiment
void readTrainFile(char[]);
void addTweet(DSString tweet, DSString sentiment);

// list of words to be filtered out of the tweets
extern vector<DSString>nonsentimentalWords;
// add words to positive and negative words list along with their occurrence
void addWords(vector<DSString>&, vector<Word>&);
void chopUpWord(DSString* word);
bool validWord(DSString word);
void removeChar(DSString* word, char c);
// words split into positive and negative from corresponding tweet list
extern vector<Word>positiveWords;
extern vector<Word>negativeWords;

// predict sentiment of tweet, either 4 for positive or 0 for negative
void readTestFile(char[]);
int predictTweet(char tweet[]);
void wordExists(int& sentimentScore, DSString& word);
// list of tweets after classifying sentiment
extern vector<Tweets>tweetSentimentResults;

// get actual sentiment and store in vector with id
void getActualSentiment(char[]);
extern vector<Tweets>tweetActualSentimentResults;

// compare results and output
void printResults(char[]);

#endif //PA01_SENTIMENT_FUNCTIONS_H
