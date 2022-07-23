<h2>Tweet Sentiment Analysis</h2>

Sentiment anaylsis is the process of classifying a phrase or sentences as positive or negative sentiment.

To determine the sentiment of tweets, I used a training dataset of 20k tweets with a pre-known sentiment to create a large collection
of words and its associated sentiment score. A value above 0 indicated that the word was more often seen in positive tweets and vice versa.

Then, a test dataset was used to determine the accuracy of this classification scheme. I classified
new tweets by calculating its sentiment score. I then compared my results with the pre-determined results by the data provider.

Overall, the sentiment accuracy was 68.1%. With larger datasets and training, I could see this number getting to 80+%.

Three program arguments are needed the (1) training dataset, (2) testing dataset (3) testing dataset with pre-verified results

<br>
To run

### `./{name of executable} data/train_dataset_20k.csv data/test_dataset_10k.csv data/test_dataset_20.csv`

Results will be in `data/results.csv` with an accuracy score and a list of tweets that were classified incorrectly.
