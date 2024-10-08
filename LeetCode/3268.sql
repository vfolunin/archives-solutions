WITH Times AS (
    SELECT DISTINCT employee_id, start_time time
    FROM EmployeeShifts
    UNION
    SELECT DISTINCT employee_id, end_time time
    FROM EmployeeShifts
), Segments AS (
    SELECT
        employee_id,
        time start_time,
        LEAD(time) OVER (PARTITION BY employee_id ORDER BY time) end_time
    FROM Times
), SegmentCount AS (
    SELECT Segments.employee_id, Segments.start_time, Segments.end_time, COUNT(*) concurrent_count
    FROM Segments JOIN EmployeeShifts USING(employee_id)
    WHERE EmployeeShifts.start_time <= Segments.start_time AND Segments.end_time <= EmployeeShifts.end_time
    GROUP BY Segments.employee_id, Segments.start_time, Segments.end_time
)
SELECT
    employee_id,
    MAX(concurrent_count) max_overlapping_shifts,
    SUM(concurrent_count * (concurrent_count - 1) / 2 * TIMESTAMPDIFF(MINUTE, start_time, end_time)) total_overlap_duration
FROM SegmentCount
GROUP BY employee_id
ORDER BY employee_id;