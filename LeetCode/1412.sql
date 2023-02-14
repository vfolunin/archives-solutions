WITH Scores AS (
    SELECT exam_id, MIN(score) min_score, MAX(score) max_score
    FROM Exam
    GROUP BY exam_id
)
SELECT student_id, student_name
FROM Student JOIN Exam e USING(student_id) JOIN Scores USING(exam_id)
GROUP BY student_id
HAVING SUM(score = max_score) = 0 AND SUM(score = min_score) = 0
ORDER BY student_id;