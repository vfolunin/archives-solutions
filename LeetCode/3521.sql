WITH Purchases AS (
    SELECT user_id, product_id, category
    FROM ProductPurchases JOIN ProductInfo USING(product_id)
) SELECT
    a.product_id product1_id,
    b.product_id product2_id,
    a.category product1_category,
    b.category product2_category,
    COUNT(a.user_id) customer_count
FROM Purchases a JOIN Purchases b ON a.user_id = b.user_id AND a.product_id < b.product_id
GROUP BY product1_id, product2_id
HAVING customer_count >= 3
ORDER BY customer_count DESC, product1_id, product2_id;