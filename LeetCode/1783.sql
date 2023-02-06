SELECT
    player_id,
    player_name,
    SUM(player_id = Wimbledon) + SUM(player_id = Fr_open) + SUM(player_id = US_open) + SUM(player_id = Au_open) grand_slams_count
FROM Players, Championships
GROUP BY player_id
HAVING grand_slams_count > 0;
