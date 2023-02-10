WITH RECURSIVE Ids AS (
    SELECT 1 id
    UNION ALL
    SELECT id + 1
    FROM Ids
    WHERE id < (
        SELECT MAX(customer_id)
        FROM Customers
    )
)
SELECT id ids
FROM Ids
WHERE id NOT IN (
    SELECT customer_id
    FROM Customers
);