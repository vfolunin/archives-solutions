WITH Ranks AS (
    SELECT
        *,
        RANK() OVER (PARTITION BY gender ORDER BY user_id) rank1,
        CASE 
            WHEN gender = "female" THEN 0
            WHEN gender = "other" THEN 1
            ELSE 2
        END rank2
    FROM Genders
)
SELECT user_id, gender
FROM Ranks
ORDER BY rank1, rank2;