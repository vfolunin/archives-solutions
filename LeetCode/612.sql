SELECT ROUND(SQRT(POWER(a.x - b.x, 2) + POWER(a.y - b.y, 2)), 2) shortest
FROM Point2D a JOIN Point2D b ON a.x <> b.x OR a.y <> b.y
ORDER BY shortest
LIMIT 1;