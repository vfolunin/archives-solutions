SELECT u.product_id, ROUND(SUM(units * price) / SUM(units), 2) average_price
FROM UnitsSold u JOIN Prices p ON u.product_id = p.product_id AND purchase_date BETWEEN start_date AND end_date
GROUP BY u.product_id;