SELECT DISTINCT user1_id, user2_id
FROM Friendship f JOIN Listens a ON f.user1_id = a.user_id JOIN Listens b ON f.user2_id = b.user_id AND a.day = b.day AND a.song_id = b.song_id
GROUP BY user1_id, user2_id, a.day
HAVING COUNT(DISTINCT a.song_id) >= 3;