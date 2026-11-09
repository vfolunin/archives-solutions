WITH monthly_profit AS (
    SELECT client_id, month, SUM(profit) profit
    FROM operations
    GROUP BY client_id, month
), accumulated_profit AS (
    SELECT
        client_id,
        month,
        SUM(profit) OVER (PARTITION BY client_id ORDER BY month) accumulated
    FROM monthly_profit
), paybacks AS (
    SELECT
        clients.name,
        clients.investment,
        month month_of_payback,
        accumulated - investment return,
        ROW_NUMBER() OVER (PARTITION BY clients.id ORDER BY month) payback_number
    FROM clients JOIN accumulated_profit ON client_id = clients.id
    WHERE accumulated >= investment
)
SELECT name, investment, month_of_payback, return
FROM paybacks
WHERE payback_number = 1
ORDER BY return DESC;