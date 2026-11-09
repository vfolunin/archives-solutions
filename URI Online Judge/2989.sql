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
        matr,
        COALESCE(total_earning, 0) - COALESCE(total_discount, 0) net_salary
    FROM
        empregado
        LEFT JOIN earnings USING(matr)
        LEFT JOIN discounts USING(matr)
)
SELECT
    departamento.nome departamento,
    divisao.nome divisao,
    ROUND(COALESCE(AVG(net_salary), 0), 2) media,
    ROUND(COALESCE(MAX(net_salary), 0), 2) maior
FROM
    departamento
    JOIN divisao USING(cod_dep)
    LEFT JOIN employee_salary ON lotacao_div = cod_divisao
GROUP BY departamento.nome, divisao.nome
ORDER BY media DESC;