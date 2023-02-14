SELECT product_name, product_id, order_id, order_date
FROM Orders JOIN Products USING(product_id)
WHERE (product_id, order_date) IN (
    SELECT product_id, MAX(order_date) order_date
    FROM Orders
    GROUP BY product_id
)
ORDER BY product_name, product_id, order_id;