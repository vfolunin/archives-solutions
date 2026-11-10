WITH city_statistics AS (
    SELECT
        nome_cidade,
        regiao,
        COUNT(DISTINCT ponto_id) qtd_pontos,
        AVG(nota::numeric) average_rating
    FROM Cidades JOIN PontosTuristicos USING(cidade_id) LEFT JOIN Avaliacoes USING(ponto_id)
    GROUP BY cidade_id, nome_cidade, regiao
    HAVING COUNT(DISTINCT ponto_id) >= 2
)
SELECT
    nome_cidade,
    regiao,
    qtd_pontos,
    ROUND(average_rating, 2) media_avaliacoes,
    RANK() OVER (PARTITION BY regiao ORDER BY average_rating DESC NULLS LAST) ranking_regional
FROM city_statistics
ORDER BY regiao, ranking_regional;