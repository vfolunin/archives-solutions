WITH TotalTime AS (
    SELECT SUM(time_spent) total_time, age_bucket
    FROM Activities JOIN Age USING(user_id)
    GROUP BY age_bucket
)
SELECT
    age_bucket,
    ROUND(SUM(IF(activity_type = 'send', time_spent, 0)) / total_time * 100, 2) send_perc,
    ROUND(SUM(IF(activity_type = 'open', time_spent, 0)) / total_time * 100, 2) open_perc
FROM Activities JOIN Age USING(user_id) JOIN TotalTime USING(age_bucket)
GROUP BY age_bucket;