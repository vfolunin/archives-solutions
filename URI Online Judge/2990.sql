SELECT e.cpf, e.enome, d.dnome
FROM empregados AS e
JOIN departamentos AS d ON e.dnumero = d.dnumero
LEFT JOIN trabalha AS t ON e.cpf = t.cpf_emp
WHERE t.pnumero IS NULL
ORDER BY e.cpf;