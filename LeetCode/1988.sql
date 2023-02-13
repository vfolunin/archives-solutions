SELECT school_id, IFNULL(MIN(score), -1) score
FROM Schools LEFT JOIN Exam ON capacity >= student_count
GROUP BY school_id;