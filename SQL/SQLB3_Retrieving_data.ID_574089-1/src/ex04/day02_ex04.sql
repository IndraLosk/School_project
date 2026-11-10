SELECT m.pizza_name AS pizza_name, pi.name AS pizzeria_name, m.price FROM menu m
JOIN pizzeria pi ON m.pizzeria_id = pi.id
WHERE m.pizza_name = 'mushroom pizza' OR m.pizza_name = 'pepperoni pizza'
ORDER BY pizza_name, pizzeria_name