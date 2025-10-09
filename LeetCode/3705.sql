SELECT
    customer_id,
    COUNT(order_id) total_orders,
    ROUND(SUM(IF(HOUR(order_timestamp) BETWEEN 11 AND 13 OR HOUR(order_timestamp) BETWEEN 18 AND 20, 1, 0)) / COUNT(order_id), 2) * 100 peak_hour_percentage,
    ROUND(AVG(order_rating), 2) average_rating
FROM restaurant_orders
GROUP BY customer_id
HAVING
    total_orders >= 3 AND peak_hour_percentage >= 60 AND average_rating >= 4 AND
    SUM(IF(order_rating IS NOT NULL, 1, 0)) / COUNT(order_id) > 0.5
ORDER BY average_rating DESC, customer_id DESC;