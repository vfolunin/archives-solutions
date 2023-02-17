WITH Parts AS (
    SELECT
        power,
        CONCAT(
            IF(factor > 0, "+", ""),
            factor,
            IF(power > 0, "X", ""),
            IF(power > 1, CONCAT("^", power), "")
        ) part        
    FROM Terms
)
SELECT CONCAT(GROUP_CONCAT(part ORDER BY power DESC SEPARATOR ""), "=0") equation
FROM Parts;