WITH IndexedUsers AS (
    SELECT *, ROW_NUMBER() OVER() i
    FROM Users
)
SELECT DISTINCT a.user_id
FROM IndexedUsers a JOIN IndexedUsers b ON a.user_id = b.user_id AND a.i != b.i AND ABS(DATEDIFF(a.created_at, b.created_at)) <= 7;