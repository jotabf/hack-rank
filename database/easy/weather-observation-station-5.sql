(
    select city, length(city) from station where length(city) = (
        select min(length(city)) from station
    ) order by city limit 1
)
union
(
    select city, length(city) from station where length(city) = (
        select max(length(city)) from station
    ) order by city limit 1
);