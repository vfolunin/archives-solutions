SELECT
    left_operand,
    operator,
    right_operand,
    IF(CASE
        WHEN e.operator = "=" THEN l.value = r.value
        WHEN e.operator = "<" THEN l.value < r.value
        ELSE l.value > r.value
    END, "true", "false") value
FROM Expressions e JOIN Variables l ON e.left_operand = l.name JOIN Variables r ON e.right_operand = r.name;