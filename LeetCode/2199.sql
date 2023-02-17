SELECT 
    post_id, 
    IFNULL(GROUP_CONCAT(DISTINCT topic_id ORDER BY topic_id), "Ambiguous!") topic
FROM Posts p LEFT JOIN Keywords k ON CONCAT(' ', LOWER(content), ' ') LIKE CONCAT('% ', LOWER(word), ' %')
GROUP BY post_id;