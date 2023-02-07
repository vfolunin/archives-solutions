SELECT project_id, employee_id
FROM Project JOIN Employee USING(employee_id)
WHERE (project_id, experience_years) IN (
    SELECT project_id, MAX(experience_years)
    FROM Project JOIN Employee USING(employee_id)
    GROUP BY project_id
);