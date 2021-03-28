# Write your MySQL query statement below
# distinct name AND id
select schoola.student_name as 'member_A', schoolb.student_name as 'member_B', 
    schoolc.student_name as 'member_C'
from schoola, schoolb, schoolc
where schoola.student_id != schoolb.student_id and schoola.student_name != 
    schoolb.student_name
and schoola.student_id != schoolc.student_id and schoolb.student_id != schoolc
    .student_id and
schoola.student_name != schoolc.student_name and schoolc.student_name != 
    schoolb.student_name