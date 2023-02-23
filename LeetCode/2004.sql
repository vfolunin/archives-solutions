WITH Employees AS (
    SELECT *, SUM(salary) OVER (PARTITION BY experience ORDER BY salary) salary_sum
    FROM Candidates
), Seniors AS (
    SELECT employee_id, salary_sum
    FROM Employees
    WHERE experience = "Senior" AND salary_sum <= 70000
), Juniors AS (
    SELECT employee_id
    FROM Employees
    WHERE experience = "Junior" AND (
        SELECT IFNULL(MAX(salary_sum), 0)
        FROM Seniors
    ) + salary_sum <= 70000
)
SELECT "Senior" experience, COUNT(*) accepted_candidates
FROM Seniors
UNION ALL
SELECT "Junior" experience, COUNT(*) accepted_candidates
FROM Juniors;