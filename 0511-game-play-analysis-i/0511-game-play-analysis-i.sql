# Write your MySQL query statement below
WITH 
    RankedActivity 
AS (
    SELECT 
        player_id,
        event_date as first_login,
        ROW_NUMBER() OVER (PARTITION BY player_id ORDER BY event_date) as rn
    FROM
        Activity
    )
SELECT 
    player_id, first_login
FROM 
    RankedActivity 
WHERE 
    rn = 1;