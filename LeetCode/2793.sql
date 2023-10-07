WITH Bookings AS (
    SELECT passenger_id, capacity, RANK() OVER (PARTITION BY flight_id ORDER BY booking_time) i
    FROM Passengers LEFT JOIN Flights USING(flight_id)
)
SELECT passenger_id, IF(i <= capacity, "Confirmed", "Waitlist") Status
FROM Bookings
ORDER BY passenger_id;