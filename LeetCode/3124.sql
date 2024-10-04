WITH IncomingCalls AS (
    SELECT first_name, type, duration
    FROM Calls JOIN Contacts ON contact_id = id
    WHERE type = "incoming"
    ORDER BY duration DESC
    LIMIT 3
), OutgoingCalls AS (
    SELECT first_name, type, duration
    FROM Calls JOIN Contacts ON contact_id = id
    WHERE type = "outgoing"
    ORDER BY duration DESC
    LIMIT 3
), AllCalls AS (
    SELECT *
    FROM IncomingCalls
    UNION
    SELECT *
    FROM OutgoingCalls
)
SELECT
    first_name,
    type,
    CONCAT(LPAD(duration DIV 3600, 2, '0'), ':', LPAD(duration % 3600 DIV 60, 2, '0'), ':', LPAD(duration % 60, 2, '0')) duration_formatted
FROM AllCalls
ORDER BY type DESC, duration DESC, first_name DESC;