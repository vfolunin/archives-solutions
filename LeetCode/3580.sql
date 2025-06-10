WITH indexed_reviews AS (
    SELECT employee_id, rating, ROW_NUMBER() OVER (PARTITION BY employee_id ORDER BY review_date DESC) i
    FROM performance_reviews
), last_reviews AS (
    SELECT *
    FROM indexed_reviews
    WHERE i <= 3
), improvements AS (
    SELECT a.employee_id, (b.rating - c.rating) prev_improvement_score, (a.rating - c.rating) improvement_score
    FROM
        last_reviews a
        JOIN last_reviews b ON a.employee_id = b.employee_id AND a.i + 1 = b.i
        JOIN last_reviews c ON a.employee_id = c.employee_id AND b.i + 1 = c.i
)
SELECT employee_id, name, improvement_score
FROM improvements JOIN employees USING(employee_id)
WHERE 0 < prev_improvement_score AND prev_improvement_score < improvement_score
ORDER BY improvement_score DESC, name;