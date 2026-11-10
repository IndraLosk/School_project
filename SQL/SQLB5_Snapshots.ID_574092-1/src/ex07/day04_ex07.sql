INSERT INTO person_visits VALUES 
	(
	(SELECT MAX(pv.id) + 1 FROM person_visits pv), 
	(SELECT id FROM person WHERE name = 'Dmitriy'),
	(SELECT id FROM pizzeria WHERE name NOT IN (SELECT name FROM mv_dmitriy_visits_and_eats)
	AND id IN (SELECT pizzeria_id FROM menu WHERE price < 800)
	LIMIT 1), 
	'2022-01-08'
	);

REFRESH MATERIALIZED VIEW mv_dmitriy_visits_and_eats;

SELECT * FROM mv_dmitriy_visits_and_eats;

-- SELECT * FROM person_visits
-- DELETE FROM person_visits WHERE id = 20