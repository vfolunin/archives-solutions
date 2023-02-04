SELECT
    ad_id,
    ROUND(IFNULL(SUM(action = "Clicked") / (SUM(action = "Clicked") + SUM(action = "Viewed")), 0) * 100, 2) ctr
FROM Ads
GROUP BY ad_id
ORDER BY ctr DESC, ad_id;