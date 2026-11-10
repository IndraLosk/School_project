SELECT * FROM person_order -- Посмотреть таблицу

INSERT INTO person_order
SELECT
    (SELECT MAX(id) FROM person_order) + p.id AS id,
    p.id AS person_id,
    (SELECT id FROM menu WHERE pizza_name = 'greek pizza') AS menu_id,
    '2022-02-25' AS order_date
FROM person p 