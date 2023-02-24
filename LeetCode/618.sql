WITH AmericaStudents AS (
    SELECT name America, ROW_NUMBER() OVER () i
    FROM Student
    WHERE continent = "America"
    ORDER BY name
), AsiaStudents AS (
    SELECT name Asia, ROW_NUMBER() OVER () i
    FROM Student
    WHERE continent = "Asia"
    ORDER BY name
), EuropeStudents AS (
    SELECT name Europe, ROW_NUMBER() OVER () i
    FROM Student
    WHERE continent = "Europe"
    ORDER BY name
), AmericaAsiaStudents AS (
    SELECT America, Asia, i
    FROM AmericaStudents LEFT JOIN AsiaStudents USING(i)
    UNION
    SELECT America, Asia, i
    FROM AsiaStudents LEFT JOIN AmericaStudents USING(i)
)
SELECT America, Asia, Europe
FROM AmericaAsiaStudents LEFT JOIN EuropeStudents USING(i)
UNION
SELECT America, Asia, Europe
FROM EuropeStudents LEFT JOIN AmericaAsiaStudents USING(i);