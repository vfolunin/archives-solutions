SELECT product_id, product_name
FROM Product JOIN Sales USING(product_id)
GROUP BY product_id
HAVING '2019-01-01' <= MIN(sale_date) AND MAX(sale_date) <= '2019-03-31';