WITH RECURSIVE tsp AS (
	SELECT 
		ARRAY[point1, point2]::VARCHAR[] AS tour,
		point2 AS last_city,
		cost AS total_cost,
	    2 AS visited_cities
	FROM graph
	WHERE point1 = 'a'
	
	UNION ALL
	
	SELECT 
		tsp.tour || n.point2,
		n.point2,
		tsp.total_cost + n.cost,
		tsp.visited_cities + 1
	FROM tsp
    JOIN graph n ON n.point1 = tsp.last_city
	WHERE NOT (n.point2 = ANY(tsp.tour)) AND tsp.visited_cities < 4
),
res_tours AS (
	SELECT 
        tsp.tour || ARRAY['a'] AS tour,
        tsp.total_cost + n.cost AS total_cost
    FROM tsp
    JOIN graph n ON n.point1 = tsp.last_city AND n.point2 = 'a'
    WHERE tsp.visited_cities = 4
)
SELECT total_cost, tour::text
FROM res_tours
WHERE total_cost = (SELECT MIN(total_cost) FROM res_tours)
UNION ALL
SELECT total_cost, tour::text
FROM res_tours
WHERE total_cost = (SELECT MAX(total_cost) FROM res_tours)
ORDER BY total_cost, tour;