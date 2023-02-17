WITH Drinks AS (
    SELECT *, ROW_NUMBER() OVER () i
    FROM CoffeeShop
), Pairs AS (
    SELECT b.id, a.drink, a.i
    FROM Drinks a JOIN Drinks b ON a.i <= b.i
    WHERE a.drink IS NOT NULL
)
SELECT id, drink
FROM Pairs
GROUP BY id;