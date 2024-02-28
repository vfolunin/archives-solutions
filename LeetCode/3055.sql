WITH FraudRank AS (
    SELECT *, PERCENT_RANK() OVER (PARTITION BY state ORDER BY fraud_score DESC) fraud_rank
    FROM Fraud
)
SELECT policy_id, state, fraud_score
FROM FraudRank
WHERE fraud_rank <= 0.05
ORDER BY state ASC, fraud_score DESC, policy_id ASC;