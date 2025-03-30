WITH Trial AS (
    SELECT user_id, ROUND(AVG(activity_duration), 2) trial_avg_duration
    FROM UserActivity
    WHERE activity_type = "free_trial"
    GROUP BY user_id
), Paid AS (
    SELECT user_id, ROUND(AVG(activity_duration), 2) paid_avg_duration
    FROM UserActivity
    WHERE activity_type = "paid"
    GROUP BY user_id
)
SELECT user_id, trial_avg_duration, paid_avg_duration
FROM Trial JOIN Paid USING(user_id)
ORDER BY user_id;