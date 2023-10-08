WITH Increases AS (
    SELECT a.customer_id, a.transaction_date 
    FROM Transactions a, Transactions b 
    WHERE a.customer_id = b.customer_id AND DATEDIFF(b.transaction_date, a.transaction_date) = 1 AND a.amount < b.amount
),
IncreaseIndexes AS (
    SELECT customer_id, transaction_date, ROW_NUMBER() OVER (PARTITION BY customer_id ORDER BY transaction_date) i
    FROM Increases
),
IngreaseGroups AS (
    SELECT customer_id, transaction_date, DATE_SUB(transaction_date, INTERVAL i DAY) increase_group
    FROM IncreaseIndexes
),
IngreaseGroupSizes AS (
    SELECT customer_id, MIN(transaction_date) consecutive_start, COUNT(*) increase_group_size
    FROM IngreaseGroups 
    GROUP BY customer_id, increase_group
)
SELECT customer_id, consecutive_start, DATE_ADD(consecutive_start, INTERVAL increase_group_size DAY) consecutive_end 
FROM IngreaseGroupSizes 
WHERE increase_group_size > 1 
ORDER BY customer_id;