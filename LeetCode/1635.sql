WITH RECURSIVE Months AS (
    SELECT 1 month
    UNION ALL
    SELECT month + 1 month
    FROM Months
    WHERE month < 12
), ActiveDrivers AS (
    SELECT month, COUNT(driver_id) active_drivers
    FROM Months LEFT JOIN Drivers ON YEAR(join_date) < 2020 OR YEAR(join_date) = 2020 AND MONTH(join_date) <= month
    GROUP BY month
), TakenRides AS (
    SELECT month, COUNT(ride_id) accepted_rides
    FROM Months LEFT JOIN (Rides JOIN AcceptedRides USING(ride_id)) ON YEAR(requested_at) = 2020 AND MONTH(requested_at) = month
    GROUP BY month
)
SELECT month, active_drivers, accepted_rides
FROM Months JOIN ActiveDrivers USING(month) JOIN TakenRides USING(month);