SELECT student_id, student_name, subject_name, COUNT(e.student_id) attended_exams
FROM Students FULL JOIN Subjects LEFT JOIN Examinations e USING(student_id, subject_name)
GROUP BY student_id, subject_name
ORDER BY student_id, subject_name;