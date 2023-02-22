WITH IndexedOrders AS (
    SELECT seller_id, item_id, RANK() OVER (PARTITION BY seller_id ORDER BY order_date) i
    FROM Orders
), SecondBrands AS (
    SELECT seller_id, item_brand
    FROM IndexedOrders JOIN Items USING(item_id)
    WHERE i = 2
)
SELECT user_id seller_id, IF(item_brand = favorite_brand, "yes", "no") 2nd_item_fav_brand
FROM Users LEFT JOIN SecondBrands ON user_id = seller_id;