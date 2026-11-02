# Write your MySQL query statement below
(select  u.name as results
from MovieRating m join Users u on m.user_id=u.user_id
group by m.user_id
order by count( m.user_id) desc,u.name
limit 1)
union all
(select mo.title
from MovieRating m join Movies mo on m.movie_id= mo.movie_id
where m.created_at>='2020-02-01' and m.created_at<='2020-02-29'
group by m.movie_id
order by avg(m.rating) desc, mo.title
limit 1)