SELECT p.year, s.name sender, r.name receiver
FROM packages p JOIN users s ON p.id_user_sender = s.id JOIN users r ON p.id_user_receiver = r.id
WHERE (p.color = 'blue' OR p.year = 2015) AND s.address <> 'Taiwan' AND r.address <> 'Taiwan'
ORDER BY p.year DESC;