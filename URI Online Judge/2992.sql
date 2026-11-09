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
        lotacao_div,
        COALESCE(total_earning, 0) - COALESCE(total_discount, 0) net_salary
    FROM empregado
    LEFT JOIN earnings USING(matr)
    LEFT JOIN discounts USING(matr)
), division_salary AS (
    SELECT
        divisao.cod_dep,
        divisao.cod_divisao,
        divisao.nome,
        COALESCE(AVG(net_salary), 0) average_salary
    FROM
        divisao
        LEFT JOIN employee_salary ON lotacao_div = cod_divisao
    GROUP BY divisao.cod_dep, divisao.cod_divisao, divisao.nome
), ranked_divisions AS (
    SELECT
        division_salary.*,
        RANK() OVER (PARTITION BY cod_dep ORDER BY average_salary DESC) salary_rank
    FROM division_salary
)
SELECT
    departamento.nome departamento,
    ranked_divisions.nome divisao,
    ROUND(average_salary, 2) media
FROM
    departamento
    JOIN ranked_divisions USING(cod_dep)
WHERE salary_rank = 1
ORDER BY average_salary DESC;