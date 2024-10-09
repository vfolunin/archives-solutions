WITH ConcurrentTasks AS (
    SELECT
        a.employee_id, 
        SUM(IF(
            a.task_id = b.task_id,
            TIMESTAMPDIFF(MINUTE, a.start_time, a.end_time),
            TIMESTAMPDIFF(MINUTE, a.end_time, b.start_time)
        )) task_hours, 
        COUNT(b.task_id) concurrent_tasks
    FROM Tasks a JOIN Tasks b ON a.employee_id = b.employee_id AND a.start_time <= b.start_time AND b.start_time < a.end_time
    GROUP BY a.employee_id, a.task_id
)
SELECT employee_id, SUM(task_hours) DIV 60 total_task_hours, MAX(concurrent_tasks) max_concurrent_tasks
FROM ConcurrentTasks
GROUP BY employee_id
ORDER BY employee_id;