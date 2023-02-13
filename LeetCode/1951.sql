WITH Pairs AS (
    SELECT a.user_id user1_id, b.user_id user2_id, COUNT(DISTINCT a.follower_id) follower_count
    FROM Relations a JOIN Relations b ON a.user_id < b.user_id AND a.follower_id = b.follower_id
    GROUP BY a.user_id, b.user_id
)
SELECT user1_id, user2_id
FROM Pairs
WHERE follower_count = (
    SELECT MAX(follower_count)
    FROM Pairs
);