SELECT
    book_id,
    title,
    author,
    genre,
    pages,
    MAX(session_rating) - MIN(session_rating) rating_spread,
    ROUND(SUM(IF(session_rating > 3 OR session_rating < 3, 1, 0)) / COUNT(*), 2) polarization_score
FROM books JOIN reading_sessions USING(book_id)
GROUP BY book_id
HAVING COUNT(*) > 4 AND MIN(session_rating) < 3 AND MAX(session_rating) > 3 AND polarization_score >= 0.6
ORDER BY polarization_score DESC, title DESC