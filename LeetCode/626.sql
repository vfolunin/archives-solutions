SELECT s1.id, IF(s2.student IS NOT NULL, s2.student, s1.student) student
FROM Seat s1 LEFT JOIN Seat s2 ON (s1.id + 1) ^ 1 = s2.id + 1
ORDER BY s1.id;