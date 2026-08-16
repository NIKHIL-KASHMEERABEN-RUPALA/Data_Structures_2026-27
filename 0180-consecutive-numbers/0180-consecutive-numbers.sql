# Write your MySQL query statement below
WITH NumberSequence AS (
    SELECT 
        id,
        num,
        LEAD(num, 1) OVER (ORDER BY id) AS next_num,
        LEAD(num, 2) OVER (ORDER BY id) AS next_next_num,
        LEAD(id, 1) OVER (ORDER BY id) AS next_id,
        LEAD(id, 2) OVER (ORDER BY id) AS next_next_id
    FROM Logs
)
SELECT DISTINCT num AS ConsecutiveNums
FROM NumberSequence
WHERE num = next_num 
  AND num = next_next_num
  AND next_id = id + 1
  AND next_next_id = id + 2;