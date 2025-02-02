SELECT * 
FROM Users
WHERE email REGEXP '^[0-9A-Za-z]+@[A-Za-z]+\.com$'
ORDER BY user_id;