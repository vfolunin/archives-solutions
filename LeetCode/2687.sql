SELECT bike_number, MAX(end_time) end_time
FROM Bikes
GROUP BY bike_number;