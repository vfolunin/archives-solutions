SELECT a.symbol metal, b.symbol nonmetal
FROM Elements a, Elements b
WHERE a.type = "Metal" AND b.type = "Nonmetal";