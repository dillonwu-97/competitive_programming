# Write your MySQL query statement below
select A.Id 
  from Weather A, Weather B
 where datediff(A.RecordDate, B.RecordDate) = 1 and A.Temperature > B
     .Temperature
                                            