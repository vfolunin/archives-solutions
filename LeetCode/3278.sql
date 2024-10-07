WITH Scores AS (
    SELECT
        project_id,
        candidate_id,
        100 + SUM(CASE 
            WHEN proficiency > importance THEN 10 
            WHEN proficiency < importance THEN -5
            ELSE 0
        END) score,
        COUNT(skill) skills
    FROM Projects JOIN Candidates USING(skill) 
    GROUP BY project_id, candidate_id
), ProjectSkills AS (
    SELECT project_id, COUNT(skill) skills
    FROM projects
    GROUP BY project_id
), GoodCandidates AS (
    SELECT project_id, candidate_id, score 
    FROM Scores JOIN ProjectSkills USING(project_id, skills)
), SortedGoodCandidates AS (
    SELECT *, RANK() OVER (PARTITION BY project_id ORDER BY score DESC, candidate_id) i
    FROM GoodCandidates
)
SELECT project_id, candidate_id, score 
FROM SortedGoodCandidates
WHERE i = 1;