-- find all customers who have a loan at the bank but don't have an account at bank
-- nested queries, use of not in operator

USE bank_database;
SELECT DISTINCT customer_name
FROM borrower
WHERE customer_name NOT IN  ( SELECT customer_name FROM depositor );

-- find all customers who have both an account and loan at the Margao Branch 
-- Use of IN operator

SELECT customer_name
FROM bank_account left join depositor
ON bank_account.account_number = depositor.account_number
WHERE branch_name='Margao' AND (branch_name, customer_name) IN 
(SELECT branch_name, customer_name
FROM loan left join borrower
ON loan.loan_number = borrower.loan_number);


-- Find all branches that have greater assets than some branch located in Margao.
-- use of some operator

select branch_name
from branch
where assets > some
(select assets
from branch
where branch_city = 'Margao');

-- Find the names of all branches that have greater assets than all branches located in Panjim.
-- use of all operator

select branch_name
from branch
where assets > all
(select assets
from branch
where branch_city = 'Panjim');


-- Find all customers who have an account at all branches located in Margao.
-- use of exists operator

SELECT customer_name
FROM depositor 
WHERE EXISTS (
SELECT 
)

select distinct S.customer_name
from depositor as S
where not exists (
(select branch_name
from branch
where branch_city = 'Margao') 
NOT IN 
(select R.branch_name
from depositor as T, account as R
where T.account_number = R.account_number and
S.customer_name = T.customer_name ))