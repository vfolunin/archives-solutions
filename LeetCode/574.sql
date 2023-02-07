SELECT c.name
FROM Candidate c JOIN Vote v ON c.id = v.candidateId
GROUP BY c.id
ORDER BY COUNT(v.id) DESC
LIMIT 1;