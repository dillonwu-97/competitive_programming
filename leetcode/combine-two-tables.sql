# Write your MySQL query statement below
select distinct FirstName, LastName, City, State
from Person left join Address
on Person.PersonID = Address.PersonID