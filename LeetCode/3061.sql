WITH Ls AS (
    SELECT a.id, IFNULL(MAX(b.height), 0) l
    FROM Heights a LEFT JOIN Heights b ON b.id < a.id
    GROUP BY a.id
), Rs AS (
    SELECT a.id, IFNULL(MAX(b.height), 0) r
    FROM Heights a LEFT JOIN Heights b ON a.id < b.id
    GROUP BY a.id
)
SELECT SUM(GREATEST(LEAST(l, r) - height, 0)) total_trapped_water
FROM Heights JOIN Ls USING(id) JOIN Rs USING(id);