(
    SELECT name AS results
    FROM MovieRating JOIN Users USING(user_id)
    GROUP BY user_id
    ORDER BY COUNT(movie_id) DESC, name 
    LIMIT 1
)
UNION ALL
(
    SELECT title AS results
    FROM MovieRating JOIN Movies USING(movie_id)
    WHERE DATE("2020-02-01") <= created_at AND created_at < DATE("2020-03-01")
    GROUP BY movie_id
    ORDER BY AVG(rating) DESC, title
    LIMIT 1
);