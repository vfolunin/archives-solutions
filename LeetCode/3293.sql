SELECT product_id, price * COALESCE(1 - discount / 100, 1) final_price, category
FROM Products LEFT JOIN Discounts USING(category)
ORDER BY product_id;