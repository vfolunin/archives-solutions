WITH transition_pairs AS (
    SELECT
        user_id,
        course_name first_course,
        LEAD(course_name) OVER (PARTITION BY user_id ORDER BY completion_date) second_course,
        COUNT(*) OVER (PARTITION BY user_id) completed_count,
        AVG(course_rating * 1.00) OVER (PARTITION BY user_id) average_rating
    FROM course_completions
)
SELECT first_course, second_course, COUNT(*) transition_count
FROM transition_pairs
WHERE second_course IS NOT NULL AND completed_count >= 5 AND average_rating >= 4
GROUP BY first_course, second_course
ORDER BY transition_count DESC, first_course, second_course;