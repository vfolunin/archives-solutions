WITH RECURSIVE IndexedEvents AS (
    SELECT *, ROW_NUMBER() OVER (ORDER BY hall_id, start_day) i
    FROM HallEvents
),
FirstEvent AS (
    SELECT *
    FROM IndexedEvents
    ORDER BY i
    LIMIT 1
),
MergedEvents AS (
    SELECT *
    FROM FirstEvent
    UNION ALL
    SELECT
        b.hall_id,
        IF(a.hall_id = b.hall_id AND b.start_day <= a.end_day, a.start_day, b.start_day) start_day,
        IF(a.hall_id = b.hall_id AND b.end_day <= a.end_day, a.end_day, b.end_day) end_day,
        b.i
    FROM MergedEvents a JOIN IndexedEvents b ON a.i + 1 = b.i
    WHERE b.i < 1000
)
SELECT hall_id, start_day, MAX(end_day) end_day
FROM MergedEvents
GROUP BY hall_id, start_day;