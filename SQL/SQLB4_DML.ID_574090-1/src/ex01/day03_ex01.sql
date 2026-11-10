SELECT id AS menu_id FROM menu m
WHERE NOT EXISTS (SELECT DISTINCT menu_id FROM person_order po WHERE m.id = po.menu_id)
ORDER BY menu_id