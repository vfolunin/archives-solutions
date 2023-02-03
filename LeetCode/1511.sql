SELECT customer_id, name
FROM Orders JOIN Customers USING(customer_id) JOIN Product USING(product_id)
GROUP BY customer_id
HAVING SUM(IF(LEFT(order_date, 7) = '2020-06', quantity * price, 0)) >= 100 AND
       SUM(IF(LEFT(order_date, 7) = '2020-07', quantity * price, 0)) >= 100;