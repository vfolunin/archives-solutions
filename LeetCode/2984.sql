WITH Hours AS (
    SELECT city, HOUR(call_time) calling_hour, COUNT(*) number_of_calls
    FROM Calls
    GROUP BY city, calling_hour
), PeakNumberOfCalls AS (
    SELECT city, MAX(number_of_calls) number_of_calls
    FROM Hours
    GROUP BY city
)
SELECT city, calling_hour peak_calling_hour, number_of_calls
FROM Hours JOIN PeakNumberOfCalls USING(city, number_of_calls)
ORDER BY peak_calling_hour DESC, city DESC;