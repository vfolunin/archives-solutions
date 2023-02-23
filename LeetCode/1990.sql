WITH Platforms AS (
    SELECT "Android" platform
    UNION ALL
    SELECT "IOS" platform
    UNION ALL
    SELECT "Web" platform
), ExperimentNames AS (
    SELECT "Programming" experiment_name
    UNION ALL
    SELECT "Reading" experiment_name
    UNION ALL
    SELECT "Sports" experiment_name
), Pairs AS (
    SELECT *
    FROM Platforms, ExperimentNames
)
SELECT platform, experiment_name, COUNT(experiment_id) num_experiments
FROM Pairs p LEFT JOIN Experiments e USING(platform, experiment_name)
GROUP BY platform, experiment_name;