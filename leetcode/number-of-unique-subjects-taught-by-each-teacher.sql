# Write your MySQL query statement below
select teacher_id, count(cnt) as cnt
from (
    select teacher_id, count(subject_id) as cnt
    from teacher
    group by teacher_id, subject_id
) as temp
group by teacher_id