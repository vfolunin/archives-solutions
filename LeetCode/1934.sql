SELECT user_id, ROUND(IFNULL(SUM(action = "confirmed") / COUNT(action), 0), 2) confirmation_rate
FROM Signups LEFT JOIN Confirmations USING (user_id)
GROUP BY user_id;