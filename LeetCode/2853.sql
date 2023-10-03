SELECT ABS((
    SELECT MAX(salary)
    FROM Salaries
    WHERE department = "Engineering"
) - (
    SELECT MAX(salary)
    FROM Salaries
    WHERE department = "Marketing"
)) salary_difference;