USE Tour;

GO

ALTER TABLE country ADD CONSTRAINT chk_cost_visa CHECK (cost_visa >= 0);
ALTER TABLE route_ ADD CONSTRAINT chk_duration CHECK (duration_days > 0);
ALTER TABLE sale ADD CONSTRAINT chk_ticket_price CHECK (ticket_price >= 0);
ALTER TABLE sale ADD CONSTRAINT chk_quantity_ticket CHECK (quantity_ticket >= 0);

ALTER TABLE route_ ADD CONSTRAINT fk_route_country FOREIGN KEY (country) REFERENCES country(name_country);
ALTER TABLE sale ADD CONSTRAINT fk_sale_client FOREIGN KEY (fcs_client) REFERENCES client(fcs);
ALTER TABLE sale ADD CONSTRAINT fk_sale_route FOREIGN KEY (name_route, destination_country) REFERENCES route_(name_route, country);