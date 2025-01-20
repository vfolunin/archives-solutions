WITH Segments AS (
    SELECT student_id, subject, MIN(exam_date) l, MAX(exam_date) r
    FROM Scores
    GROUP BY student_id, subject
), SegmentScores AS (
    SELECT Segments.student_id, Segments.subject, lScore.score first_score, rScore.score latest_score
    FROM
        Segments
        JOIN Scores lScore ON Segments.student_id = lScore.student_id AND Segments.subject = lScore.subject AND Segments.l = lScore.exam_date
        JOIN Scores rScore ON Segments.student_id = rScore.student_id AND Segments.subject = rScore.subject AND Segments.r = rScore.exam_date AND lScore.exam_date != rScore.exam_date
)
SELECT student_id, subject, first_score, latest_score
FROM SegmentScores
WHERE first_score < latest_score
ORDER BY student_id, subject;