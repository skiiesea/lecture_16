
USE Tour

GO

CREATE TABLE country(
	id_country INT IDENTITY(1, 1) PRIMARY KEY NOT NULL,
	name_country VARCHAR(100) NOT NULL,
	cost_visa DECIMAL(10, 2) NOT NULL CHECK (cost_visa >= 0),
	capital VARCHAR(100) NOT NULL,
	languagee VARCHAR(50) NOT NULL,
	currency VARCHAR(20) NOT NULL,
);
CREATE TABLE marshrut (
	id_route INT IDENTITY(1, 1) PRIMARY KEY NOT NULL,
	name_route VARCHAR(255) NOT NULL,
	id_country INT NOT NULL,
	duration_days INT NOT NULL CHECK (duration_days > 0),
	organizer VARCHAR(150) NOT NULL,
	CONSTRAINT fk_marshrut_country
		FOREIGN KEY(id_country) REFERENCES country(id_country)

);

CREATE TABLE client (
	id_client INT IDENTITY(1,1) PRIMARY KEY,
	full_name VARCHAR(200) NOT NULL,
	phone_number VARCHAR(255) CHECK (phone_number LIKE '+[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]') NOT NULL,
	email VARCHAR(50) CHECK (email LIKE '_%@_%._%') NOT NULL,
	passport_data VARCHAR(100) NOT NULL,
	birth_day DATE NOT NULL
);

CREATE TABLE sale (
	id_sale INT IDENTITY(1,1) PRIMARY KEY,
	id_client INT NOT NULL,
	id_route INT NOT NULL,
	number_contract VARCHAR(50) NOT NULL,
	full_name_client VARCHAR(200) NOT NULL,
	name_route VARCHAR(255) NOT NULL,
	destination_country VARCHAR(100) NOT NULL,
	ticket_price DECIMAL(10, 2) NOT NULL CHECK (ticket_price >= 0),
	quantity_ticket INT NOT NULL CHECK (quantity_ticket > 0),
	date_sale DATE NOT NULL,
	sales_manager VARCHAR(150) NOT NULL,
	CONSTRAINT fk_sale_client
		FOREIGN KEY (id_client) REFERENCES client(id_client),
	CONSTRAINT fk_sale_marshrut
		FOREIGN KEY(id_route) REFERENCES marshrut(id_route)
		
);
