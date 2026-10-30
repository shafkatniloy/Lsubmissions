# Write your MySQL query statement below
select  s.user_Id ,ROUND(coalesce(AVG(c.action = 'confirmed'),0), 2) AS confirmation_rate
from Signups s left join Confirmations c
on s.user_Id=c.user_Id
group by s.user_Id

