# Write your MySQL query statement below
select e.name as Employee from employee e where salary > 
(select salary from employee e2 where e.managerId=e2.id);