SELECT po.order_date, CONCAT(p.name, ' (age:', p.age, ')') AS person_information 
FROM person_order po
NATURAL JOIN (SELECT id AS person_id, name, age FROM person) p
ORDER BY order_date, person_information