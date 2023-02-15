WITH InstallDates AS (
    SELECT player_id, MIN(event_date) install_dt
    FROM Activity
    GROUP BY player_id
), Retention AS (
    SELECT d.player_id, install_dt, event_date
    FROM InstallDates d LEFT JOIN Activity a ON d.player_id = a.player_id AND d.install_dt + 1 = a.event_date
)
SELECT 
    install_dt,
    COUNT(player_id) installs,
    ROUND(COUNT(event_date) / COUNT(player_id), 2) Day1_retention
FROM Retention
GROUP BY install_dt;