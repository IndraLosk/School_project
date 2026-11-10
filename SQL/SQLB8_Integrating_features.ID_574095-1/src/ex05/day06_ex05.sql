COMMENT ON TABLE person_discounts IS 'Персональные скидки клиентов в пиццериях на основе количества заказов';

COMMENT ON COLUMN person_discounts.id IS 'Уникальный идентификатор записи';
COMMENT ON COLUMN person_discounts.person_id IS 'ID клиента (ссылка на person)';
COMMENT ON COLUMN person_discounts.pizzeria_id IS 'ID пиццерии (ссылка на pizzeria)';
COMMENT ON COLUMN person_discounts.discount IS 'Размер скидки в %: 10.5% - 1 заказ, 22% - 2 заказа, 30% - 3+ заказов';