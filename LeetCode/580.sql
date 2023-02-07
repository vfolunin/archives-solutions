SELECT dept_name, COUNT(student_id) student_number
FROM Department LEFT JOIN Student USING(dept_id)
GROUP BY dept_id
ORDER BY student_number DESC, dept_name;