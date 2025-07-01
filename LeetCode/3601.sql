WITH first_half AS (
    SELECT driver_id, AVG(distance_km / fuel_consumed) first_half_avg
    FROM trips
    WHERE MONTH(trip_date) <= 6
    GROUP BY driver_id
), second_half AS (
    SELECT driver_id, AVG(distance_km / fuel_consumed) second_half_avg
    FROM trips
    WHERE MONTH(trip_date) > 6
    GROUP BY driver_id
)
SELECT
    driver_id,
    driver_name,
    ROUND(first_half_avg, 2) first_half_avg,
    ROUND(second_half_avg, 2) second_half_avg,
    ROUND(second_half_avg - first_half_avg, 2) efficiency_improvement
FROM first_half JOIN second_half USING(driver_id) JOIN drivers USING(driver_id)
WHERE first_half_avg < second_half_avg
ORDER BY efficiency_improvement DESC, driver_name;