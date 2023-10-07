WITH StepsPairs AS (
    SELECT a.user_id, a.steps_date, b.steps_count
    FROM Steps a LEFT JOIN Steps b ON a.user_id = b.user_id AND DATEDIFF(a.steps_date, b.steps_date) BETWEEN 0 AND 2
),
CumulativeSteps AS (
    SELECT user_id, steps_date, SUM(steps_count) steps_count, COUNT(*) day_count
    FROM StepsPairs
    GROUP BY user_id, steps_date
)
SELECT user_id, steps_date, ROUND(steps_count / day_count, 2) rolling_average
FROM CumulativeSteps
WHERE day_count = 3
ORDER BY user_id, steps_date;