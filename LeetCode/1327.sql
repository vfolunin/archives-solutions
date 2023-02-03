SELECT product_name, SUM(unit) unit
FROM Orders JOIN Products USING(product_id)
WHERE order_date BETWEEN "2020-02-01" AND "2020-02-29"
GROUP BY product_id
HAVING unit >= 100;