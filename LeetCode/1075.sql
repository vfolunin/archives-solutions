SELECT project_id, ROUND(AVG(experience_years), 2) average_years
FROM Project JOIN Employee USING(employee_id)
GROUP BY project_id;