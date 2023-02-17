SELECT b.book_id, name 
FROM Books b LEFT JOIN Orders o ON b.book_id = o.book_id AND dispatch_date BETWEEN "2018-06-23" AND "2019-06-23"
WHERE DATEDIFF("2019-06-23", available_from) > 30
GROUP BY b.book_id
HAVING SUM(IFNULL(quantity, 0)) < 10;