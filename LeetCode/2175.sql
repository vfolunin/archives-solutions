SELECT
    team_id,
    name,
    CAST(ROW_NUMBER() OVER (ORDER BY points DESC, name) AS SIGNED) -
    CAST(ROW_NUMBER() OVER (ORDER BY points + points_change DESC, name) AS SIGNED) rank_diff
FROM TeamPoints a JOIN PointsChange b USING(team_id);