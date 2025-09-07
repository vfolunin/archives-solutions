WITH RECURSIVE PassTeams AS (
    SELECT T1.team_name team1, T2.team_name team2, time_stamp
    FROM Passes JOIN Teams T1 ON pass_from = T1.player_id JOIN Teams T2 ON pass_to = T2.player_id    
), IndexedPassTeams AS (
    SELECT team1, team2, RANK() OVER (PARTITION BY team1 ORDER BY time_stamp) i 
    FROM PassTeams
), Streaks AS (
    SELECT
        team1,
        team2,
        i,
        IF(team1 = team2, 1, 0) streak
    FROM IndexedPassTeams
    WHERE i = 1
    UNION
    SELECT
        IndexedPassTeams.team1,
        IndexedPassTeams.team2,
        IndexedPassTeams.i,
        IF(IndexedPassTeams.team1 = IndexedPassTeams.team2, Streaks.streak + 1, 0) streak
    FROM IndexedPassTeams JOIN Streaks ON IndexedPassTeams.i = Streaks.i + 1 AND IndexedPassTeams.team1 = Streaks.team1
)
SELECT team1 team_name, MAX(streak) longest_streak
FROM Streaks
GROUP BY team_name
HAVING longest_streak > 0;