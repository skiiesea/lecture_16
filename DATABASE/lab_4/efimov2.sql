USE Tour
GO

SELECT 
    id_country AS 'ID страны',
    name_country AS 'Название страны',
    cost_visa AS 'Стоимость визы ($)',
    capital AS 'Столица',
    languagee AS 'Язык',
    currency AS 'Валюта'
FROM country;


SELECT 
    m.id_route AS 'ID маршрута',
    m.name_route AS 'Название маршрута',
    c.name_country AS 'Страна назначения',
    m.duration_days AS 'Длительность (дни)',
    m.organizer AS 'Организатор'
FROM marshrut m
INNER JOIN country c ON m.id_country = c.id_country;

SELECT 
    id_client AS 'ID клиента',
    full_name AS 'Полное имя',
    phone_number AS 'Номер телефона',
    email AS 'Электронная почта',
    passport_data AS 'Паспортные данные',
    birth_day AS 'Дата рождения'
FROM client;

SELECT 
    s.id_sale AS 'ID продажи',
    s.number_contract AS 'Номер договора',
    c.full_name AS 'Клиент',
    m.name_route AS 'Маршрут',
    s.destination_country AS 'Страна назначения',
    s.ticket_price AS 'Цена билета ($)',
    s.quantity_ticket AS 'Количество билетов',
    s.ticket_price * s.quantity_ticket AS 'Общая стоимость ($)',
    s.date_sale AS 'Дата продажи',
    s.sales_manager AS 'Менеджер по продажам',
    cnt.name_country AS 'Страна маршрута',
    cnt.cost_visa AS 'Стоимость визы ($)',
    m.duration_days AS 'Длительность тура (дни)',
    m.organizer AS 'Организатор тура'
FROM sale s
INNER JOIN client c ON s.id_client = c.id_client
INNER JOIN marshrut m ON s.id_route = m.id_route
INNER JOIN country cnt ON m.id_country = cnt.id_country;

SELECT 
    s.sales_manager AS 'Менеджер',
    COUNT(s.id_sale) AS 'Количество продаж',
    SUM(s.ticket_price * s.quantity_ticket) AS 'Общая выручка ($)',
    AVG(s.ticket_price) AS 'Средняя цена билета ($)'
FROM sale s
GROUP BY s.sales_manager;

SELECT 
    c.name_country AS 'Страна',
    COUNT(m.id_route) AS 'Количество маршрутов',
    c.cost_visa AS 'Стоимость визы ($)',
    c.capital AS 'Столица',
    c.currency AS 'Валюта'
FROM country c
LEFT JOIN marshrut m ON c.id_country = m.id_country
GROUP BY c.name_country, c.cost_visa, c.capital, c.currency
ORDER BY COUNT(m.id_route) DESC;

SELECT 
    c.full_name AS 'Клиент',
    c.phone_number AS 'Телефон',
    c.email AS 'Электронная почта',
    COUNT(s.id_sale) AS 'Количество покупок',
    SUM(s.ticket_price * s.quantity_ticket) AS 'Общая сумма покупок ($)',
    MAX(s.date_sale) AS 'Последняя покупка'
FROM client c
LEFT JOIN sale s ON c.id_client = s.id_client
GROUP BY c.full_name, c.phone_number, c.email
ORDER BY COUNT(s.id_sale) DESC;

SELECT 
    m.name_route AS 'Маршрут',
    c.name_country AS 'Страна',
    COUNT(s.id_sale) AS 'Количество продаж',
    SUM(s.quantity_ticket) AS 'Количество проданных билетов',
    AVG(s.ticket_price) AS 'Средняя цена ($)',
    SUM(s.ticket_price * s.quantity_ticket) AS 'Общая выручка ($)'
FROM marshrut m
INNER JOIN country c ON m.id_country = c.id_country
LEFT JOIN sale s ON m.id_route = s.id_route
GROUP BY m.name_route, c.name_country
ORDER BY COUNT(s.id_sale) DESC;

SELECT 
    s.number_contract AS 'Номер договора',
    s.date_sale AS 'Дата продажи',
    cl.full_name AS 'Клиент',
    cl.phone_number AS 'Телефон клиента',
    m.name_route AS 'Тур',
    cnt.name_country AS 'Страна тура',
    s.destination_country AS 'Назначение',
    m.duration_days AS 'Длительность (дней)',
    s.ticket_price AS 'Цена билета ($)',
    s.quantity_ticket AS 'Кол-во билетов',
    (s.ticket_price * s.quantity_ticket) AS 'Итого ($)',
    cnt.cost_visa AS 'Стоимость визы ($)',
    m.organizer AS 'Организатор',
    s.sales_manager AS 'Менеджер'
FROM sale s
INNER JOIN client cl ON s.id_client = cl.id_client
INNER JOIN marshrut m ON s.id_route = m.id_route
INNER JOIN country cnt ON m.id_country = cnt.id_country
ORDER BY s.date_sale DESC;