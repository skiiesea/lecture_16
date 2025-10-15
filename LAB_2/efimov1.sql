CREATE DATABASE Tour;

GO

USE Tour;

GO

CREATE TABLE country (
	name_country VARCHAR(100) PRIMARY KEY,
	cost_visa DECIMAL(10, 2) NOT NULL CHECK (cost_visa >= 0),
	capital VARCHAR(100) NOT NULL,
	languagee VARCHAR(50) NOT NULL,
	currency VARCHAR(20) NOT NULL,
);
CREATE TABLE route_ (
	name_route VARCHAR(255) NOT NULL,
	country VARCHAR(100) NOT NULL,
	duration_days INT NOT NULL CHECK (duration_days > 0),
	organizer VARCHAR(150) NOT NULL,
	PRIMARY KEY(name_route, country),
	CONSTRAINT fk_route_country
		FOREIGN KEY(country) REFERENCES country(name_country)

);
CREATE TABLE client (
	fcs VARCHAR(200) PRIMARY KEY,
	phone_number VARCHAR(11) CHECK (phone_number LIKE '+[0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9][0-9]') NOT NULL,
	email VARCHAR(50) CHECK (email LIKE '_%@_%._%') NOT NULL,
	passport_data VARCHAR(100) NOT NULL,
	birth_day DATE NOT NULL
);

CREATE TABLE sale (
	number_contract VARCHAR(50) PRIMARY KEY NOT NULL,
	fcs_client VARCHAR(200) NOT NULL,
	name_route VARCHAR(255) NOT NULL,
	destination_country VARCHAR(100) NOT NULL,
	ticket_price DECIMAL(10, 2) NOT NULL CHECK (ticket_price >= 0),
	quantity_ticket INT NOT NULL CHECK (quantity_ticket > 0),
	date_sale DATE NOT NULL,
	sales_manager VARCHAR(150) NOT NULL,
	CONSTRAINT fk_sale_client
		FOREIGN KEY(fcs_client) REFERENCES client(fcs),
	CONSTRAINT fk_sale_route
		FOREIGN KEY(name_route, destination_country) REFERENCES route_(name_route, country)
);