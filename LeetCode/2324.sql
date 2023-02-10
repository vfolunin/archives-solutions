 WITH Costs AS (
    SELECT user_id, product_id, SUM(quantity * price) cost
    FROM Sales JOIN Product USING(product_id)
    GROUP BY user_id, product_id
 )
 SELECT user_id, product_id
 FROM Costs
 WHERE (user_id, cost) IN (
    SELECT user_id, MAX(cost)
    FROM Costs
    GROUP BY user_id
 );