SELECT * FROM person_order -- Посмотреть таблицу

INSERT INTO person_order VALUES 
	(
	(SELECT MAX(po.id) + 1 FROM person_order po), 
	(SELECT id FROM person WHERE name = 'Denis'),
	(SELECT id FROM menu WHERE pizza_name = 'sicilian pizza'), 
	'2022-02-24'
	),
	(
	(SELECT MAX(po.id) + 2 FROM person_order po), 
	(SELECT id FROM person WHERE name = 'Irina'),
	(SELECT id FROM menu WHERE pizza_name = 'sicilian pizza'), 
	'2022-02-24'
	)  -- Вставить строки
