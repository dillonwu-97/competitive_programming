# Write your MySQL query statement below
select date_format(`order_date`, '%Y-%m') as month, count(distinct order_id) as 
    order_count, count(distinct customer_id) as customer_count
from orders
where invoice > 20
group by 1
# DATE_FORMAT(`date`, '%d-%m-%Y')