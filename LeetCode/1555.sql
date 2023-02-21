WITH Income AS (
    SELECT paid_to user_id, SUM(amount) income
    FROM Transactions
    GROUP BY paid_to
), Outcome AS (
    SELECT paid_by user_id, SUM(amount) outcome
    FROM Transactions
    GROUP BY paid_by
), Credits AS (
    SELECT user_id, user_name, (credit + IFNULL(income, 0) - IFNULL(outcome, 0)) credit
    FROM Users users LEFT JOIN Income USING(user_id) LEFT JOIN Outcome USING(user_id)
)
SELECT *, IF(credit < 0, "Yes", "No") credit_limit_breached
FROM Credits;