SELECT 
    name,
    IFNULL(SUM(rest), 0) rest,
    IFNULL(SUM(paid), 0) paid,
    IFNULL(SUM(canceled), 0) canceled,
    IFNULL(SUM(refunded), 0) refunded   
FROM Product LEFT JOIN Invoice USING(product_id)
GROUP BY product_id
ORDER BY name;