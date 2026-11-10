SELECT order_date, 
	(SELECT CONCAT(name, ' (age:', age, ')') FROM person WHERE id = person_id) AS person_information
	FROM person_order
ORDER BY order_date, person_information