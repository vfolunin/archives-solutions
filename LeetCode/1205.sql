WITH Ops AS (
    SELECT *
    FROM Transactions
    WHERE state = "approved"
    UNION ALL
    SELECT t.id, t.country, "chargeback" state, t.amount, c.trans_date
    FROM Chargebacks c JOIN Transactions t ON c.trans_id = t.id
)
SELECT 
    LEFT(trans_date, 7) month,
    country,
    SUM(state = "approved") approved_count,
    SUM(IF(state = "approved", amount, 0)) approved_amount,
    SUM(state = "chargeback") chargeback_count,
    SUM(IF(state = "chargeback", amount, 0)) chargeback_amount
FROM Ops
GROUP BY month, country;