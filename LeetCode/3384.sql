SELECT a.team_name, IF(time_stamp <= "45:00", 1, 2) half_number, SUM(IF(a.team_name = b.team_name, 1, -1)) dominance
FROM Passes JOIN Teams a ON pass_from = a.player_id JOIN Teams b ON pass_to = b.player_id
GROUP BY a.team_name, half_number
ORDER BY a.team_name, half_number;