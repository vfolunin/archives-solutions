SELECT a.employee_id, COUNT(*) team_size
FROM Employee a JOIN Employee b USING(team_id)
GROUP BY a.employee_id;