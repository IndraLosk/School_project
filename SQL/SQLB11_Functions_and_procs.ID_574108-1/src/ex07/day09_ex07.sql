CREATE OR REPLACE FUNCTION func_minimum(VARIADIC arr float[])
RETURNS float AS $$ 
    SELECT MIN(x) FROM UNNEST(arr) x;
$$ LANGUAGE SQL;

SELECT func_minimum(VARIADIC arr => ARRAY[10.0, -1.0, 5.0, 4.4]);