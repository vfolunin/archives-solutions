SELECT seller_id
FROM Sales
GROUP BY seller_id
HAVING SUM(price) = (
    SELECT SUM(price) total
    FROM Sales
    GROUP BY seller_id
    ORDER BY total DESC
    LIMIT 1
);