WITH Alerts AS (
    SELECT account_id, max_income, MONTH(day) month
    FROM Accounts JOIN Transactions USING(account_id)
    WHERE type = "Creditor"
    GROUP BY account_id, MONTH(day)
    HAVING SUM(amount) > max_income
)
SELECT DISTINCT a.account_id
FROM Alerts a JOIN Alerts b ON a.account_id = b.account_id AND a.month + 1 = b.month;