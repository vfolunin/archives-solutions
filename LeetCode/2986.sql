WITH TripleTransactions AS (
    SELECT
        user_id,
        spend third_transaction_spend,
        transaction_date third_transaction_date,
        RANK() OVER (PARTITION BY user_id ORDER BY transaction_date) i,
        LAG(spend) OVER (PARTITION BY user_id ORDER BY transaction_date) second_transaction_spend,
        LAG(spend, 2) OVER (PARTITION BY user_id ORDER BY transaction_date) first_transaction_spend
    FROM Transactions
)
SELECT user_id, third_transaction_spend, third_transaction_date
FROM TripleTransactions
WHERE i = 3 AND first_transaction_spend < third_transaction_spend AND second_transaction_spend < third_transaction_spend
ORDER BY user_id;