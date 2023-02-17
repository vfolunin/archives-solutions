WITH a AS (
    SELECT first_col, ROW_NUMBER() OVER (ORDER BY first_col) i
    FROM Data
), b AS (
    SELECT second_col, ROW_NUMBER() OVER (ORDER BY second_col DESC) i
    FROM Data
)
SELECT first_col, second_col
FROM a JOIN b USING(i);