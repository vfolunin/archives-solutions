WITH cycles AS (
    SELECT student_id, COUNT(DISTINCT subject) cycle_length, SUM(hours_studied) total_study_hours
    FROM study_sessions
    GROUP BY student_id
    HAVING COUNT(DISTINCT subject) >= 3
), indexed_cycles AS (
    SELECT
        student_id,
        cycle_length,
        total_study_hours,
        subject,
        session_date,
        DATEDIFF(LEAD(session_date, 1, session_date) OVER (PARTITION BY student_id ORDER BY session_date), session_date) gap,
        ROW_NUMBER() OVER (PARTITION BY student_id ORDER BY session_date) i
    FROM cycles JOIN study_sessions USING(student_id)
), spiral_students AS (
    SELECT a.student_id, a.cycle_length, a.total_study_hours
    FROM indexed_cycles a JOIN indexed_cycles b ON a.student_id = b.student_id AND a.subject = b.subject AND a.i + a.cycle_length = b.i
    WHERE a.gap <= 2 AND b.gap <= 2
    GROUP BY a.student_id, a.cycle_length, a.total_study_hours
    HAVING COUNT(DISTINCT a.subject) >= 3
)
SELECT student_id, student_name, major, cycle_length, total_study_hours
FROM students JOIN spiral_students USING(student_id)
ORDER BY cycle_length DESC, total_study_hours DESC;