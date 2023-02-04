SELECT LOWER(TRIM(product_name)) product_name, LEFT(sale_date, 7) sale_date, COUNT(*) total
FROM Sales
GROUP BY LOWER(TRIM(product_name)), LEFT(sale_date, 7)
ORDER BY product_name, sale_date;