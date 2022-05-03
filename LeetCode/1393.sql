SELECT stock_name, SUM(IF(operation = "SELL", price, -price)) capital_gain_loss
FROM Stocks
GROUP BY stock_name