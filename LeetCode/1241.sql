SELECT a.sub_id post_id, COUNT(DISTINCT b.sub_id) number_of_comments
FROM Submissions a LEFT JOIN Submissions b ON a.sub_id = b.parent_id
WHERE a.parent_id IS NULL
GROUP BY a.sub_id
ORDER BY post_id;