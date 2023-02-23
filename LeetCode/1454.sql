SELECT DISTINCT a.id, name
FROM Logins a JOIN Accounts USING(id) JOIN Logins b ON a.id = b.id AND DATEDIFF(a.login_date, b.login_date) BETWEEN 1 AND 4
GROUP BY a.id, a.login_date
HAVING COUNT(DISTINCT(b.login_date)) = 4;