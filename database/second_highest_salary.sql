-- 176. Second Highest Salary
create table if not exists Employee (Id int, Salary int);
truncate table Employee;
insert into Employee (Id, Salary) values ('1', '100');
insert into Employee (Id, Salary) values ('2', '200');
insert into Employee (Id, Salary) values ('3', '300');

select (select distinct Salary from Employee order by Salary desc limit 1,1) as SecondHighestSalary;
