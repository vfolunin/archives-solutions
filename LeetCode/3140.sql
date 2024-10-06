WITH FreeSeatsRows AS (
    SELECT seat_id, seat_id - ROW_NUMBER() OVER (PARTITION BY free ORDER BY seat_id) i 
    FROM Cinema
    WHERE free = 1
), SortedFreeSeatsRows AS (
    SELECT
        MIN(seat_id) first_seat_id,
        MAX(seat_id) last_seat_id,
        COUNT(*) consecutive_seats_len,
        RANK() OVER(ORDER BY COUNT(*) DESC) i
    FROM FreeSeatsRows
    GROUP BY i
)
SELECT first_seat_id, last_seat_id, consecutive_seats_len
FROM SortedFreeSeatsRows
WHERE i = 1;