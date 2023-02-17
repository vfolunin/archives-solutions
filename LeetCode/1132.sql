WITH DailyPercents AS (
    SELECT action_date, COUNT(DISTINCT r.post_id) / COUNT(DISTINCT a.post_id) * 100 AS daily_percent
    FROM Actions a LEFT JOIN Removals r USING(post_id)
    WHERE extra = "spam"
    GROUP BY action_date
)
SELECT ROUND(AVG(daily_percent), 2) average_daily_percent
FROM DailyPercents;