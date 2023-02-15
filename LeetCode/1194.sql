WITH Ranks AS (
    SELECT 
		group_id,
        player_id, 
		RANK() OVER (PARTITION BY group_id ORDER BY SUM(IF(player_id = first_player, first_score, second_score)) DESC, player_id) r
	FROM Players JOIN Matches ON player_id = first_player OR player_id = second_player
	GROUP BY group_id, player_id
)
SELECT group_id, player_id
FROM Ranks
WHERE r = 1;