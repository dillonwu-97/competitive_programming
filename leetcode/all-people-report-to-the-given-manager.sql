# Write your MySQL query statement below
# with recursive cte as
# (
# select employee_id from employees where manager_id=1 and employee_id!=1
# union all
# select a.employee_id from employees a join cte b on (b.employee_id=a
    .manager_id) 
# )
# select employee_id from cte
with recursive emp_data as (
    select 
        employee_id
    from 
        employees
    where manager_id = 1 and employee_id != 1
    union all 
    select e.employee_id from employees e join emp_data c on (e.manager_id=c
        .employee_id)
    # Below statement won't work because we are using c.employee_id which 
        triggers and inf recursive call
    # select c.employee_id from employees e join emp_data c on (e.manager_id = 
        c.employee_id)    
)
select employee_id from emp_data;