SELECT 
    m1.pizza_name,
	pi1.name AS pizzeria_name_1,
	pi2.name AS pizzeria_name_2,
    m1.price
FROM menu m1
JOIN menu m2 ON m1.pizza_name = m2.pizza_name AND m1.price = m2.price AND m1.id < m2.id AND m1.pizzeria_id != m2.pizzeria_id
JOIN pizzeria pi1 ON m1.pizzeria_id = pi1.id 
JOIN pizzeria pi2 ON m2.pizzeria_id = pi2.id 
ORDER BY m1.pizza_name