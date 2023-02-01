SELECT name warehouse_name, SUM(units * Width * Length * Height) volume
FROM Warehouse JOIN Products USING(product_id)
GROUP BY warehouse_name;