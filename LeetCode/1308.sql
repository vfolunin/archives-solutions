SELECT a.gender, a.day, SUM(b.score_points) total
FROM Scores a JOIN Scores b ON a.gender = b.gender AND a.day >= b.day
GROUP BY a.gender, a.day
ORDER BY a.gender, a.day;