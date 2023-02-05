# Write your MySQL query statement below
select event_day as day, emp_id, sum(diff) as total_time
from (
    select event_day, emp_id, out_time - in_time as diff
    from employees
) as temp
group by event_day, emp_id