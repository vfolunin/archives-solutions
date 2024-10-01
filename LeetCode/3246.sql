SELECT
    team_id,
    team_name,
    SUM(wins * 3 + draws) points,
    RANK() OVER (ORDER BY SUM(wins * 3 + draws) DESC) position
FROM TeamStats
GROUP BY team_id, team_name
ORDER BY points DESC, team_name