SELECT REGEXP_SUBSTR(tweet, "\#[a-zA-Z]+") hashtag, COUNT(*) hashtag_count
FROM Tweets
WHERE YEAR(tweet_date) = "2024" AND MONTH(tweet_date) = "2"
GROUP BY hashtag
ORDER BY hashtag_count DESC, hashtag DESC
LIMIT 3;