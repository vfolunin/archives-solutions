WITH MinDates AS (
    SELECT player_id, MIN(event_date) event_date 
    FROM Activity 
    GROUP BY player_id
)
SELECT ROUND(COUNT(d2.player_id) / COUNT(d1.player_id), 2) fraction 
FROM MinDates d1 LEFT JOIN Activity d2 ON d1.player_id = d2.player_id AND d1.event_date + 1 = d2.event_date;