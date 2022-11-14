USE BANK_DATABASE;

INSERT INTO customer VALUES ("Zubin", "Desainagar", "Sankhali");
INSERT INTO customer VALUES ("Souradeep", "St. John", "Panjim");
INSERT INTO customer VALUES ("Omkar", "Palkinagar", "Margao");

INSERT INTO branch VALUES ("Sankhali", "Sankhali", 1312.23);
INSERT INTO branch VALUES ("Margao", "Margao", 112.33);
INSERT INTO branch VALUES ("Panjim", "Panjim", 123.5);

INSERT INTO bank_account VALUES (123, "Margao", 123.4);
INSERT INTO bank_account VALUES (124, "Margao", 233.4);
INSERT INTO bank_account VALUES (125, "Margao", 834.4);

INSERT INTO depositor VALUES ("Omkar", 123);
INSERT INTO depositor VALUES ("Zubin", 124);
INSERT INTO depositor VALUES ("Souradeep", 124);

INSERT INTO loan VALUES (3223, "Sankhali", 23484);
INSERT INTO loan VALUES (3224, "Margao", 484);
INSERT INTO loan VALUES (3225, "Panjim", 894);

INSERT INTO borrower VALUES ("Zubin", 3223);
INSERT INTO borrower VALUES ("Souradeep", 3224);
INSERT INTO borrower VALUES ("Omkar", 3225);