SELECT activity 
FROM Friends
GROUP BY activity
HAVING COUNT(*) NOT IN (
    (
        SELECT COUNT(*)
        FROM Friends
        GROUP BY activity
        ORDER BY COUNT(*)
        LIMIT 1
    ), (       
        SELECT COUNT(*)
        FROM Friends
        GROUP BY activity
        ORDER BY COUNT(*) DESC
        LIMIT 1
    )
);