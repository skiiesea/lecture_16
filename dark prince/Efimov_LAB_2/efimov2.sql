CREATE DATABASE Tour;

GO

USE Tour;

GO

CREATE TABLE country (
	name_country VARCHAR(100) PRIMARY KEY NOT NULL,
	cost_visa DECIMAL(10, 2) NOT NULL,
	capital VARCHAR(100) NOT NULL,
	languagee VARCHAR(50) NOT NULL,
	currency VARCHAR(20) NOT NULL,
);
CREATE TABLE route_ (
	name_route VARCHAR(255) NOT NULL,
	country VARCHAR(100) NOT NULL,
	duration_days INT NOT NULL,
	organizer VARCHAR(150) NOT NULL
);
CREATE TABLE client (
	full_name VARCHAR(200) PRIMARY KEY NOT NULL,
	phone_number VARCHAR(11) NOT NULL,
	email VARCHAR(50) NOT NULL,
	passport_data VARCHAR(100) NOT NULL,
	birth_day DATE NOT NULL
);

CREATE TABLE sale (
	number_contract VARCHAR(50) PRIMARY KEY NOT NULL,
	full_name_client VARCHAR(200) NOT NULL,
	name_route VARCHAR(255) NOT NULL,
	destination_country VARCHAR(100) NOT NULL,
	ticket_price DECIMAL(10, 2) NOT NULL,
	quantity_ticket INT NOT NULL,
	date_sale DATE NOT NULL,
	sales_manager VARCHAR(150) NOT NULL
);