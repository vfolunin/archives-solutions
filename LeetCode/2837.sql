SELECT user_id, name, IFNULL(SUM(distance), 0) "traveled distance"
FROM Users LEFT JOIN Rides USING(user_id)
GROUP BY user_id
ORDER BY user_id;