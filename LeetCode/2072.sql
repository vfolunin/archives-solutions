SELECT
    CASE
        WHEN a > b THEN "New York University"
        WHEN a < b THEN "California University"
        ELSE "No Winner"
    END winner
FROM (
    SELECT COUNT(student_id) a
    FROM NewYork
    WHERE score >= 90
) a, (
    SELECT COUNT(student_id) b
    FROM California
    WHERE score >= 90
) b;