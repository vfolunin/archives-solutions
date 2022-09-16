SELECT d.Name Department, e1.Name Employee, e1.Salary
FROM Employee e1 JOIN Department d ON e1.DepartmentId = d.Id
WHERE (
    SELECT COUNT(DISTINCT e2.Salary)
    FROM Employee e2
    WHERE e1.Salary < e2.Salary AND e1.DepartmentId = e2.DepartmentId
) < 3;