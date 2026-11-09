SELECT l.queue, l.id "left", r.id "right"
FROM chairs l JOIN chairs r ON r.queue = l.queue AND l.id + 1 = r.id
WHERE l.available AND r.available
ORDER BY l.id;