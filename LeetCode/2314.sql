WITH MaxDegree AS (
    SELECT city_id, MAX(degree) degree
    FROM Weather
    GROUP BY city_id
)
SELECT city_id, MIN(day) day, degree
FROM Weather JOIN MaxDegree USING(city_id, degree)
GROUP BY city_id
ORDER BY city_id;