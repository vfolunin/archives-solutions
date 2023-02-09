SELECT a.log_id start_id, b.log_id end_id
FROM Logs a JOIN Logs b ON a.log_id <= b.log_id
WHERE
    a.log_id - 1 NOT IN (
        SELECT log_id
        FROM Logs
    ) AND b.log_id + 1 NOT IN (
        SELECT log_id
        FROM Logs
    )
GROUP BY a.log_id;