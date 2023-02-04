SELECT extra report_reason, COUNT(DISTINCT post_id) report_count
FROM Actions
WHERE extra != "null" AND action = "report" AND action_date = "2019-07-04"
GROUP BY report_reason;