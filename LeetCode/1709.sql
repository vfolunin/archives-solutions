WITH IndexedVisits AS (
    SELECT *, RANK() OVER (PARTITION BY user_id ORDER BY visit_date) i
    FROM UserVisits
)
SELECT a.user_id, MAX(DATEDIFF(IFNULL(b.visit_Date, "2021-01-01"), a.visit_Date)) biggest_window
FROM IndexedVisits a LEFT JOIN IndexedVisits b ON a.user_id = b.user_id AND a.i + 1 = b.i
GROUP BY user_id 
ORDER BY user_id;