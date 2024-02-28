WITH TypeFootage AS (
    SELECT item_type, SUM(square_footage) total_footage, COUNT(item_id) type_count
    FROM Inventory
    GROUP BY item_type
), PrimeCount AS (
    SELECT FLOOR(500000 / total_footage) prime_count
    FROM TypeFootage
    WHERE item_type = "prime_eligible"
), NotPrimeCount AS (
    SELECT FLOOR(500000 % p.total_footage / np.total_footage) not_prime_count
    FROM TypeFootage p, TypeFootage np
    WHERE p.item_type = "prime_eligible" AND np.item_type = "not_prime"
)
SELECT item_type, prime_count * type_count item_count
FROM TypeFootage, PrimeCount
WHERE item_type = "prime_eligible"
UNION
SELECT item_type, not_prime_count * type_count item_count
FROM TypeFootage, NotPrimeCount
WHERE item_type = "not_prime"
ORDER BY item_count DESC;