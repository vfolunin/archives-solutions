SELECT name
FROM SalesPerson
WHERE sales_id NOT IN (
    SELECT sales_id
    FROM Orders JOIN Company USING(com_id)
    WHERE name = "RED"
);