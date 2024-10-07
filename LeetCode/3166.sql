WITH TotalFees AS (   
    SELECT car_id, SUM(fee_paid) total_fee_paid, SUM(TIMESTAMPDIFF(MINUTE, entry_time, exit_time) / 60) total_time_spent
    FROM ParkingTransactions
    GROUP BY car_id
), Fees AS (
    SELECT car_id, total_fee_paid, ROUND(total_fee_paid / total_time_spent, 2) avg_hourly_fee
    FROM TotalFees
), Times AS (
    SELECT car_id, lot_id, SUM(TIMESTAMPDIFF(MINUTE, entry_time, exit_time) / 60) total_time_in_lot
    FROM ParkingTransactions
    GROUP BY car_id, lot_id
), SortedTimes AS (
    SELECT car_id, lot_id, RANK() OVER (PARTITION BY car_id ORDER BY total_time_in_lot DESC) i
    FROM Times
)
SELECT car_id, total_fee_paid, avg_hourly_fee, lot_id most_time_lot
FROM Fees JOIN SortedTimes USING(car_id)
WHERE i = 1;  