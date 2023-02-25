WITH RECURSIVE BusSegments AS (
    SELECT bus_id, capacity, 1 + LAG(arrival_time, 1, -1) OVER (ORDER BY arrival_time) l, arrival_time r
    FROM Buses
), Pairs AS (
    SELECT bus_id, r arrival_time, capacity, COUNT(passenger_id) passenger_count
    FROM BusSegments LEFT JOIN Passengers ON arrival_time BETWEEN l AND r
    GROUP BY bus_id
), IndexedPairs AS (
    SELECT *, ROW_NUMBER() OVER (ORDER BY arrival_time) i
    FROM Pairs
), FirstPair AS (
    SELECT
        bus_id,
        IF(passenger_count <= capacity, passenger_count, capacity) passenger_count,
        IF(passenger_count <= capacity, 0, passenger_count - capacity) passenger_over,
        i
    FROM IndexedPairs
    ORDER BY i
    LIMIT 1
), MergedPairs AS (
    SELECT *
    FROM FirstPair
    UNION ALL
    SELECT
        b.bus_id,
        IF(a.passenger_over + b.passenger_count <= b.capacity, a.passenger_over + b.passenger_count, b.capacity) passenger_count,
        IF(a.passenger_over + b.passenger_count <= b.capacity, 0, a.passenger_over + b.passenger_count - b.capacity) passenger_over,
        b.i
    FROM MergedPairs a JOIN IndexedPairs b ON a.i + 1 = b.i
    WHERE b.i < 1000
)
SELECT bus_id, passenger_count passengers_cnt
FROM MergedPairs
ORDER BY bus_id;