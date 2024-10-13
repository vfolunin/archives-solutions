WITH Stats AS (
    SELECT
        season_id,
        team_id,
        team_name,
        (wins * 3) + draws points,
        goals_for - goals_against goal_difference
    FROM SeasonStats
)
SELECT *, RANK() OVER (PARTITION BY season_id ORDER BY points DESC, goal_difference DESC, team_name) position
FROM Stats
ORDER BY season_id, position, team_name;