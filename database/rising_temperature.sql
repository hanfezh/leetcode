-- Given a Weather table, write a SQL query to find all dates' Ids 
-- with higher temperature compared to its previous (yesterday's) dates.
Create table If Not Exists Weather (Id int, RecordDate date, Temperature int)
Truncate table Weather
insert into Weather (Id, RecordDate, Temperature) values ('1', '2015-01-01', '10')
insert into Weather (Id, RecordDate, Temperature) values ('2', '2015-01-02', '25')
insert into Weather (Id, RecordDate, Temperature) values ('3', '2015-01-03', '20')
insert into Weather (Id, RecordDate, Temperature) values ('4', '2015-01-04', '30')

-- Write your MySQL query statement below
select b.id from weather a inner join weather b on (date_add(a.recorddate, interval 1 day) = b.recorddate and a.temperature < b.temperature)
