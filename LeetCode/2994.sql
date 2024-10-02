WITH RECURSIVE Dates AS (
    SELECT "2023-11-03" purchase_date
    UNION ALL
    SELECT DATE_ADD(purchase_date, INTERVAL 1 DAY) purchase_date
    FROM Dates
    WHERE purchase_date < "2023-11-30"
)
SELECT
	WEEK(purchase_date) - WEEK("2023-11-01") + 1 week_of_month,
	purchase_date,
	IFNULL(SUM(amount_spend), 0) total_amount
FROM Dates LEFT JOIN Purchases USING(purchase_date)
WHERE DAYOFWEEK(purchase_date) = 6
GROUP BY purchase_date
ORDER BY week_of_month;