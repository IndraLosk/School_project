CREATE UNIQUE INDEX idx_person_discounts_unique ON person_discounts(person_id, pizzeria_id);

SET enable_seqscan = OFF;
EXPLAIN ANALYZE
SELECT 
	p.name,
	m.pizza_name,
	m.price,
	m.price - (m.price * ROUND((pd.discount / 100), 2)) AS discount_price,
	pi.name AS pizzeria_name
FROM person_order po 
JOIN person p ON po.person_id = p.id
JOIN menu m ON po.menu_id = m.id
JOIN pizzeria pi ON m.pizzeria_id = pi.id
JOIN person_discounts pd ON po.person_id = pd.person_id
ORDER BY p.name, m.pizza_name;