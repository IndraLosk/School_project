CREATE MATERIALIZED VIEW mv_dmitriy_visits_and_eats AS
SELECT pi.name FROM person_visits pv
JOIN person p ON pv.person_id = p.id
JOIN pizzeria pi ON pv.pizzeria_id = pi.id
JOIN menu m ON pv.pizzeria_id = m.pizzeria_id
WHERE p.name = 'Dmitriy' AND pv.visit_date = '2022-01-08' AND m.price < 800;

SELECT * FROM mv_dmitriy_visits_and_eats;