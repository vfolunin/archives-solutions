WITH Sellers AS (
    SELECT seller_id, COUNT(DISTINCT item_id) num_items
    FROM Orders LEFT JOIN Items USING(item_id) LEFT JOIN Users USING(seller_id)
    WHERE item_brand != favorite_brand
    GROUP BY seller_id
)
SELECT *
FROM Sellers
WHERE num_items = (SELECT MAX(num_items) FROM Sellers)
ORDER BY seller_id;