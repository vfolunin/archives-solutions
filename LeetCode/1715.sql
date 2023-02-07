SELECT
    SUM(b.apple_count) + IFNULL(SUM(c.apple_count), 0) apple_count,
    SUM(b.orange_count) + IFNULL(SUM(c.orange_count), 0) orange_count
FROM Boxes b LEFT JOIN Chests c USING(chest_id);