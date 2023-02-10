SELECT product_id, quantity, quantity * price price
FROM Purchases JOIN Products USING(product_id)
WHERE invoice_id = (
    SELECT invoice_id
    FROM Purchases JOIN Products USING(product_id)
    GROUP BY invoice_id
    ORDER BY SUM(quantity * price) DESC, invoice_id
    LIMIT 1
);