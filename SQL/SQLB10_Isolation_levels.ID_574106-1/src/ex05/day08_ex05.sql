-- Session #1 --
SHOW TRANSACTION ISOLATION LEVEL;

-- Session #2 --
SHOW TRANSACTION ISOLATION LEVEL;

-- Session #1 --
BEGIN;

-- Session #2 --
BEGIN;

-- Session #1 --
select SUM(rating) from pizzeria;

-- Session #2 --
INSERT INTO pizzeria VALUES (10, 'Kazan Pizza', 5);

-- Session #2 --
COMMIT;

-- Session #1 --
select SUM(rating) from pizzeria;

-- Session #1 --
COMMIT;

-- Session #1 --
select SUM(rating) from pizzeria;

-- Session #2 --
select SUM(rating) from pizzeria;