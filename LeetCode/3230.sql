WITH Stats AS (
    SELECT
        customer_id,
        SUM(amount) total_amount,
        COUNT(transaction_id) transaction_count, 
        COUNT(DISTINCT category) unique_categories,
        ROUND(AVG(amount), 2) avg_transaction_amount, 
        ROUND(COUNT(transaction_id) * 10 + SUM(amount) / 100, 2) loyalty_score
    FROM Transactions JOIN Products USING(product_id)
    GROUP BY customer_id
), IndexedCategories AS (
    SELECT
        customer_id,
        category,
        RANK() OVER(PARTITION BY customer_id ORDER BY COUNT(transaction_id) DESC, MAX(transaction_date) DESC) i
    FROM Transactions JOIN Products USING(product_id)
    GROUP BY customer_id, category
)
SELECT customer_id, total_amount, transaction_count, unique_categories, avg_transaction_amount, category top_category, loyalty_score
FROM Stats JOIN IndexedCategories USING(customer_id)
WHERE i = 1
ORDER BY loyalty_score DESC, customer_id;