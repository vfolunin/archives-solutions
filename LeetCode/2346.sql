SELECT student_id, department_id, ROUND(PERCENT_RANK() OVER (PARTITION BY department_id ORDER BY mark DESC) * 100, 2) percentage 
FROM Students;