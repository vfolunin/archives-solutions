WITH MinDates AS (
    SELECT customer_id, MIN(order_date) order_date
    FROM delivery 
    GROUP BY customer_id
)
SELECT ROUND(SUM(order_date = customer_pref_delivery_date) / COUNT(DISTINCT customer_id) * 100, 2) immediate_percentage 
FROM Delivery JOIN MinDates USING(customer_id, order_date);