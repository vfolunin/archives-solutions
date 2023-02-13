SELECT c.name customer_name, c.customer_id, o1.order_id, o1.order_date
FROM Customers c JOIN Orders o1 ON c.customer_id = o1.customer_id JOIN Orders o2 ON c.customer_id = o2.customer_id AND o1.order_date <= o2.order_date
GROUP BY c.customer_id, o1.order_id
HAVING COUNT(o2.order_date) <= 3
ORDER BY customer_name, customer_id, order_date DESC;