SELECT p.address, pi.name, COUNT(*) AS count_of_orders FROM person_order po
JOIN person p ON p.id = po.person_id
JOIN menu m ON m.id = po.menu_id
JOIN pizzeria pi ON m.pizzeria_id = pi.id
GROUP BY p.address, pi.name
ORDER BY address, name;