# Write your MySQL query statement below
select name as "Customers"
from customers C
where C.ID not in (select CustomerID
                  from Orders)