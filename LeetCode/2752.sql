WITH TransactionIndexes AS (
    SELECT customer_id, transaction_date, ROW_NUMBER() OVER (PARTITION BY customer_id ORDER BY transaction_date) i
    FROM Transactions
),
TransactionGroups AS (
    SELECT customer_id, transaction_date, DATE_SUB(transaction_date, INTERVAL i DAY) transaction_group
    FROM TransactionIndexes
),
TransactionGroupSizes AS (
    SELECT customer_id, MIN(transaction_date) consecutive_start, COUNT(*) transaction_group_size
    FROM TransactionGroups 
    GROUP BY customer_id, transaction_group
),
MaxTransactionGroupSize AS (
    SELECT MAX(transaction_group_size) max_transaction_group_size
    FROM TransactionGroupSizes
)
SELECT customer_id
FROM TransactionGroupSizes, MaxTransactionGroupSize 
WHERE transaction_group_size = max_transaction_group_size
ORDER BY customer_id;