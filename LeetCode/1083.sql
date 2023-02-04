SELECT buyer_id
FROM Sales JOIN Product USING(product_id)
GROUP BY buyer_id
HAVING SUM(IF(product_name = "S8", 1, 0)) > 0 AND SUM(IF(product_name = "IPhone", 1, 0)) = 0;