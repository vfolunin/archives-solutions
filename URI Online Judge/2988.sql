SELECT
    name,
    COUNT(teams.id = team_1 OR teams.id = team_2) matches,
    SUM(CASE
        WHEN teams.id = team_1 AND team_1_goals > team_2_goals THEN 1
        WHEN teams.id = team_2 AND team_2_goals > team_1_goals THEN 1
        ELSE 0
    END) victories,
    SUM(CASE
        WHEN teams.id = team_1 AND team_1_goals < team_2_goals THEN 1
        WHEN teams.id = team_2 AND team_2_goals < team_1_goals THEN 1
        ELSE 0
    END) defeats,
    SUM(CASE
        WHEN (teams.id = team_1 OR teams.id = team_2) AND team_1_goals = team_2_goals THEN 1
        ELSE 0
    END) draws,
    SUM(CASE
        WHEN teams.id = team_1 AND team_1_goals > team_2_goals THEN 3
        WHEN teams.id = team_2 AND team_2_goals > team_1_goals THEN 3
        WHEN (teams.id = team_1 OR teams.id = team_2) AND team_1_goals = team_2_goals THEN 1
        ELSE 0
    END) score
FROM teams LEFT JOIN matches ON teams.id = team_1 OR teams.id = team_2
GROUP BY teams.id
ORDER BY score DESC;