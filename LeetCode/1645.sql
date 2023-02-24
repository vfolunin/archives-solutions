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
), AcceptedDrivers AS (
    SELECT month, COUNT(DISTINCT driver_id) accepted_drivers
    FROM Months LEFT JOIN (Rides JOIN AcceptedRides USING(ride_id)) ON YEAR(requested_at) = 2020 AND MONTH(requested_at) = month
    GROUP BY month
)
SELECT month, ROUND(IFNULL(accepted_drivers / active_drivers * 100, 0), 2) working_percentage
FROM Months JOIN ActiveDrivers USING(month) JOIN AcceptedDrivers USING(month);