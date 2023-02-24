WITH RECURSIVE Months AS (
    SELECT 1 month
    UNION ALL
    SELECT month + 1 month
    FROM Months
    WHERE month < 10
)
SELECT
    month,
    ROUND(IFNULL(SUM(ride_distance) / 3, 0), 2) average_ride_distance,
    ROUND(IFNULL(SUM(ride_duration) / 3, 0), 2) average_ride_duration
FROM Months LEFT JOIN (Rides JOIN AcceptedRides USING(ride_id)) ON YEAR(requested_at) = 2020 AND MONTH(requested_at) - month BETWEEN 0 AND 2
GROUP BY month;