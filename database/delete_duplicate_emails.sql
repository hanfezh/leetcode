-- Delete Duplicate Emails.
-- Write a SQL query to delete all duplicate email entries in a table 
-- named Person, keeping only unique emails based on its smallest Id.
create table if not exists Person(Id int, Email nvarchar(256));
insert into Person(Id, Email) values (1, 'john@example.com');
insert into Person(Id, Email) values (2, 'bob@example.com');
insert into Person(Id, Email) values (3, 'john@example.com');

-- Write your MySQL query statement below
delete p1 from Person p1 inner join Person p2 on p1.Email = p2.Email where p1.Id > p2.Id;
