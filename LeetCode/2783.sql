WITH Bookings AS (
    SELECT flight_id, capacity, COUNT(passenger_id) bookings
    FROM Flights LEFT JOIN Passengers USING(flight_id)
    GROUP BY flight_id
)
SELECT
    flight_id,
    IF(bookings <= capacity, bookings, capacity) booked_cnt,
    IF(bookings <= capacity, 0, bookings - capacity) waitlist_cnt
FROM Bookings
ORDER BY flight_id;