WITH FirstYears AS (
    SELECT product_id, MIN(year) year
    FROM Sales
    GROUP BY product_id
)
SELECT product_id, year first_year, quantity, price
FROM Sales JOIN FirstYears USING(product_id, year);