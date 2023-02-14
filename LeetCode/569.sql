SELECT id, company, salary
FROM (
    SELECT
        *,
        ROW_NUMBER() OVER (PARTITION BY company ORDER BY salary, id) i,
        COUNT(*) OVER (PARTITION BY company) size 
    FROM Employee
) s
WHERE i BETWEEN size / 2 AND size / 2 + 1;