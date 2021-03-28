# Write your MySQL query statement below
select name, (case when isnull(distance) then 0 else sum(distance) end) as 
    travelled_distance
from users left join rides on users.id=rides.user_id
group by users.id
order by travelled_distance desc, name asc