SELECT user_id
FROM emails JOIN texts USING(email_id)
WHERE signup_action = "Verified" AND DATE_ADD(DATE(signup_date), INTERVAL 1 DAY) = DATE(action_date)
ORDER BY user_id;