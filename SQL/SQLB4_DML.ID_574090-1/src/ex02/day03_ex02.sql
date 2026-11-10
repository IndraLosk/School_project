SELECT m.pizza_name, m.price, pi.name AS pizzeria_name FROM menu m
JOIN pizzeria pi ON m.pizzeria_id = pi.id
WHERE NOT EXISTS (SELECT DISTINCT menu_id FROM person_order po WHERE m.id = po.menu_id)
ORDER BY pizza_name, price