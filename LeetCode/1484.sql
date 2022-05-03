SELECT sell_date, COUNT(DISTINCT product) num_sold, GROUP_CONCAT(DISTINCT product) products
FROM Activities
GROUP BY sell_date;