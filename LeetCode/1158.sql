SELECT u.user_id buyer_id, u.join_date, COUNT(o.buyer_id) orders_in_2019 
FROM Users u LEFT JOIN Orders o ON u.user_id = o.buyer_id AND YEAR(order_date) = 2019
GROUP BY u.user_id;