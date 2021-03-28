# Write your MySQL query statement below
select Name as "Employee"
from employee E
where E.salary > (select salary
                    from employee M
                    where E.ManagerId = M.Id)