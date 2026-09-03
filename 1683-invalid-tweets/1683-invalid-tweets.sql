# Write your MySQL query statement below
SELECT tweet_id
FROM tweets
where CHAR_LENGTH(content) > 15;