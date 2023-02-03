SELECT MIN(b.x - a.x) shortest
FROM Point a JOIN Point b ON a.x < b.x;