SELECT Request_at Day, ROUND((SUM(status != "completed") / COUNT(*)), 2) "Cancellation Rate"
FROM trips
  JOIN users c ON client_id = c.users_id AND c.banned = "No"
  JOIN users d ON driver_id = d.users_id AND d.banned = "No"
WHERE request_at BETWEEN "2013-10-01" AND "2013-10-03"
GROUP BY request_at;