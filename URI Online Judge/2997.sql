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
        empregado.matr,
        empregado.nome,
        empregado.lotacao,
        COALESCE(total_earning, 0) gross_salary,
        COALESCE(total_discount, 0) total_discount,
        COALESCE(total_earning, 0) - COALESCE(total_discount, 0) net_salary
    FROM empregado
    LEFT JOIN earnings USING(matr)
    LEFT JOIN discounts USING(matr)
)
SELECT
    departamento.nome "Departamento",
    employee_salary.nome "Empregado",
    gross_salary "Salario Bruto",
    total_discount "Total Desconto",
    net_salary "Salario Liquido"
FROM
    employee_salary
    JOIN departamento ON lotacao = cod_dep
ORDER BY net_salary DESC;