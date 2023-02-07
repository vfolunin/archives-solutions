SELECT a.player_id, a.event_date, SUM(b.games_played) games_played_so_far
FROM Activity a LEFT JOIN Activity b ON a.player_id = b.player_id AND a.event_date >= b.event_date
GROUP BY a.player_id, a.event_date;