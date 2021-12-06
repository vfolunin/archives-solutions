(SELECT name, customers_number 
FROM lawyers
ORDER BY customers_number DESC
LIMIT 1)

UNION ALL

(SELECT name, customers_number 
FROM lawyers
ORDER BY customers_number
LIMIT 1)

UNION ALL

(SELECT 'Average' AS name, CAST(AVG(customers_number) AS INT) AS customers_number
FROM lawyers);