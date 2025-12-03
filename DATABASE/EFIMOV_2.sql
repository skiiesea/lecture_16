USE Tour
GO

UPDATE client
SET email = 'new_email@example.com'
WHERE id_client = 1;

UPDATE country
SET cost_visa = cost_visa * 2
WHERE capital = 'Париж';

UPDATE marshrut
SET duration_days = 3
WHERE id_country = 13;

UPDATE sale
SET ticket_price = ticket_price + 100.0
WHERE destination_country = 'Россия';

UPDATE country
SET currency = 'Евро'
WHERE name_country = 'Украина';