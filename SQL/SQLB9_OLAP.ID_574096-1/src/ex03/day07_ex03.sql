SELECT 
    name,
    SUM(count) AS total_count
FROM (
	SELECT * FROM (
	(SELECT pi.name, COUNT(*) AS count, 'visit' AS action_type FROM person_visits pv
	JOIN pizzeria pi ON pi.id = pv.pizzeria_id
	GROUP BY pi.name
	ORDER BY count DESC)
	UNION ALL
	(SELECT pi.name AS pizzeria_name, COUNT(*) AS count, 'order' AS action_type FROM person_order po
	JOIN menu m ON po.menu_id = m.id
	JOIN pizzeria pi ON m.pizzeria_id = pi.id
	GROUP BY pi.name
	ORDER BY count DESC)
	ORDER BY action_type, count DESC)
) AS combined
GROUP BY name
ORDER BY total_count DESC, name ASC;