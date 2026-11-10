SELECT * FROM menu -- Посмотреть таблицу

INSERT INTO menu (id, pizzeria_id, pizza_name, price) 
VALUES (
	(SELECT MAX(m.id) + 1 FROM menu m), 
	(SELECT id FROM pizzeria WHERE name = 'Dominos'), 
	'sicilian pizza', 
	900) -- Вставить строку