SELECT product_id, SUM(quantity) total_quantity
FROM Sales
GROUP BY product_id;