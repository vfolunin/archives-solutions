SELECT transaction_id
FROM Transactions
WHERE (DAY(day), amount) IN (
    SELECT DAY(day), MAX(amount)
    FROM Transactions
    GROUP BY DAY(day)
)
ORDER BY transaction_id;