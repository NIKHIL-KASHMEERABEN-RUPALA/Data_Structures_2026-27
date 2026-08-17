# Write your MySQL query statement below
SELECT 
    score,
    DENSE_RANK() OVER (ORDER BY score DESC) AS `rank` -- i used backticks because rank is a reserved keyword inside MYSQL
FROM 
    Scores;