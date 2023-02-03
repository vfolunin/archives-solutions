SELECT id, year, COALESCE(npv, 0) npv
FROM Queries LEFT JOIN NPV USING(id, year)
ORDER BY id, year;