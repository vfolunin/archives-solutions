WITH TeamWorkload AS (
    SELECT team, AVG(workload) average_workload
    FROM Project JOIN Employees USING(employee_id)
    GROUP BY team
), EmployeeWorkload AS (
    SELECT project_id, employee_id, workload project_workload, name employee_name, team
    FROM Project JOIN Employees USING(employee_id)
)
SELECT employee_id, project_id, employee_name, project_workload
FROM EmployeeWorkload JOIN TeamWorkload TAW USING(team)
WHERE project_workload > average_workload
ORDER BY employee_id, project_id;