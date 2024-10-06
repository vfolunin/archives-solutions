WITH Points AS (
    SELECT *, (wins * 3) + draws points
    FROM TeamStats
), Positions AS ( 
    SELECT *, RANK() OVER (ORDER BY points DESC) position, COUNT(*) OVER () position_count
    FROM Points
)
SELECT
    team_name,
    points,
    position, 
    CASE 
        WHEN position < (position_count / 3) + 1 THEN "Tier 1"
        WHEN position < (position_count * 2 / 3) + 1 THEN "Tier 2"
        ELSE "Tier 3"
    END tier
FROM Positions
ORDER BY points DESC, team_name;