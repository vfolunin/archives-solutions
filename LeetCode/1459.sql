SELECT
    a.id p1,
    b.id p2,
	ABS(a.x_value - b.x_value) * ABS(a.y_value - b.y_value) area
FROM Points a JOIN Points b ON a.id < b.id AND a.x_value <> b.x_value AND a.y_value <> b.y_value
ORDER BY area DESC, p1, p2;