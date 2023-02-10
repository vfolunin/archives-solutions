SELECT
    item_category CATEGORY,
    SUM(IF(WEEKDAY(order_date) = 0, quantity, 0)) MONDAY,
    SUM(IF(WEEKDAY(order_date) = 1, quantity, 0)) TUESDAY,
    SUM(IF(WEEKDAY(order_date) = 2, quantity, 0)) WEDNESDAY,
    SUM(IF(WEEKDAY(order_date) = 3, quantity, 0)) THURSDAY,
    SUM(IF(WEEKDAY(order_date) = 4, quantity, 0)) FRIDAY,
    SUM(IF(WEEKDAY(order_date) = 5, quantity, 0)) SATURDAY,
    SUM(IF(WEEKDAY(order_date) = 6, quantity, 0)) SUNDAY
FROM Items LEFT JOIN Orders USING(item_id)
GROUP BY category
ORDER BY category;