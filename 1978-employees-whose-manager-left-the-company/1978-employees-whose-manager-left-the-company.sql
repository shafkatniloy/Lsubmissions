# Write your MySQL query statement below
select e2.employee_id
From Employees e1 right join Employees e2
on e1.employee_id=e2.manager_id
where e2.manager_id is not null and  e1.employee_id is  null and e2.salary <30000
ORDER BY e2.employee_id;