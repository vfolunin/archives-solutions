SELECT
    b.account_id,
    b.day,
    SUM(a.amount * IF(a.type = "Deposit", 1, -1)) balance
FROM Transactions a JOIN Transactions b ON a.account_id = b.account_id AND a.day <= b.day
GROUP BY account_id, day
ORDER BY account_id, day;