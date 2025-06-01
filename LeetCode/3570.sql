WITH taken_books AS (
    SELECT l.book_id, title, author, genre, publication_year, total_copies, COUNT(*) current_borrowers
    FROM library_books l JOIN borrowing_records b ON l.book_id = b.book_id AND b.return_date IS NULL
    GROUP BY book_id
    HAVING current_borrowers = total_copies
)
SELECT book_id, title, author, genre, publication_year, current_borrowers
FROM taken_books
ORDER BY current_borrowers DESC, title;