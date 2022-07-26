# Tweet Sentiment Analysis
This repository was created and maintained by Cullen Watson.

Email: cgwatson@smu.edu

## Functionality

Sentiment anaylsis is the process of classifying a phrase or sentences as positive or negative sentiment.

To determine the sentiment of tweets, I used a training dataset of 20k tweets with a pre-known sentiment to create a large collection
of words and its associated sentiment score. A value above 0 indicated that the word was more often seen in positive tweets and vice versa.

A test dataset was used to determine the accuracy of this classification scheme. I classified
new tweets by calculating its sentiment score. I then compared my results with the pre-determined results given by the data provider.

## Results

Overall, the sentiment accuracy was 68.1%. With larger datasets and training, I could see this number getting to 80+%.

## Binary Link

Download the exe [here](https://github.com/cullenwatson/tweet-sentiment-analysis/releases/tag/v0.1)

## How to Compile (Linux)

Compile and build using CMake

[Video Demo](https://youtu.be/1FiGnzL5qQs)

## How to Compile (using MinGW on Windows)

Create a build folder in the project directory and navigate to the build folder

Run the following command in the build folder

```cmake .. -G "MinGW Makefiles"```

Now run the `make` command

```mingw32-make```

## How to Run

The program takes one command line arg:

* output results file location

To run the program, type:

```./tweet_sentiment_analysis results.csv```

The `results.csv` contians an accuracy score and a list of tweets that were classified incorrectly.

