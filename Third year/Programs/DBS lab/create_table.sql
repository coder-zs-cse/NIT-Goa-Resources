USE bank_database;
CREATE TABLE IF NOT EXISTS customer(
	customer_name VARCHAR(20) PRIMARY KEY,
    customer_street VARCHAR(20),
    customer_city VARCHAR(20)
);

CREATE TABLE IF NOT EXISTS branch(
	branch_name VARCHAR(20) PRIMARY KEY,
    branch_city VARCHAR(20),
    assets FLOAT(10)
);

CREATE TABLE IF NOT EXISTS bank_account(
	account_number INT(13) PRIMARY KEY,
	branch_name VARCHAR(20),
	balance FLOAT(10),
	FOREIGN KEY (branch_name) REFERENCES branch(branch_name)
);

CREATE TABLE IF NOT EXISTS depositor(
	customer_name VARCHAR(20),
    account_number INT(13),
    FOREIGN KEY (customer_name) REFERENCES customer(customer_name),
    FOREIGN KEY (account_number) REFERENCES bank_account(account_number)
 );
 
 CREATE TABLE IF NOT EXISTS loan(
	loan_number INT(9) PRIMARY KEY,
    branch_name VARCHAR(20),
    amount INT(9),
    FOREIGN KEY (branch_name) REFERENCES branch(branch_name)
);

CREATE TABLE IF NOT EXISTS borrower(
	customer_name VARCHAR(20),
	loan_number INT(9),
	FOREIGN KEY (customer_name) REFERENCES customer(customer_name),
	FOREIGN KEY (loan_number) REFERENCES loan(loan_number)
);
