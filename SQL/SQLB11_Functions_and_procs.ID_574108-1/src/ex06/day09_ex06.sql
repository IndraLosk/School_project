CREATE OR REPLACE FUNCTION fnc_person_visits_and_eats_on_date(
    IN pperson varchar DEFAULT 'Dmitriy',
    IN pprice numeric DEFAULT 500,
    IN pdate date DEFAULT '2022-01-08'
)
RETURNS TABLE (name varchar) AS $$
BEGIN
    RETURN QUERY
    SELECT pi.name FROM person_visits pv
    JOIN person p ON pv.person_id = p.id
    JOIN pizzeria pi ON pv.pizzeria_id = pi.id
    JOIN menu m ON pv.pizzeria_id = m.pizzeria_id
    WHERE p.name = pperson AND pv.visit_date = pdate AND m.price < pprice;
END;
$$ LANGUAGE plpgsql;

select *  
from fnc_person_visits_and_eats_on_date(pprice := 800);

select *  
from fnc_person_visits_and_eats_on_date(pperson := 'Anna',pprice := 1300,pdate := '2022-01-01');