WITH Years AS (
    SELECT "2018" report_year
    UNION ALL
    SELECT "2019" report_year
    UNION ALL
    SELECT "2020" report_year
)
SELECT
    product_id,
    product_name,
    report_year,
    average_daily_sales * (1 + DATEDIFF(
        LEAST(period_end, CONCAT(report_year, "-12-31")),
        GREATEST(period_start, CONCAT(report_year, "-01-01"))
    )) total_amount
FROM Sales JOIN product USING(product_id) JOIN Years ON report_year BETWEEN YEAR(period_start) AND YEAR(period_end)
ORDER BY product_id, report_year;