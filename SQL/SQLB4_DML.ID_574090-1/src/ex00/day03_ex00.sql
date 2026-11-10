SELECT m.pizza_name AS pizza_name, m.price, pi.name AS pizzeria_name, pv.visit_date FROM person_visits pv
JOIN person p ON pv.person_id = p.id
JOIN pizzeria pi ON pv.pizzeria_id = pi.id
JOIN menu m ON pv.pizzeria_id = m.pizzeria_id
WHERE p.name = 'Kate' AND m.price BETWEEN 800 AND 1000
ORDER BY pizza_name, price, pizzeria_name