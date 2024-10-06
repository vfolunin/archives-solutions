SELECT a.employee_id, COUNT(*) overlapping_shifts
FROM EmployeeShifts a JOIN EmployeeShifts b ON a.employee_id = b.employee_id AND a.start_time < b.start_time AND b.start_time < a.end_time
GROUP BY a.employee_id
ORDER BY employee_id;