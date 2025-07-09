WITH employeeMeetingHours AS (
    SELECT employee_id, SUM(duration_hours) meeting_hours
    FROM meetings
    GROUP BY employee_id, WEEKOFYEAR(meeting_date), YEAR(meeting_date)
)
SELECT employee_id, employee_name, department, COUNT(employee_id) meeting_heavy_weeks 
FROM employees JOIN employeeMeetingHours USING(employee_id)
WHERE meeting_hours > 20
GROUP BY employee_id, employee_name, department
HAVING COUNT(employee_id) > 1
ORDER BY meeting_heavy_weeks DESC, employee_name;