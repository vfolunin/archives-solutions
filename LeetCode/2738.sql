SELECT "bull" word, SUM(content LIKE "% bull %") count
FROM Files

UNION ALL

SELECT "bear" word, SUM(content LIKE "% bear %") count
FROM Files