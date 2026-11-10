SELECT name, rating FROM pizzeria
WHERE id NOT IN (SELECT pizzeria_id FROM person_visits)