SELECT DISTINCT a.user_id
FROM
    Confirmations a JOIN Confirmations b ON a.user_id = b.user_id AND
    a.time_stamp < b.time_stamp AND TIMESTAMPDIFF(SECOND, a.time_stamp, b.time_stamp) <= 24 * 60 * 60
ORDER BY a.user_id;