WITH RECURSIVE Chains AS (
    SELECT giver_id, receiver_id, 1 chain_length, gift_value
    FROM SecretSanta
    UNION ALL
    SELECT a.giver_id, b.receiver_id, a.chain_length + 1, a.gift_value + b.gift_value
    FROM Chains a, SecretSanta b
    WHERE a.giver_id != a.receiver_id AND a.receiver_id = b.giver_id 
), CircularChains AS (
    SELECT DISTINCT chain_length, gift_value
    FROM Chains
    WHERE giver_id = receiver_id
)
SELECT RANK() OVER (ORDER BY chain_length DESC, gift_value DESC) chain_id, chain_length, gift_value total_gift_value
FROM CircularChains;