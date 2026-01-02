# Write your MySQL query statement below
select firstname, lastName, city, state
from Person left join Address
on Person.personId = Address.personId