WITH SelectedPosts AS (
    SELECT *
    FROM Posts
    WHERE post_date BETWEEN "2024-02-01" AND "2024-02-28"
), AvgWeeklyPosts AS (
    SELECT user_id, COUNT(*) / 4 avg_weekly_posts
    FROM SelectedPosts
    GROUP BY user_id
), 7DayPosts AS (
    SELECT
        user_id,
        post_date,
        COUNT(*) OVER (PARTITION BY user_id ORDER BY post_date RANGE BETWEEN INTERVAL 6 DAY PRECEDING AND CURRENT ROW) 7day_posts
    FROM SelectedPosts
), Max7DayPosts AS (
    SELECT user_id, MAX(7day_posts) max_7day_posts
    FROM 7DayPosts
    GROUP BY user_id
)
SELECT *
FROM Max7DayPosts JOIN AvgWeeklyPosts USING(user_id)
HAVING avg_weekly_posts * 2 <= max_7day_posts
ORDER BY user_id;