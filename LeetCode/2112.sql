WITH Airports AS (
    SELECT departure_airport airport_id, flights_count
    FROM Flights
    UNION ALL
    SELECT arrival_airport airport_id, flights_count
    FROM Flights
)
SELECT airport_id
FROM Airports
GROUP BY airport_id
HAVING SUM(flights_count) = (
    SELECT SUM(flights_count)
    FROM Airports
    GROUP BY airport_id
    ORDER BY 1 DESC
    LIMIT 1
);