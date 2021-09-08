#include "Functions.h"

vector<DSString>positiveTweets;
vector<DSString>negativeTweets;
void readTrainFile(char fileToOpen[]) {
    //open file
    ifstream file(fileToOpen);
    char line[361], tweet[281];
    char sentiment[2];
    //extract just the tweets from file
    if (file.is_open()) {
        // remove header row
        file.getline(line, 361, '\n');
        int i = 0;
        while (file && i < 20000) {
            // read till first comma
            file.getline(sentiment, 361, ',');

            for (int i = 0; i < 4; i++)
                // parse till u get to last comma
                file.getline(tweet, 361, ',');

            // then read in the tweet after the last comma
            file.getline(tweet, 361, '\n');
            addTweet(tweet, sentiment);
            i++;
        }
        file.close();
    }
}
void addTweet(char tweet[], char sentiment[]) {
    if (strcmp(sentiment, "4") == 0)
        positiveTweets.push_back(tweet);

    else if (strcmp(sentiment, "0") == 0)
        negativeTweets.push_back(tweet);
}

vector<DSString>nonsentimentalWords{
        "we","I","a","you","and","are","as","for","the","with","but","except","or","idk","have","they","of","just",
        "him","her","to","at","how","them","its","been", "i", "there", "when","get","now","on","is","me"
};
vector<Word>positiveWords;
vector<Word>negativeWords;
void addWords(vector<DSString>& tweetsList, vector<Word>& wordsList) {
    // pointer to point to each individual word in tweet
    char* point;

    // loop through tweets
    for (int i = 0; unsigned(i) < tweetsList.size(); i++) {

        // pointer points to first word in tweet
        point = strtok(tweetsList[i].c_str(), " ");
        // loop through tweet
        while (point != NULL) {

            // remove punctuation from word
            chopUpWord(point);

            // check if word is in nonsentimental list or a user tag
            bool isValidWord = validWord(point);
            if (!isValidWord) {
                point = strtok(NULL, " ");
                continue;

            }
            if ((point != NULL) && (point[0] != '\0')) {
                // see if word exists in corresponding word list
                vector<Word>::iterator it = find(wordsList.begin(), wordsList.end(), Word(point));

                // if it does exist, increase quantity
                if (it != wordsList.end())
                    it->quantity++;
                    // if it doesnt exist, add to list
                else {
                    Word temp(point);
                    wordsList.push_back(temp);
                }
            }
            point = strtok(NULL, " ");

        }
    }
}
void chopUpWord(char word[]) {
    removeChar(word, ',');
    removeChar(word, '.');
    removeChar(word, '!');
    removeChar(word, '"');
    removeChar(word, '?');
    removeChar(word, '(');
    removeChar(word, ')');
}
bool validWord(DSString word) {
    // check if word has @ sign
    if (strchr(word.c_str(), '@'))
        return false;
        // check if word is in nonsentimental list
    else if (find(nonsentimentalWords.begin(), nonsentimentalWords.end(), word) != nonsentimentalWords.end())
        return false;
    else
        return true;
}
void removeChar(char word[], char c) {
    // check if word is empty
    if (word == NULL)
        return;
    // create pointer that points to start of word
    char* result = word;

    // looop through every character in word
    while (*word) {
        // store letter in pointer value only if it is not the letter we're trying to remove
        if (*word != c) {
            *result = *word;
            result++;
        }
        word++;
    }
    // add null character to end
    *result = '\0';
}

vector<Tweets>tweetSentimentResults;
void readTestFile(char testFile[]) {
    //open file
    int sentiment=0;

    ifstream file(testFile);
    char line[361], tweet[281], id[20];
    if (file.is_open()) {
        //remove header row in csv file
        file.getline(line, 361, '\n');

        int i = 0;
        // loop till end of file
        while (file && i < 10000) {
            // get id
            file.getline(id, 20, ',');

            // parse line to get just the tweet
            for (int i = 0; i < 3; i++)
                file.getline(tweet, 361, ',');
            file.getline(tweet, 361, '\n');


            sentiment = predictTweet(tweet);
            Tweets temp(id, sentiment);
            tweetSentimentResults.push_back(temp);
            i++;
        }
        file.close();
    }
}
int predictTweet(char tweet[]) {
    char* point;

    point = strtok(tweet, " ");
    int sentimentScore = 0;
    // check every word and increase occurrence
    while (point != NULL) {
        // check if word is valid
        bool isValidWord = validWord(point);
        if (!isValidWord) {
            point = strtok(NULL, " ");
            continue;
        }
        chopUpWord(point);
        wordExists(sentimentScore, point);
        point = strtok(NULL, " ");
    }

    // check total sentiment of tweet
    if (sentimentScore >= 0)
        return 4;
    else
        return 0;
}
void wordExists(int& sentimentScore, char word[]) {
    int positiveOcc = 0, negativeOcc = 0;
    vector<Word>::iterator it = find(positiveWords.begin(), positiveWords.end(), Word(word));
    if (it != positiveWords.end())
        positiveOcc += it->quantity;
    it = find(negativeWords.begin(), negativeWords.end(), Word(word));
    if (it != negativeWords.end())
        negativeOcc += it->quantity;
    if (positiveOcc >= negativeOcc)
        sentimentScore++;
    else
        sentimentScore--;
}

vector<Tweets>tweetActualSentimentResults;
void getActualSentiment(char sentimentFile[]) {
    //open file
    ifstream file(sentimentFile);
    char line[361],id[20], sentiment[5];

    if (file.is_open()) {
        //remove header line
        file.getline(line, 361, '\n');
        int i = 0;

        while (file && i < 10000) {
            file.getline(sentiment, 20, ',');
            file.getline(id, 20, '\n');
            int sentimentInt=0;
            if (sentiment[0] == '4')
                sentimentInt = 4;
            else if (sentiment[0] == '0')
                sentimentInt = 0;
            Tweets temp(id, sentimentInt);
            tweetActualSentimentResults.push_back(temp);
            i++;
        }
        file.close();
    }
}

void printResults(char outputFile[]) {
    vector<DSString>idsWrong;
    ofstream output(outputFile);
    int amountRight = 0;

    if (output.is_open()) {
        // loop through Tweets list
        for (int i = 0; i < tweetSentimentResults.size(); i++)
            // check if sentiments match
            if (tweetSentimentResults[i].Sentiment == tweetActualSentimentResults[i].Sentiment)
                ++amountRight;
            else
                idsWrong.push_back(tweetSentimentResults[i].Id);

        float percentRight = (float)amountRight / tweetActualSentimentResults.size();

        // output percent right
        output<< percentRight << endl;

        // output wrong id's
        for (int i = 0; i < idsWrong.size(); i++)
            output << idsWrong[i] << endl;
        output.close();
    }

}
