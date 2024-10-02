SELECT
	WEEK(purchase_date) - WEEK("2023-11-01") + 1 week_of_month,
	purchase_date,
	SUM(amount_spend) total_amount
FROM Purchases
WHERE DAYOFWEEK(purchase_date) = 6
GROUP BY purchase_date
ORDER BY week_of_month;