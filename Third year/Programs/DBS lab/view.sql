create view all_customer as
	(select branch_name, customer_name
	 from depositor, bank_account
	 where depositor.account_number =bank_account.account_number)
 union
	 (select branch_name, customer_name
	 from borrower, loan
	 where borrower.loan_number = loan.loan_number);

select customer_name
from all_customer
where branch_name = 'Panjim'