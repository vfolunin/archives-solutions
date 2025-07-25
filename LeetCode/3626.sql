WITH indexed_inventory AS (
    SELECT
        store_id,
        product_name,
        quantity,
        RANK() OVER(PARTITION BY store_id ORDER BY price DESC) i,
        RANK() OVER(PARTITION BY store_id ORDER BY price) j
    FROM inventory
), most_exp AS (
    SELECT store_id, product_name most_exp_product, quantity most_exp_quantity
    FROM indexed_inventory
    WHERE i = 1 AND j > 2
), cheapest AS (
    SELECT store_id, product_name cheapest_product, quantity cheapest_quantity
    FROM indexed_inventory
    WHERE j = 1 AND i > 2
)
SELECT
    store_id,
    store_name,
    location,
    most_exp_product,
    cheapest_product,
    ROUND(cheapest_quantity / most_exp_quantity, 2) imbalance_ratio
FROM stores JOIN most_exp USING(store_id) JOIN cheapest USING(store_id)
WHERE most_exp_quantity < cheapest_quantity
ORDER BY imbalance_ratio DESC, store_name;