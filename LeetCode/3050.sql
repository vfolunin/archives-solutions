SELECT
    CONCAT_WS(',', a.topping_name, b.topping_name, c.topping_name) pizza,
    ROUND(a.cost + b.cost + c.cost, 2) total_cost
FROM Toppings a, Toppings b, Toppings c
WHERE a.topping_name < b.topping_name AND b.topping_name < c.topping_name
ORDER BY total_cost DESC, pizza;