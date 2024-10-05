WITH RECURSIVE Managers AS (
    SELECT employee_id subordinate_id, employee_name subordinate_name, 0 hierarchy_level, salary
    FROM Employees
    WHERE manager_id IS NULL

    UNION ALL
    
    SELECT e.employee_id, e.employee_name, hierarchy_level + 1, e.salary
    FROM Employees e JOIN Managers m ON m.subordinate_id = e.manager_id
)
SELECT
    subordinate_id,
    subordinate_name,
    hierarchy_level,
    salary - (SELECT salary FROM Managers WHERE hierarchy_level = 0) salary_difference
FROM Managers
WHERE hierarchy_level != 0
ORDER BY hierarchy_level, subordinate_id;