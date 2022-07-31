#define CATCH_CONFIG_RUNNER
#include "Functions.h"

int main(int argc, char* argv[])
{

        // get tweets
        cout<<"Reading training file..."<<endl;
        readTrainFile("../input/train_dataset_20k.csv");
        // get words
        addWords(positiveTweets, positiveWords);
        addWords(negativeTweets, negativeWords);

        cout<<"Reading test file..."<<endl;
        // add test tweets and predicted sentiment to vector of type Tweets
        readTestFile("../input/test_dataset_10k.csv");

        cout<<"Calculating results..."<<endl;
        // read in actual sentiment and id's and put in another Tweet vector
        getActualSentiment("../input/test_dataset_sentiment_10k.csv");

        // compare the results of the two Tweet vectors
        printResults(argv[1]);


        cout << "Complete!" << endl;


    return 0;
}
