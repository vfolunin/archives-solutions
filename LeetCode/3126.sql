WITH RankedServers AS (
    SELECT *, RANK() OVER (PARTITION BY server_id ORDER BY status_time, session_status) r
    FROM Servers
), Uptime AS (
    SELECT TIMESTAMPDIFF(SECOND, a.status_time, b.status_time) duration
    FROM RankedServers a, RankedServers b
    WHERE a.server_id = b.server_id AND a.session_status = 'start' AND a.r + 1 = b.r
)
SELECT SUM(duration) DIV 86400 total_uptime_days
FROM Uptime;