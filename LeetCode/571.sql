WITH Frequencies AS (
    SELECT
        *,
        SUM(frequency) OVER (ORDER BY num) upper_frequency,
        (SUM(frequency) OVER ()) / 2 median_frequency
    FROM Numbers
)
SELECT AVG(num) median
FROM Frequencies
WHERE median_frequency BETWEEN (upper_frequency - frequency) AND upper_frequency;