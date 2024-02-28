WITH ConsecutiveSessions AS (
    SELECT *, LAG(session_end) OVER (PARTITION BY user_id, session_type ORDER BY session_start) prev_session_end
    FROM Sessions
)
SELECT DISTINCT user_id
FROM ConsecutiveSessions
WHERE session_start <= DATE_ADD(prev_session_end, INTERVAL 12 HOUR)
ORDER BY user_id;