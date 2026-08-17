# Write your MySQL query statement below
SELECT 
    score,
    DENSE_RANK() OVER (ORDER BY score DESC) AS `rank` -- i used backticks because rank is a reserved keyword inside MYSQL
    -- use of dense rank is that ties share the same rank while the every row is numbered without skipping any numbers 
FROM 
    Scores;