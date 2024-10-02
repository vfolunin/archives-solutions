WITH Departments AS (
    SELECT dep_id, COUNT(*) count
    FROM Employees
    GROUP BY dep_id
), LargestDepartments AS (
    SELECT *
    FROM Departments
    WHERE count = (SELECT MAX(count) FROM Departments)
)
SELECT emp_name manager_name, dep_id
FROM Employees JOIN LargestDepartments USING(dep_id)
WHERE position = "Manager"
ORDER BY dep_id;