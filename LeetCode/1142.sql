SELECT ROUND(IFNULL(COUNT(DISTINCT session_id) / COUNT(DISTINCT user_id), 0), 2) average_sessions_per_user 
FROM Activity
WHERE activity_date BETWEEN "2019-06-28" AND "2019-07-27";