SELECT candidate_id
FROM Candidates
GROUP BY candidate_id
HAVING SUM(skill IN ("Python", "Tableau", "PostgreSQL")) = 3
ORDER BY candidate_id;