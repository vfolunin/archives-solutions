WITH Players AS (
    SELECT *, ROW_NUMBER() OVER (PARTITION BY player_id ORDER BY match_day) i
    FROM Matches
), Streaks AS (
    SELECT player_id, i - ROW_NUMBER() OVER (PARTITION BY player_id ORDER BY match_day) streak_id
    FROM Players
    WHERE result = 'Win'
), StreaksSizes AS (
    SELECT player_id, streak_id, COUNT(*) streak_size
    FROM Streaks
    GROUP BY player_id, streak_id
)
SELECT DISTINCT player_id, IFNULL(MAX(streak_size), 0) longest_streak
FROM Matches LEFT JOIN StreaksSizes USING(player_id)
GROUP BY player_id;