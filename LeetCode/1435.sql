SELECT "[0-5>" bin, COUNT(*) total
FROM Sessions
WHERE duration < 5 * 60

UNION

SELECT "[5-10>" bin, COUNT(*) total
FROM Sessions
WHERE 5 * 60 <= duration AND duration < 10 * 60

UNION

SELECT "[10-15>" bin, COUNT(*) total
FROM Sessions
WHERE 10 * 60 <= duration AND duration < 15 * 60

UNION

SELECT "15 or more" bin, COUNT(*) total
FROM Sessions
WHERE 15 * 60 <= duration;