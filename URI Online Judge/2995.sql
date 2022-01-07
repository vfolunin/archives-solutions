SELECT MIN(temperature) AS temperature, COUNT(*) AS number_of_records
FROM records
GROUP BY mark
ORDER BY MIN(id);