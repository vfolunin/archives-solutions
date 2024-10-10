WITH SortedSessions AS (
    SELECT *, RANK() OVER (PARTITION BY user_id ORDER BY session_start) i
    FROM Sessions
), SessionPairs AS (
    SELECT a.*
    FROM SortedSessions a JOIN SortedSessions b ON a.user_id = b.user_id AND a.i = 1 AND b.i != 1 AND a.session_type = "Viewer" AND b.session_type = "Streamer"
)
SELECT user_id, COUNT(*) sessions_count
FROM SessionPairs
GROUP BY user_id
ORDER BY sessions_count DESC, user_id DESC;
