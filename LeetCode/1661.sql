SELECT s.machine_id, ROUND(AVG(e.timestamp - s.timestamp), 3) processing_time
FROM Activity s JOIN Activity e ON s.machine_id = e.machine_id AND s.process_id = e.process_id AND s.timestamp < e.timestamp
GROUP BY s.machine_id;