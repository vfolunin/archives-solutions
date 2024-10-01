SELECT state, GROUP_CONCAT(city ORDER BY city SEPARATOR ', ') cities
FROM cities
GROUP BY state
ORDER BY state;