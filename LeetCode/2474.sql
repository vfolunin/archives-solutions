WITH Costs AS (
    SELECT customer_id, YEAR(order_date) y, SUM(price) cost
    FROM Orders
    GROUP BY customer_id, y
)
SELECT a.customer_id
FROM Costs a LEFT JOIN Costs b ON a.customer_id = b.customer_id AND a.y + 1 = b.y
GROUP BY a.customer_id
HAVING SUM(a.cost >= IFNULL(b.cost, 0)) = 1;