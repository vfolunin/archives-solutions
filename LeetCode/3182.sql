SELECT student_id
FROM students JOIN courses USING(major) LEFT JOIN enrollments USING(student_id, course_id)
GROUP BY student_id
HAVING COUNT(courses.course_id) = COUNT(enrollments.course_id) AND MAX(grade) = "A"
ORDER BY student_id;