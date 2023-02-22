WITH YearOrders AS (
    SELECT product_id, YEAR(purchase_date) year
    FROM Orders
    GROUP BY product_id, year
    HAVING COUNT(order_id) >= 3
)
SELECT DISTINCT a.product_id
FROM YearOrders a JOIN YearOrders b ON a.product_id = b.product_id AND a.year + 1 = b.year;