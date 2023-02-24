WITH Dates AS (
    SELECT DISTINCT spend_date
    FROM Spending
), DesktopUsers AS (
    SELECT user_id, spend_date, SUM(amount) amount
    FROM Spending
    GROUP BY user_id, spend_date
    HAVING COUNT(DISTINCT platform) = 1 AND MIN(platform) = "desktop"
), MobileUsers AS (
    SELECT user_id, spend_date, SUM(amount) amount
    FROM Spending
    GROUP BY user_id, spend_date
    HAVING COUNT(DISTINCT platform) = 1 AND MIN(platform) = "mobile"
), BothUsers AS (
    SELECT user_id, spend_date, SUM(amount) amount
    FROM Spending
    GROUP BY user_id, spend_date
    HAVING COUNT(DISTINCT platform) = 2
)
SELECT spend_date, "desktop" platform, IFNULL(SUM(amount), 0) total_amount, IFNULL(COUNT(user_id), 0) total_users
FROM Dates LEFT JOIN DesktopUsers USING(spend_date)
GROUP BY spend_date
UNION ALL
SELECT spend_date, "mobile" platform, IFNULL(SUM(amount), 0) total_amount, IFNULL(COUNT(user_id), 0) total_users
FROM Dates LEFT JOIN MobileUsers USING(spend_date)
GROUP BY spend_date
UNION ALL
SELECT spend_date, "both" platform, IFNULL(SUM(amount), 0) total_amount, IFNULL(COUNT(user_id), 0) total_users
FROM Dates LEFT JOIN BothUsers USING(spend_date)
GROUP BY spend_date;