SELECT user_id, SUM(quantity * price) spending
FROM Sales JOIN Product USING(product_id)
GROUP BY user_id
ORDER BY spending DESC, user_id;