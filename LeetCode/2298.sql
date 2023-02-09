SELECT SUM(WEEKDAY(submit_date) >= 5) weekend_cnt, SUM(WEEKDAY(submit_date) < 5) working_cnt
FROM Tasks;