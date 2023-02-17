SELECT employee_id
FROM Employees LEFT JOIN Logs USING(employee_id)
GROUP BY employee_id
HAVING IFNULL(SUM(CEIL(TIMESTAMPDIFF(SECOND, in_time, out_time) / 60) / 60), 0) < MAX(needed_hours);