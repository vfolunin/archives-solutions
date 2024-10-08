WITH RECURSIVE tags AS (
    SELECT REGEXP_SUBSTR(tweet, "#[^\\s]+") hashtag, REGEXP_REPLACE(tweet, "#[^\\s]+", "", 1, 1) tweet
    FROM Tweets

    UNION ALL

    SELECT REGEXP_SUBSTR(tweet, "#[^\\s]+") hashtag, REGEXP_REPLACE(tweet, "#[^\\s]+", "", 1, 1) tweet
    FROM tags
    WHERE hashtag IS NOT NULL
)
SELECT hashtag, COUNT(*) count
FROM tags
WHERE hashtag IS NOT NULL
GROUP BY hashtag
ORDER BY count DESC, hashtag DESC
LIMIT 3;