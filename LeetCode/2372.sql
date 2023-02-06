SELECT salesperson_id, name, IFNULL(SUM(price), 0) total
FROM Salesperson LEFT JOIN Customer USING(salesperson_id) LEFT JOIN Sales USING(customer_id)
GROUP BY salesperson_id;