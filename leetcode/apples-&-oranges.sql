# Write your MySQL query statement below
# using sum and case
# select sale_date, sum(case when fruit='apples' then sold_num when fruit
    ='oranges' then -sold_num else 0 end) as diff from Sales 
select sale_date, sum(case when fruit="apples" then sold_num when fruit
    ="oranges" then -sold_num else 10000 end) as diff 
from sales
group by sale_date
# select app.sale_date, (app.sold_num - ora.sold_num) as diff
# from 
#     (select sale_date, sold_num
#     from sales
#     where fruit = "oranges"
#     ) as ora join 
#     (select sale_date, sold_num
#     from sales
#     where fruit = "apples"
#     ) as app on app.sale_date = ora.sale_date
# # group by app.sale_date