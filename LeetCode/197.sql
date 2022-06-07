SELECT w2.id
FROM weather w1 JOIN weather w2 ON ADDDATE(w1.recordDate, 1) = w2.recordDate
WHERE w1.temperature < w2.temperature;