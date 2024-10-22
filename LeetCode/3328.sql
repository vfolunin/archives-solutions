SELECT
    state,
    GROUP_CONCAT(city ORDER BY city SEPARATOR ', ') cities,
    SUM(LEFT(city, 1) = LEFT(state, 1)) matching_letter_count
FROM cities
GROUP BY state
HAVING COUNT(city) > 2 AND matching_letter_count > 0
ORDER BY matching_letter_count DESC, state;