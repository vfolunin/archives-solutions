WITH Averages AS (
    SELECT event_type, AVG(occurences) average_occurences
    FROM Events
    GROUP BY event_type
)
SELECT business_id
FROM Events JOIN Averages USING(event_type)
GROUP BY business_id
HAVING SUM(occurences > average_occurences) > 1;