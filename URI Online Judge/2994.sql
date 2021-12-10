SELECT d.name,
ROUND(SUM(a.hours * 150 * (1 + w.bonus / 100.0)), 1) AS salary
FROM attendances AS a
JOIN doctors AS d ON a.id_doctor = d.id
JOIN work_shifts AS w ON a.id_work_shift = w.id
GROUP BY d.id
ORDER BY salary DESC;