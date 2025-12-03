USE Tour
GO

DELETE FROM sale
WHERE date_sale BETWEEN '2024-01-16' AND '2024-01-25';

DELETE FROM marshrut
WHERE id_country = 11;

DELETE FROM client
WHERE email = 'ivanov.p@mail.ru';

DELETE FROM country
WHERE name_country = 'ื่๋่';

DELETE FROM country
WHERE cost_visa = 80.00;