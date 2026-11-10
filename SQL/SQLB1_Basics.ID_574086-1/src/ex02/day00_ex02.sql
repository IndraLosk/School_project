SELECT name, rating FROM pizzeria
WHERE 3.5 <= rating and rating <= 5
ORDER BY rating

SELECT name, rating FROM pizzeria
WHERE rating BETWEEN 3.5 and 5
ORDER BY rating