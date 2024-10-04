WITH IndexedCoordinates AS (
    SELECT *, ROW_NUMBER() OVER (ORDER BY X) i
    FROM Coordinates
)
SELECT DISTINCT(a.x) x, a.y y
FROM IndexedCoordinates a JOIN IndexedCoordinates b ON a.x = b.y AND b.x = a.y AND a.i != b.i
WHERE a.x <= a.y
ORDER BY x, y;