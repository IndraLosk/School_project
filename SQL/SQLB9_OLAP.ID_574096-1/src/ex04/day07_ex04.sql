SELECT p.name, COUNT(*) AS count FROM person_visits pv
JOIN person p ON p.id = pv.person_id
GROUP BY p.name
HAVING pv.count > 3;