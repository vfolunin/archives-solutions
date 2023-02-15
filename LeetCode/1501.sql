SELECT Country.name country
FROM Person JOIN Country ON LEFT(phone_number, 3) = country_code JOIN Calls ON id = caller_id  OR id = callee_id
GROUP BY country
HAVING AVG(duration) > (
    SELECT AVG(duration)
    FROM Calls
);