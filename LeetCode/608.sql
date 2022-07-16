SELECT t.id, CASE
        WHEN t.parent IS NULL THEN 'Root'
        WHEN t.child IS NULL THEN 'Leaf'
        ELSE 'Inner'
    END Type
FROM (
    SELECT t1.id, t1.p_id parent, t2.id child
    FROM Tree t1 LEFT JOIN Tree t2 ON t1.id = t2.p_id
    GROUP BY t1.id
) t;