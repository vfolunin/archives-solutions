SELECT DISTINCT a.seat_id
FROM Cinema a JOIN Cinema b ON ABS(a.seat_id - b.seat_id) = 1 AND a.free AND b.free
ORDER BY a.seat_id;