WITH RECURSIVE tokens AS (
    SELECT 
        content_id,
        content_text,
        TRIM(REGEXP_SUBSTR(content_text, "^[A-Za-z]+")) token,
        TRIM(REGEXP_REPLACE(content_text, "^[A-Za-z]+", "")) tokens,
        1 i
    FROM user_content
    UNION ALL
    SELECT 
        content_id,
        content_text,
        TRIM(REGEXP_SUBSTR(tokens, "^[A-Za-z]+")),
        TRIM(REGEXP_REPLACE(tokens, "^[A-Za-z]+", "")),
        i + 1
    FROM tokens
    WHERE tokens != ""
), content AS (
    SELECT content_id, content_text, CONCAT(UPPER(LEFT(token, 1)), LOWER(SUBSTRING(token, 2))) token, i
    FROM tokens
    WHERE token IS NOT NULL
)
SELECT content_id, content_text original_text, GROUP_CONCAT(token ORDER BY i SEPARATOR " ") converted_text
FROM content
GROUP BY content_id;
