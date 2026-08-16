# Write your MySQL query statement below
-- select 
--     email as Email
-- from 
--     Person 
-- group by 
--     email
-- having 
--     count(email) > 1


select Distinct
    p.email as Email 
from 
    Person p
inner join 
    Person d
on 
    p.email = d.email
    and p.id != d.id