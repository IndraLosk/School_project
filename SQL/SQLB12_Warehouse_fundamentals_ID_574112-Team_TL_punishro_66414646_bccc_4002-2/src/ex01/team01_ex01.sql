insert into currency values (100, 'EUR', 0.85, '2022-01-01 13:29');
insert into currency values (100, 'EUR', 0.79, '2022-01-08 13:29');


SELECT 
  COALESCE (us.name, 'not defined') AS user_name,
  COALESCE (us.lastname, 'not defined') AS lastname,
  (
  SELECT c.name
  FROM currency AS c
  WHERE c.id = b.currency_id
  ORDER BY c.updated DESC
  LIMIT 1
  ) AS currency_name,
  COALESCE (
    (
      SELECT CAST(ROUND(c1.rate_to_usd * b.money, 6) AS real)
      FROM currency AS c1
      WHERE c1.id = b.currency_id
        AND c1.updated <= b.updated
      ORDER BY c1.updated DESC
      LIMIT 1
    ),
     (  
      SELECT CAST(ROUND(c1.rate_to_usd * b.money, 6) AS real)
      FROM currency AS c1
      WHERE c1.id = b.currency_id
        AND c1.updated > b.updated
      ORDER BY c1.updated ASC
      LIMIT 1
    )
  ) AS currency_in_usd

FROM balance as b
LEFT JOIN "user" AS us ON us.id = b.user_id
WHERE EXISTS (
  SELECT 1
  FROM currency AS c
  WHERE c.id = b.currency_id
)
ORDER BY user_name DESC, lastname ASC, currency_name ASC;