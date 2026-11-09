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
        lotacao,
        matr,
        COALESCE(total_earning, 0) - COALESCE(total_discount, 0) net_salary
    FROM empregado
    LEFT JOIN earnings USING(matr)
    LEFT JOIN discounts USING(matr)
)
SELECT
    departamento.nome "Nome Departamento",
    COUNT(employee_salary.matr) "Numero de Empregados",
    ROUND(COALESCE(AVG(net_salary), 0), 2) "Media Salarial",
    COALESCE(MAX(net_salary), 0) "Maior Salario",
    COALESCE(MIN(net_salary), 0) "Menor Salario"
FROM
    departamento
    LEFT JOIN employee_salary ON lotacao = cod_dep
GROUP BY departamento.cod_dep, departamento.nome
ORDER BY COALESCE(AVG(net_salary), 0) DESC;