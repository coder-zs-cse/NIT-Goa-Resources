-- find the names of all branches where average bank account balance is more than Rs 200

SELECT branch_name, ROUND(avg(balance),2) as Average_Balance
FROM bank_account
GROUP BY branch_name;
-- HAVING avg(balance) > 200; 

--find the max balance in each branch 

SELECT branch_name, max(balance) as Maximum_Balance
FROM bank_account
GROUP BY balance;

-- find the min balance in each branch 

SELECT branch_name, min(balance) as Minimum_Balance
FROM bank_account
GROUP BY balance;

-- find the total debt amount loaned in each branch  

SELECT branch_name, sum(amount)
FROM loan
GROUP BY branch_name;

-- find the count of total accounts, total loan_ids in each branch 

WITH accounts as (SELECT branch_name, count(*) NumberOfAccounts
FROM bank_account
GROUP BY 1),
loans AS (
SELECT branch_name, count(*) NumberOfLoanId
FROM loan
GROUP BY 1)

SELECT a.branch_name, a.NumberOfAccounts, l.NumberOfLoanId
FROM accounts a, loans l
WHERE a.branch_name=l.branch_name
ORDER BY l.NumberOfLoanId DESC;
-- SELECT a.branch_name, NumberOfAccounts, NumberOfLoanId
-- FROM accounts a
-- JOIN
-- loans l
-- ON a.branch_name = l.branch_name;


