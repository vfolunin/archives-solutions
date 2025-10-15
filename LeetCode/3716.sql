WITH user_stats AS (
    SELECT 
        user_id,
        MIN(event_date) first_event_date,
        MAX(event_date) last_event_date,
        MAX(monthly_amount) max_historical_amount,
        SUM(CASE WHEN event_type = 'downgrade' THEN 1 ELSE 0 END) downgrade_count
    FROM subscription_events
    GROUP BY user_id
), last_events AS (
    SELECT 
        user_id,
        event_type,
        plan_name,
        monthly_amount,
        ROW_NUMBER() OVER (PARTITION BY user_id ORDER BY event_date DESC, event_id DESC) i
    FROM subscription_events
)
SELECT 
    user_id,
    plan_name current_plan,
    monthly_amount current_monthly_amount,
    max_historical_amount,
    DATEDIFF(last_event_date, first_event_date) days_as_subscriber
FROM user_stats JOIN last_events USING(user_id)
WHERE
    i = 1 AND
    event_type != 'cancel' AND
    downgrade_count > 0 AND
    monthly_amount < max_historical_amount * 0.5 AND
    DATEDIFF(last_event_date, first_event_date) >= 60
ORDER BY days_as_subscriber DESC, user_id;