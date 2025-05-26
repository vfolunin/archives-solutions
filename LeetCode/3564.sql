WITH SeasonSales AS (
    SELECT
        CASE
            WHEN MONTH(sale_date) BETWEEN 3 AND 5 THEN 'Spring'
            WHEN MONTH(sale_date) BETWEEN 6 AND 8 THEN 'Summer'
            WHEN MONTH(sale_date) BETWEEN 9 AND 11 THEN 'Fall'
            ELSE 'Winter'
        END season, category, SUM(quantity) total_quantity, SUM(quantity * price) total_revenue
    FROM Sales JOIN Products USING(product_id)
    GROUP BY season, category
), RankedSeasonSales AS (
    SELECT *, RANK() OVER (PARTITION BY season ORDER BY total_quantity DESC, total_revenue DESC) i
    FROM SeasonSales
)
SELECT season, category, total_quantity, total_revenue
FROM RankedSeasonSales
WHERE i = 1
ORDER BY season;
