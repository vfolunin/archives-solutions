WITH Teams AS (
    SELECT salary, RANK() OVER (ORDER BY salary) team_id
    FROM Employees
    GROUP BY salary
    HAVING COUNT(salary) > 1
)
SELECT employee_id, name, salary, team_id
FROM Employees JOIN Teams USING(salary)
ORDER BY team_id, employee_id;