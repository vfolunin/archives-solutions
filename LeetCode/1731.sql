SELECT a.employee_id, a.name, COUNT(b.employee_id) reports_count, ROUND(AVG(b.age), 0) average_age
FROM Employees a JOIN Employees b ON b.reports_to = a.employee_id
GROUP BY a.employee_id
ORDER BY a.employee_id;