WITH earnings AS (
    SELECT matr, SUM(valor) total_earning
    FROM emp_venc JOIN vencimento USING(cod_venc)
    GROUP BY matr
), discounts AS (
    SELECT matr, SUM(valor) total_discount
    FROM emp_desc JOIN desconto USING(cod_desc)
    GROUP BY matr
), employee_salary AS (
    SELECT
        nome,
        lotacao_div,
        COALESCE(total_earning, 0) - COALESCE(total_discount, 0) net_salary
    FROM empregado LEFT JOIN earnings USING(matr) LEFT JOIN discounts USING(matr)
), division_average AS (
    SELECT
        employee_salary.*,
        AVG(net_salary) OVER (PARTITION BY lotacao_div) average_salary
    FROM employee_salary
)
SELECT nome, ROUND(net_salary, 2) salario
FROM division_average
WHERE net_salary > average_salary AND net_salary >= 8000
ORDER BY lotacao_div, net_salary DESC;