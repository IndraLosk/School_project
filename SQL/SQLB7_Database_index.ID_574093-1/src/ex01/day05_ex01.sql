SET enable_seqscan = OFF;

EXPLAIN ANALYZE 
SELECT m.pizza_name, p.name FROM pizzeria p
JOIN menu m ON p.id = m.pizzeria_id;