# Write your MySQL query statement below
select e1.name
from Employee as e1
inner join Employee as e2
where e1.id = e2.managerId
group by e1.id having count(e1.id)>=5;