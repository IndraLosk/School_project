WITH visits_by_gender AS
	(SELECT p.gender, pi.name AS pizzeria_name, COUNT(*) AS visit_count FROM person_order po
	JOIN menu m  ON m.id = po.menu_id
    JOIN pizzeria pi ON pi.id = m.pizzeria_id
    JOIN person p ON p.id = po.person_id
	GROUP BY p.gender, pi.name
	ORDER BY pizzeria_name)
SELECT pizzeria_name FROM visits_by_gender
GROUP BY pizzeria_name
HAVING COUNT(gender) = 1
ORDER BY pizzeria_name