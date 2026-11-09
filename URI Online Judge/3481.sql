WITH children AS (
    SELECT DISTINCT pointer child_id
    FROM nodes
    WHERE pointer IS NOT NULL
)
SELECT DISTINCT
    node_id,
    CASE
        WHEN child_id IS NULL THEN 'ROOT'
        WHEN pointer IS NULL THEN 'LEAF'
        ELSE 'INNER'
    END type
FROM nodes LEFT JOIN children ON node_id = child_id
ORDER BY node_id;