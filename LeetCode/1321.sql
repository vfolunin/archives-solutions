WITH Visits AS (
    SELECT visited_on, SUM(amount) amount
    FROM Customer
    GROUP BY visited_on
)
SELECT
    b.visited_on,
    ROUND(SUM(a.amount), 2) amount,
    ROUND(AVG(a.amount), 2) average_amount
FROM Visits a JOIN Visits b on DATEDIFF(b.visited_on, a.visited_on) BETWEEN 0 AND 6
GROUP BY b.visited_on
HAVING COUNT(DISTINCT a.visited_on) = 7
ORDER BY b.visited_on;