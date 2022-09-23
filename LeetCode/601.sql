SELECT DISTINCT a.*
FROM Stadium a JOIN Stadium b JOIN Stadium c ON (
    (a.id + 1 = b.id AND a.id + 2 = c.id) OR
    (a.id - 1 = b.id AND a.id + 1 = c.id) OR
    (a.id - 2 = b.id AND a.id - 1 = c.id)
)
WHERE a.people >= 100 AND b.people >= 100 AND c.people >= 100
ORDER BY a.id;