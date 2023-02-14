SELECT
    LEFT(trans_date, 7) month,
    country,
    COUNT(*) trans_count,
    SUM(amount) trans_total_amount,
    SUM(state = "approved") approved_count,
    SUM(IF(state = "approved", amount, 0)) approved_total_amount
FROM Transactions
GROUP BY month, country;