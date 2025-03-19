WITH RECURSIVE Levels AS (
    SELECT employee_id, employee_name, manager_id, 1 level, salary
    FROM Employees
    UNION ALL
    SELECT a.employee_id, a.employee_name, b.manager_id, level + 1, a.salary
    FROM Levels a JOIN Employees b ON a.manager_id = b.employee_id
), Managers AS (
    SELECT employee_id, employee_name, salary, level
    FROM Levels
    WHERE manager_id IS NULL
), Teams AS (
    SELECT manager_id, COUNT(*) team_size, SUM(salary) budget
    FROM Levels
    WHERE manager_id IS NOT NULL
    GROUP BY manager_id
)
SELECT employee_id, employee_name, level, COALESCE(team_size, 0) team_size, salary + COALESCE(budget, 0) budget
FROM Managers LEFT JOIN Teams ON employee_id = manager_id
ORDER BY level, budget DESC, employee_name;