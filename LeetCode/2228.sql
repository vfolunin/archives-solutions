SELECT DISTINCT a.user_id
FROM Purchases a JOIN Purchases b ON
    a.purchase_id <> b.purchase_id AND a.user_id = b.user_id AND
    ABS(DATEDIFF(b.purchase_date, a.purchase_date)) <= 7
ORDER BY a.user_id;