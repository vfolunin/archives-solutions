SELECT DISTINCT title
FROM TVProgram JOIN Content USING(content_id)
WHERE LEFT(program_date, 7) = "2020-06" AND Kids_content = "Y" AND content_type = "Movies";