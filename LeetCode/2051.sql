SELECT
    member_id,
    name,
    CASE
        WHEN COUNT(visit_date) = 0 THEN "Bronze"
        WHEN (COUNT(charged_amount) / COUNT(visit_date)) < 0.5 THEN "Silver"
        WHEN (COUNT(charged_amount) / COUNT(visit_date)) >= 0.8 THEN "Diamond"
        ELSE "Gold"
    END category
FROM Members LEFT JOIN Visits USING(member_id) LEFT JOIN Purchases USING(visit_id)
GROUP BY member_id;