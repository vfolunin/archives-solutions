WITH Times AS (
    SELECT passenger_id, MIN(b.arrival_time) arrival_time
    FROM Passengers p JOIN Buses b ON p.arrival_time <= b.arrival_time
    GROUP BY passenger_id
)
SELECT bus_id, COUNT(passenger_id) passengers_cnt
FROM Buses LEFT JOIN Times USING(arrival_time)
GROUP BY bus_id
ORDER BY bus_id;