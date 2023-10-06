SELECT (minute - 1) DIV 6 + 1 interval_no, SUM(order_count) total_orders
FROM Orders
GROUP BY interval_no
ORDER BY interval_no;