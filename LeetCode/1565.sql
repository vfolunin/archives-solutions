SELECT
    LEFT(order_date, 7) month,
    COUNT(order_id) order_count,
    COUNT(DISTINCT customer_id) customer_count
FROM Orders
WHERE invoice > 20
GROUP BY month;