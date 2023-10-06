WITH Friends AS (
    SELECT *
    FROM Friends
    UNION
    SELECT user2, user1
    FROM Friends
), UserCount AS (
    SELECT COUNT(DISTINCT user1) userCount
    FROM Friends
)
SELECT user1, ROUND(COUNT(DISTINCT user2) / userCount * 100, 2) percentage_popularity
FROM Friends, UserCount
GROUP BY user1
ORDER BY user1;