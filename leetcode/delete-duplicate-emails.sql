# Write your MySQL query statement below
delete from Person
where Person.Id not in (select *
                        from (select min(A.Id)
                from Person A
                group by A.Email) as B)
                    