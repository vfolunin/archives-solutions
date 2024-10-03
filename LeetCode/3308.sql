WITH Indexes AS (
    SELECT
        fuel_type,
        driver_id,
        ROUND(AVG(rating), 2) rating,
        SUM(distance) distance,
        RANK() OVER(PARTITION BY fuel_type ORDER BY AVG(rating) DESC, SUM(distance) DESC, SUM(accidents)) i
    FROM Drivers JOIN Vehicles USING(driver_id) JOIN Trips USING(vehicle_id)
    GROUP BY fuel_type, driver_id
)
SELECT fuel_type, driver_id, rating, distance
FROM Indexes 
WHERE i = 1
ORDER BY fuel_type;