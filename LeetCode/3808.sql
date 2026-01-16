WITH reaction_counts AS (
    SELECT
        user_id,
        reaction dominant_reaction,
        COUNT(*) OVER (PARTITION BY user_id) total_reaction, 
        COUNT(*) OVER (PARTITION BY user_id, reaction) current_reaction
    FROM reactions
)
SELECT DISTINCT user_id, dominant_reaction, ROUND(current_reaction / total_reaction, 2) reaction_ratio
FROM reaction_counts
WHERE total_reaction >= 5
HAVING reaction_ratio >= 0.6
ORDER BY reaction_ratio DESC, user_id;