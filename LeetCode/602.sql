SELECT DISTINCT a id, COUNT(*) num
FROM (
    SELECT requester_id a, accepter_id b
    FROM RequestAccepted
    UNION
    SELECT accepter_id a, requester_id b
    FROM RequestAccepted
) s
GROUP BY id
ORDER BY num DESC
LIMIT 1;