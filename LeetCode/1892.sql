WITH Friendship AS (
    SELECT user1_id, user2_id
    FROM Friendship
    UNION ALL
    SELECT user2_id user1_id, user1_id user2_id
    FROM Friendship
), Users AS (
    SELECT DISTINCT user1_id user_id
    FROM Friendship
), Pages AS (
    SELECT DISTINCT page_id
    FROM Likes
), IsLiked AS (
    SELECT user_id, page_id, COUNT(l.page_id) is_liked
    FROM (Users, Pages) LEFT JOIN Likes l USING(user_id, page_id)
    GROUP BY user_id, page_id
)
SELECT user1_id user_id, a.page_id page_id, SUM(b.is_liked) friends_likes
FROM
    Friendship
    JOIN IsLiked a ON user1_id = a.user_id AND a.is_liked = 0
    JOIN IsLiked b ON user2_id = b.user_id AND b.is_liked = 1 AND a.page_id = b.page_id
GROUP BY user1_id, page_id;