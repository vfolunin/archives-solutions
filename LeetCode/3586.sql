WITH positive AS (
    SELECT patient_id, MIN(test_date) p_date
    FROM patients JOIN covid_tests USING(patient_id)
    WHERE result = "Positive"
    GROUP BY patient_id
), negative AS (
    SELECT patient_id, MIN(test_date) n_date
    FROM Positive JOIN covid_tests USING(patient_id)
    WHERE result = "Negative" AND p_date < test_date
    GROUP BY patient_id
)
SELECT patient_id, patient_name, age, DATEDIFF(n_date, p_date) recovery_time
FROM patients JOIN positive USING(patient_id) JOIN negative USING(patient_id)
ORDER BY recovery_time, patient_name;