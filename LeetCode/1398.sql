SELECT *
FROM Customers
WHERE
    customer_id IN (
        SELECT DISTINCT customer_id
        FROM Orders
        WHERE product_name = "A"
    ) AND customer_id IN (
        SELECT DISTINCT customer_id
        FROM Orders
        WHERE product_name = "B"
    ) AND customer_id NOT IN (
        SELECT DISTINCT customer_id
        FROM Orders
        WHERE product_name = "C"
    );