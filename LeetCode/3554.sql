WITH Products AS (
	SELECT user_id, category
	FROM ProductPurchases JOIN ProductInfo USING(product_id)
), ReportablePairs AS (
	SELECT A.category category1, B.category category2, COUNT(DISTINCT A.user_id) customer_count 
	FROM Products A JOIN Products B ON A.category < B.category AND A.user_id = B.user_id
	GROUP BY A.category, B.category
	HAVING(COUNT(DISTINCT A.user_id)) > 2
)
SELECT category1, category2, customer_count
FROM ReportablePairs
ORDER BY customer_count DESC, category1, category2