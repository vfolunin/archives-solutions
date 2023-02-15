WITH RECURSIVE VisitTransactions AS (
    SELECT v.user_id user_id, IF(transaction_date IS NULL, 0, COUNT(*)) transaction_count
    FROM Visits v LEFT JOIN Transactions t on v.user_id = t.user_id AND v.visit_date = t.transaction_date
    GROUP BY user_id, visit_date
), Indexes AS (
    SELECT 0 i
    UNION ALL
    SELECT i + 1 i
    FROM Indexes
    WHERE i < (
        SELECT MAX(transaction_count)
        FROM VisitTransactions
    )
)
SELECT i transactions_count, IF(transaction_count IS NULL, 0, COUNT(*)) visits_count
FROM Indexes LEFT JOIN VisitTransactions ON i = transaction_count
GROUP BY i
ORDER BY i;