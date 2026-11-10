CREATE OR REPLACE FUNCTION fnc_fibonacci(pstop integer = 10)
RETURNS TABLE(fibonacci_num integer) AS $$
	WITH RECURSIVE fibonacci(val1, val2) AS (
	    SELECT 0, 1
	    
	    UNION ALL
	
	    SELECT val2, val1 + val2
	    FROM fibonacci
	    WHERE val2 < pstop
	)
	SELECT val1 AS fibonacci_num FROM fibonacci;
$$ LANGUAGE SQL;

select * from fnc_fibonacci(100);

select * from fnc_fibonacci();