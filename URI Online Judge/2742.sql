SELECT l.name, ROUND(l.omega * 1.618, 3) AS "The N Factor"
FROM life_registry AS l
JOIN dimensions AS d ON l.dimensions_id = d.id
WHERE l.name LIKE 'Richard%' AND d.name IN ('C774', 'C875')
ORDER BY l.omega;