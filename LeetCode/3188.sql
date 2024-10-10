WITH MandatoryCourses AS (
    SELECT course_id, major
    FROM courses
    WHERE mandatory = "Yes"
), ElectiveCourses AS (
    SELECT course_id, major
    FROM courses
    WHERE mandatory = "No"
), MandatoryPassed AS (
    SELECT student_id
    FROM enrollments JOIN MandatoryCourses USING(course_id) JOIN students USING(student_id, major)
    WHERE grade = "A"
    GROUP BY student_id, students.major
    HAVING COUNT(DISTINCT course_id) = (SELECT COUNT(*) FROM MandatoryCourses WHERE major = students.major)
), ElectivePassed AS (
    SELECT student_id
    FROM enrollments JOIN ElectiveCourses USING(course_id) JOIN students USING(student_id, major)
    WHERE grade = "A" OR grade = "B"
    GROUP BY student_id
    HAVING COUNT(DISTINCT course_id) >= 2
), GpaPassed AS (
    SELECT student_id
    FROM enrollments
    GROUP BY student_id
    HAVING AVG(GPA) >= 2.5
)
SELECT DISTINCT student_id
FROM MandatoryPassed JOIN ElectivePassed USING(student_id) JOIN GpaPassed USING(student_id)
ORDER BY student_id;