WITH Quantities AS (
    SELECT order_id, MAX(quantity) max_quantity, AVG(quantity) avg_quantity
    FROM OrdersDetails
    GROUP BY order_id
)
SELECT order_id
FROM Quantities
WHERE max_quantity > (
    SELECT MAX(avg_quantity)
    FROM Quantities
);