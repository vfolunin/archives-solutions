SELECT
    product_id,
    MAX(IF(store = 'store1', price, NULL)) store1,
    MAX(IF(store = 'store2', price, NULL)) store2,
    MAX(IF(store = 'store3', price, NULL)) store3
FROM Products
GROUP BY product_id