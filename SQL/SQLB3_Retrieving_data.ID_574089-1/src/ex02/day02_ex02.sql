SELECT 
    COALESCE(p.name, '-') AS person_name,
    gs_visit_date::date AS visit_date,
    COALESCE(pi.name, '-') AS pizzeria_name
FROM generate_series('2022-01-01', '2022-01-03', interval '1') AS gs_visit_date
JOIN person_visits pv ON gs_visit_date = pv.visit_date
FULL JOIN person p ON p.id = pv.person_id
FULL JOIN pizzeria pi ON pi.id = pv.pizzeria_id
ORDER BY person_name, visit_date, pizzeria_name