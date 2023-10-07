WITH VoterWeight AS (
    SELECT voter, COUNT(*) weight
    FROM Votes
    GROUP BY voter
), CandidateWeight AS (
    SELECT candidate, SUM(1.0 / weight) weight
    FROM Votes a, VoterWeight b
    WHERE a.voter = b.voter AND candidate IS NOT NULL
    GROUP BY candidate
), MaxWeight AS (
    SELECT MAX(weight) maxWeight
    FROM CandidateWeight
)
SELECT candidate
FROM CandidateWeight, MaxWeight
WHERE weight = maxWeight
ORDER BY candidate;