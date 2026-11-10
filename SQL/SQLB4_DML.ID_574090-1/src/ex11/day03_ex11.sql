SELECT * FROM menu -- 19	2	"greek pizza"	800

UPDATE menu SET price = price - (price * 0.1)
WHERE pizza_name = 'greek pizza'