SELECT
    company_id,
    employee_id,
    employee_name,
    ROUND(CASE
        WHEN max_salary < 1000 THEN salary
        WHEN max_salary <= 10000 THEN 0.76 * salary
        ELSE 0.51 * salary
    END, 0) salary
FROM Salaries JOIN (
    SELECT company_id, MAX(salary) max_salary
    FROM Salaries
    GROUP BY company_id
) s USING(company_id);