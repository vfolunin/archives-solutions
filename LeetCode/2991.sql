WITH WineriesPoints AS (
    SELECT country, winery, SUM(points) total_points
    FROM Wineries
    GROUP BY country, winery
), SortedWineries AS (
    SELECT
        country,
        CONCAT(winery, " (", total_points, ")") winery,
        RANK() OVER (PARTITION BY country ORDER BY total_points DESC, winery) i
    FROM WineriesPoints
)
SELECT
    country,
    IFNULL(MAX(CASE WHEN i = 1 THEN winery END), "No top winery") top_winery,
    IFNULL(MAX(CASE WHEN i = 2 THEN winery END), "No second winery") second_winery,
    IFNULL(MAX(CASE WHEN i = 3 THEN winery END), "No third winery") third_winery
FROM SortedWineries
GROUP BY country
ORDER BY country;