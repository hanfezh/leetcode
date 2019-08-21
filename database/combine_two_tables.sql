-- 175. Combine Two Tables
create table Person (PersonId int, FirstName varchar(255), LastName varchar(255));
create table Address (AddressId int, PersonId int, City varchar(255), State varchar(255));
truncate table Person;
truncate table Address;
insert into Person (PersonId, LastName, FirstName) values ('1', 'Wang', 'Allen');
insert into Address (AddressId, PersonId, City, State) values ('1', '2', 'New York City', 'New York');

select p.FirstName, p.LastName, a.City, a.State from Person p left join Address a on p.PersonId = a.PersonId
