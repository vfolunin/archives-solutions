WITH MaxMonths AS (
    SELECT id, MAX(month) maxMonth 
    FROM Employee 
    GROUP BY id
), OutputEmployee AS (
    SELECT id, month, salary
    FROM Employee JOIN MaxMonths USING(id)
    WHERE month <> maxMonth
)
SELECT a.id, a.month, SUM(b.salary) Salary 
FROM OutputEmployee a LEFT JOIN Employee b ON a.id = b.id AND b.month BETWEEN a.month - 2 AND a.month
GROUP BY id, month 
ORDER BY id, month DESC;