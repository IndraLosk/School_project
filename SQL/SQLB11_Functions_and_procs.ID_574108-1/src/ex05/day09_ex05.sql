DROP FUNCTION IF EXISTS fnc_persons_female, fnc_persons_male;

CREATE OR REPLACE FUNCTION fnc_persons(pgender varchar = 'female') RETURNS SETOF person AS $$ 
	SELECT * FROM person 
	WHERE gender = pgender;
$$ LANGUAGE SQL;

SELECT *
FROM fnc_persons(pgender := 'male');

SELECT *
FROM fnc_persons();