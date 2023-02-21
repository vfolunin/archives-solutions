WITH OrderCount AS (
    SELECT customer_id, product_id, product_name, COUNT(*) order_count
    FROM Customers JOIN Orders USING(customer_id) JOIN Products USING(product_id)
    GROUP BY customer_id, product_id
), MaxOrderCount AS (
    SELECT customer_id, MAX(order_count) order_count
    FROM OrderCount
    GROUP BY customer_id
)
SELECT customer_id, product_id, product_name
FROM OrderCount JOIN MaxOrderCount USING (customer_id, order_count);