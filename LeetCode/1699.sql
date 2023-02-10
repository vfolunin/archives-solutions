SELECT LEAST(from_id, to_id) person1, GREATEST(from_id, to_id) person2, COUNT(*) call_count, SUM(duration) total_duration
FROM Calls
GROUP BY person1, person2;