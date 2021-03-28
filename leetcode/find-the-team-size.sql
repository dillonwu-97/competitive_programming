# Write your MySQL query statement below
select employee_id, team_size
from employee join (select team_id, count(team_id) as team_size from employee 
    group by team_id) as t using (team_id)