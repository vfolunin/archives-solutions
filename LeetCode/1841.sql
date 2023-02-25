WITH MatchResults AS (
    SELECT
        *,
        CASE
            WHEN home_team_goals > away_team_goals THEN 3
            WHEN home_team_goals = away_team_goals THEN 1
            ELSE 0
        END home_points,
        CASE
            WHEN away_team_goals > home_team_goals THEN 3
            WHEN away_team_goals = home_team_goals THEN 1
            ELSE 0
        END away_points
    FROM Matches
), TeamResults AS (
    SELECT home_team_id team_id, home_points points, home_team_goals goal_for, away_team_goals goal_against
    FROM MatchResults
    UNION ALL
    SELECT away_team_id team_id, away_points points, away_team_goals goal_for, home_team_goals goal_against
    FROM MatchResults
)
SELECT
    team_name,
    COUNT(*) matches_played,
    SUM(points) points,
    SUM(goal_for) goal_for,
    SUM(goal_against) goal_against,
    SUM(goal_for) - SUM(goal_against) goal_diff
FROM Teams JOIN TeamResults USING(team_id)
GROUP BY team_name
ORDER BY points DESC, goal_diff DESC, team_name;