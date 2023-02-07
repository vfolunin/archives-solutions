SELECT candidate_id
FROM Candidates JOIN Rounds USING(interview_id)
WHERE years_of_exp >= 2
GROUP BY candidate_id
HAVING SUM(score) > 15;