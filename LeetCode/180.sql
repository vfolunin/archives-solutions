SELECT DISTINCT a.num ConsecutiveNums
FROM Logs a, Logs b, Logs c
WHERE a.num = b.num AND a.id + 1 = b.id AND a.num = c.num AND a.id + 2 = c.id;