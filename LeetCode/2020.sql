SELECT COUNT(account_id) accounts_count
FROM Subscriptions JOIN Streams USING(account_id)
WHERE (YEAR(start_date) = 2021 OR YEAR(end_date) = 2021) AND YEAR(stream_date) <> 2021;