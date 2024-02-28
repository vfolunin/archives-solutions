WITH OrderedFriends AS (
    SELECT user_id1, user_id2
    FROM Friends
    UNION ALL 
    SELECT user_id2 user_id1, user_id1 user_id2
    FROM Friends
), PairsWithMutualFriends AS (
    SELECT t1.user_id1 user_id1, t2.user_id1 user_id2, true have_mutual_friends
    FROM OrderedFriends t1 JOIN OrderedFriends t2 USING(user_id2)
    WHERE t1.user_id1 != t2.user_id1
)
SELECT user_id1, user_id2
FROM Friends LEFT JOIN PairsWithMutualFriends USING(user_id1, user_id2)
WHERE have_mutual_friends IS NULL
ORDER BY user_id1, user_id2;