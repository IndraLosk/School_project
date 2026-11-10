SELECT * FROM person_visits -- Посмотреть таблицу

INSERT INTO person_visits VALUES 
	(
	(SELECT MAX(pv.id) + 1 FROM person_visits pv), 
	(SELECT id FROM person WHERE name = 'Denis'),
	(SELECT id FROM pizzeria WHERE name = 'Dominos'), 
	'2022-02-24'
	),
	(
	(SELECT MAX(pv.id) + 2 FROM person_visits pv), 
	(SELECT id FROM person WHERE name = 'Irina'),
	(SELECT id FROM pizzeria WHERE name = 'Dominos'), 
	'2022-02-24'
	)  -- Вставить строки