# Write your MySQL query statement below
select name as "WAREHOUSE_NAME", sum(Width * Length * Height * units) as 
    "VOLUME"
from warehouse
left join products
using (product_id)
group by name