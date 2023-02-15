SELECT
    DISTINCT LEFT(pay_date, 7) pay_month,
    department_id,
    CASE
        WHEN AVG(amount) OVER (PARTITION BY pay_date, department_id) < AVG(amount) OVER (PARTITION BY pay_date) THEN "lower"
        WHEN AVG(amount) OVER (PARTITION BY pay_date, department_id) > AVG(amount) OVER (PARTITION BY pay_date) THEN "higher"
        ELSE "same"
    END comparison
FROM Salary JOIN Employee USING(employee_id);