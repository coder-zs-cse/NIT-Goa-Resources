USE bank_database;
ALTER TABLE depositor
DROP CONSTRAINT depositor_ibfk_2;

ALTER TABLE depositor
ADD CONSTRAINT FOREIGN KEY (account_number) REFERENCES bank_account(account_number)
ON DELETE CASCADE;
 
DELETE FROM bank_account
WHERE branch_name="Margao";



