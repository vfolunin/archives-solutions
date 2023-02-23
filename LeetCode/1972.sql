WITH Pairs AS (
    SELECT caller_id a, recipient_id b, DATE(call_time) date, call_time time
    FROM Calls
    UNION ALL
    SELECT recipient_id a, caller_id b, DATE(call_time) date, call_time time
    FROM Calls
), IndexedPairs AS (
    SELECT
        *,
        RANK() OVER (PARTITION BY a, date ORDER BY time) index_asc,
        RANK() OVER (PARTITION BY a, date ORDER BY time DESC) index_desc
    FROM Pairs
)
SELECT DISTINCT a user_id
FROM IndexedPairs
WHERE index_asc = 1 OR index_desc = 1
GROUP BY a, date
HAVING COUNT(DISTINCT b) = 1;