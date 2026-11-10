WITH visits_by_gender AS
	(SELECT p.gender, pi.name AS pizzeria_name, COUNT(*) AS visit_count FROM person_visits pv
	JOIN person p ON pv.person_id = p.id
	JOIN pizzeria pi ON pv.pizzeria_id = pi.id
	GROUP BY p.gender, pi.name
	ORDER BY pizzeria_name)
SELECT vbg.pizzeria_name FROM visits_by_gender vbg
JOIN visits_by_gender vbg2 ON vbg.pizzeria_name = vbg2.pizzeria_name
WHERE vbg.gender = 'female' 
  AND vbg2.gender = 'male'
  AND (vbg.visit_count > vbg2.visit_count
  OR vbg.visit_count < vbg2.visit_count)
ORDER BY vbg.pizzeria_name