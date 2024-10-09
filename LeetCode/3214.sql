WITH Spends AS (
    SELECT product_id, SUM(spend) spend, YEAR(transaction_date) year
    FROM user_transactions
    GROUP BY product_id, YEAR(transaction_date)
)
SELECT
    a.year,
    a.product_id,
    a.spend curr_year_spend,
    b.spend prev_year_spend,
    ROUND((a.spend - b.spend) * 100.0 / b.spend, 2) yoy_rate 
FROM Spends a LEFT JOIN Spends b ON a.product_id = b.product_id AND a.year = b.year + 1
ORDER BY product_id, year;