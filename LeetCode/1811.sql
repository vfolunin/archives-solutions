WITH MedalContests AS (
    SELECT user_id, contest_id, LEAD(contest_id, 2) OVER (PARTITION BY user_id ORDER BY contest_id) next_contest_id 
    FROM Users JOIN Contests ON user_id = gold_medal OR user_id = silver_medal OR user_id = bronze_medal
), ConsecutiveWinners AS (
    SELECT user_id
    FROM MedalContests
    GROUP BY user_id
    HAVING SUM(contest_id + 2 = next_contest_id) >= 1
), GoldWinners AS (
    SELECT user_id
    FROM Users JOIN Contests ON user_id = gold_medal
    GROUP BY user_id
    HAVING COUNT(*) >= 3
), Winners AS (
    SELECT *
    FROM ConsecutiveWinners
    UNION
    SELECT *
    FROM GoldWinners
)
SELECT name, mail
FROM Users JOIN Winners USING(user_id);