WITH Friendship AS (
    SELECT user1_id, user2_id
    FROM Friendship
    UNION ALL
    SELECT user2_id user1_id, user1_id user2_id
    FROM Friendship
), Pairs AS (
    SELECT DISTINCT a.user_id user1_id, b.user_id user2_id
    FROM Listens a JOIN Listens b ON a.day = b.day AND a.song_id = b.song_id AND a.user_id <> b.user_id
    GROUP BY a.day, a.user_id, b.user_id
    HAVING COUNT(DISTINCT a.song_id) >= 3
)
SELECT user1_id user_id, user2_id recommended_id
FROM Pairs LEFT JOIN Friendship f USING(user1_id, user2_id)
WHERE f.user1_id IS NULL;