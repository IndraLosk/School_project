WITH missing_date AS
	(SELECT missing_date::date
	FROM generate_series('2022-01-01'::date, '2022-01-10'::date, interval '1 day') AS missing_date)
SELECT * FROM missing_date
WHERE missing_date::date NOT IN
	(SELECT visit_date FROM person_visits
	WHERE visit_date BETWEEN '2022-01-01' AND '2022-01-10'
	AND person_id IN (1, 2))
ORDER BY missing_date