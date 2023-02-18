WITH Dates AS (
    SELECT
        "failed" period_state,
        fail_date date,
        DAYOFYEAR(fail_date) - ROW_NUMBER() OVER (ORDER BY fail_date) period
    FROM Failed
    WHERE YEAR(fail_date) = 2019   

    UNION ALL

    SELECT
        "succeeded" period_state,
        success_date date,
        DAYOFYEAR(success_date) - ROW_NUMBER() OVER (ORDER BY success_date) period
    FROM Succeeded
    WHERE YEAR(success_date) = 2019
)
SELECT period_state, MIN(date) start_date, MAX(date) end_date
FROM Dates
GROUP BY period_state, period
ORDER BY start_date;