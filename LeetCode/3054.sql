WITH HasChild AS (
    SELECT DISTINCT a.N, true has_child
    FROM Tree a JOIN Tree b ON a.N = b.P
)
SELECT
    N,
    CASE
        WHEN P IS NULL THEN "Root"
        WHEN has_child IS NULL THEN "Leaf"
        ELSE "Inner"
    END Type
FROM Tree LEFT JOIN HasChild USING(N)
ORDER BY N;