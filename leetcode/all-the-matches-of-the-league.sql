# Write your MySQL query statement below
select home_team, away_team
from 
    (
        select team_name as away_team
        from teams
    ) as t1 join 
    (
        select team_name as home_team
        from teams
    ) t2 on t2.home_team != t1.away_team