SELECT b.person_name
FROM Queue a JOIN Queue b ON a.turn <= b.turn
GROUP BY b.turn
HAVING SUM(a.weight) <= 1000
ORDER BY SUM(a.weight) DESC
LIMIT 1;