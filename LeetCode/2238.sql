WITH Ids as (
    SELECT DISTINCT driver_id
    FROM Rides
)
SELECT i.driver_id, COUNT(r.ride_id) cnt
FROM Ids i LEFT JOIN Rides r ON i.driver_id = r.passenger_id
GROUP BY i.driver_id;