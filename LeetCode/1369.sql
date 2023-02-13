SELECT * 
FROM UserActivity 
GROUP BY username 
HAVING COUNT(*) = 1

UNION ALL

SELECT a.username, a.activity, a.startDate, a.endDate
FROM UserActivity a JOIN UserActivity b ON a.username = b.username AND a.endDate < b.endDate
GROUP BY a.username, a.endDate
HAVING COUNT(b.endDate) = 1;