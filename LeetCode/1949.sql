WITH Edges AS (
    SELECT *
    FROM Friendship
    UNION ALL
    SELECT user2_id user1_id, user1_id user2_id
    FROM Friendship
)
SELECT a.user1_id, a.user2_id, COUNT(c.user2_id) common_friend
FROM Friendship a JOIN Edges b ON a.user1_id = b.user1_id JOIN Edges c ON a.user2_id = c.user1_id AND b.user2_id = c.user2_id
GROUP BY a.user1_id, a.user2_id
HAVING COUNT(c.user2_id) >= 3;