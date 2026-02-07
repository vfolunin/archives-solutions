WITH day_actions AS (
    SELECT user_id, action_date, action
    FROM activity
    GROUP BY user_id, action_date
    HAVING COUNT(*) = 1
), streaks AS (
    SELECT *, DATE_SUB(action_date, INTERVAL ROW_NUMBER() OVER (PARTITION BY user_id ORDER BY action_date) - 1 DAY) group_date
    FROM day_actions
)
SELECT user_id, action, COUNT(*) streak_length, MIN(action_date) start_date, MAX(action_date) end_date
FROM streaks
GROUP BY user_id, action, group_date
HAVING streak_length >= 5
ORDER BY streak_length DESC, user_id;