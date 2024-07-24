WITH classified_transactions AS (
    SELECT
        transaction_date,
        IF(amount % 2, amount, 0) odd_amount,
        IF(amount % 2 = 0, amount, 0) even_amount
    FROM transactions
)
SELECT
    transaction_date,
    SUM(odd_amount) odd_sum,
    SUM(even_amount) even_sum
FROM classified_transactions
GROUP BY transaction_date
ORDER BY transaction_date;