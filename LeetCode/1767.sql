WITH RECURSIVE Subtasks AS (
    SELECT 1 AS subtask_id
    UNION ALL
    SELECT subtask_id + 1 subtask_id
    FROM Subtasks
    WHERE subtask_id <= 20
)
SELECT task_id, subtask_id
FROM Tasks JOIN Subtasks ON subtask_id <= subtasks_count LEFT JOIN Executed USING(task_id, subtask_id)
WHERE Executed.subtask_id IS NULL;