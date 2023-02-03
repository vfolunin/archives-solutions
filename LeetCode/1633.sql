SELECT
    contest_id,
    ROUND(COUNT(*) / user_count * 100, 2) percentage
FROM
    Register,
    (
        SELECT COUNT(*) user_count
        FROM Users
    ) user_count
GROUP BY contest_id
ORDER BY percentage DESC, contest_id;