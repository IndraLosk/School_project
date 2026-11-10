# SQL — практикум по базам данных

Набор проектов по SQL и работе с реляционными базами данных (PostgreSQL). Каждый блок содержит решения практических задач `src/exNN/dayNN_exNN.sql` нарастающей сложности: от первых запросов до DWH-моделирования и управления транзакциями.

## Структура

| Блок | Тема | Задач | Пример src |
|------|------|:--:|------------|
| **SQLB1** | Базы данных: основные операции | 10 | `SQLB1_Basics.ID_574086-1/src/ex00/day00_ex00.sql` |
| **SQLB2** | Выборка данных (SELECT, JOIN) | 11 | `SQLB2_Retrieving_data.ID_574087-1/src/ex00/day01_ex00.sql` |
| **SQLB3** | Выборка данных продвинутая (подзапросы, UNION) | 11 | `SQLB3_Retrieving_data.ID_574089-1/src/ex00/day02_ex00.sql` |
| **SQLB4** | DML: вставка и обновление данных | 14 | `SQLB4_DML.ID_574090-1/src/ex00/day03_ex00.sql` |
| **SQLB5** | Снимки данных (snapshots) и витрины | 9 | `SQLB5_Snapshots.ID_574092-1/src/ex00/day04_ex00.sql` |
| **SQLB6** | Задача коммивояжёра (рекурсивные CTE) | 2 | `SQLB6_Salesman_problem.../src/ex00/team00_ex00.sql` |
| **SQLB7** | Индексы и производительность | 7 | `SQLB7_Database_index.ID_574093-1/src/ex00/day05_ex00.sql` |
| **SQLB8** | Интеграция данных: внешние ключи, представления, EXPLAIN | 7 | `SQLB8_Integrating_features.ID_574095-1/src/ex00/day06_ex00.sql` |
| **SQLB9** | OLAP: агрегации и оконные функции | 10 | `SQLB9_OLAP.ID_574096-1/src/ex00/day07_ex00.sql` |
| **SQLB10** | Уровни изоляции транзакций | 8 | `SQLB10_Isolation_levels.ID_574106-1/src/ex00/day08_ex00.sql` |
| **SQLB11** | Хранимые функции и процедуры | 9 | `SQLB11_Functions_and_procs.ID_574108-1/src/ex00/day09_ex00.sql` |
| **SQLB12** | DWH: проектирование хранилища | 2 | `SQLB12_Warehouse.../src/ex00/team01_ex00.sql` |

## Освоенные навыки

- **Основы SQL** — SELECT, WHERE, ORDER BY, LIMIT, типы данных.
- **JOIN и подзапросы** — INNER/LEFT JOIN, коррелированные подзапросы, UNION/INTERSECT/EXCEPT, DISTINCT ON.
- **Агрегации и группировка** — GROUP BY, HAVING, COUNT/SUM/AVG/MIN/MAX, ROUND, CASE.
- **Оконные функции и OLAP** — агрегации по окнам, ранжирование, аналитические отчёты.
- **Рекурсивные CTE** — транзитивное замыкание, графы (задача коммивояжёра).
- **DML и схемы** — INSERT/UPDATE/DELETE, sequences, констрейнты, внешние ключи, представления.
- **Производительность** — индексы, `EXPLAIN ANALYZE`, оптимизация планов запросов.
- **Транзакции** — `BEGIN/COMMIT/ROLLBACK`, уровни изоляции, параллельные сессии.
- **Хранимый код** — функции и процедуры на PL/pgSQL.
- **DWH** — моделирование "звезда", витрины данных из операционных таблиц.

## Избранные решения

- Самая содержательная задача — **SQLB6 (задача коммивояжёра)** решается рекурсивным CTE: строится кратчайший маршрут по графу из 4 городов.

```sql
WITH RECURSIVE tsp AS (
    SELECT ARRAY['a','b']::varchar[] AS tour, 'b' AS last_city, cost, 2 AS visited
    FROM graph WHERE point1='a'
    UNION ALL
    SELECT tsp.tour || n.point2, n.point2, tsp.cost + n.cost, tsp.visited+1
    FROM tsp JOIN graph n ON n.point1 = tsp.last_city
    WHERE NOT (n.point2 = ANY(tsp.tour)) AND tsp.visited < 4
)
SELECT * FROM tsp;
```

## Как запускать

Проекты рассчитывались на PostgreSQL. Для полного воспроизведения нужен датасет с таблицами `person`, `menu`, `pizzeria`, `person_order` и т.д. — он не публикуется; скрипты решены под их схему.

---

*Практический трек по SQL: 100 упражнений, 12 блоков.*