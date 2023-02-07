SELECT a.follower, COUNT(DISTINCT b.follower) num
FROM Follow a JOIN Follow b ON a.follower = b.followee
GROUP BY a.follower
ORDER BY a.follower;