USE Tour;

GO

ALTER TABLE country ADD CONSTRAINT chk_cost_visa CHECK (cost_visa >= 0);
ALTER TABLE route_ ADD CONSTRAINT chk_duration CHECK (duration_days > 0);
ALTER TABLE sale ADD CONSTRAINT chk_ticket_price CHECK (ticket_price >= 0);
ALTER TABLE sale ADD CONSTRAINT chk_quantity_ticket CHECK (quantity_ticket >= 0);

ALTER TABLE route_ ADD CONSTRAINT fk_route_country FOREIGN KEY (country_id) REFERENCES country(id_country);
ALTER TABLE sale ADD CONSTRAINT fk_sale_client FOREIGN KEY (full_name_client) REFERENCES client(full_name);
ALTER TABLE sale ADD CONSTRAINT fk_sale_route FOREIGN KEY (name_route, destination_country) REFERENCES route_travel(name_route, country_id);