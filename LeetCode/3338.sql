WITH indexedEmployees AS (
    SELECT *, DENSE_RANK() OVER (PARTITION BY dept ORDER BY salary DESC) i
    FROM employees
)
SELECT emp_id, dept
FROM indexedEmployees
WHERE i = 2
ORDER BY emp_id;