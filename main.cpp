#define CATCH_CONFIG_RUNNER
#include "Functions.h"
#include "catch.hpp"
int test();
int main(int argc, char* argv[])
{
    // check to make sure user entered file's needed for program execution
    if (argc ==1) {
        test();
    }else{
        // get tweets
        readTrainFile(argv[1]);

        // get words
        addWords(positiveTweets, positiveWords);
        addWords(negativeTweets, negativeWords);

        // add test tweets and predicted sentiment to vector of type Tweets
        readTestFile(argv[2]);

        // read in actual sentiment and id's and put in another Tweet vector
        getActualSentiment(argv[3]);

        // compare the results of the two Tweet vectors
        printResults(argv[4]);


        cout << "done" << endl;
    }

    return 0;
}
int test(){
    return Catch::Session().run();
}