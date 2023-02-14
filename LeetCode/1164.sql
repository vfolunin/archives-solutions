WITH LastChangeDates AS (
    SELECT product_id, MAX(change_date) change_date
    FROM Products 
    WHERE change_date <= "2019-08-16"
    GROUP BY product_id
)

SELECT DISTINCT product_id, new_price price 
FROM Products
WHERE (product_id, change_date) IN (
    SELECT *
    FROM LastChangeDates
)

UNION ALL 

SELECT DISTINCT product_id, 10 price 
FROM Products
WHERE product_id NOT IN (
    SELECT product_id
    FROM LastChangeDates
);