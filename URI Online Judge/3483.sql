WITH ranked_cities AS (
    SELECT
        city_name,
        population,
        ROW_NUMBER() OVER (ORDER BY population DESC, id) largest_rank,
        ROW_NUMBER() OVER (ORDER BY population, id) smallest_rank
    FROM cities
)
SELECT city_name, population
FROM ranked_cities
WHERE largest_rank = 2 OR smallest_rank = 2
ORDER BY population DESC;