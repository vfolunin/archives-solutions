SELECT a.score, COUNT(DISTINCT b.score) `rank`
FROM Scores a JOIN Scores b ON a.score <= b.score
GROUP BY a.id
ORDER BY a.score DESC;