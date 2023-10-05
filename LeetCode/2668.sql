SELECT emp_id, firstname, lastname, MAX(salary) salary, department_id
FROM salary
GROUP BY emp_id
ORDER BY emp_id;