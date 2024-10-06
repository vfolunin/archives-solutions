WITH Weeks AS (
    SELECT 1 week_of_month
    UNION
    SELECT 2
    UNION
    SELECT 3
    UNION
    SELECT 4
), Memberships AS (
    SELECT "Premium" membership
    UNION
    SELECT "VIP"
), Types AS (
    SELECT *
    FROM Weeks JOIN Memberships
), Spends AS (
    SELECT amount_spend, membership, (DAY(purchase_date) - 1) DIV 7 + 1 week_of_month
    FROM Purchases JOIN Users USING(user_id)
    WHERE DAYOFWEEK(purchase_date) = 6
)
SELECT week_of_month, membership, IFNULL(SUM(amount_spend), 0) total_amount
FROM Types LEFT JOIN Spends USING(week_of_month, membership)
GROUP BY week_of_month, membership
ORDER BY week_of_month, membership;