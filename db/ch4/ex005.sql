select product_id, sum(qty)
from production_history
group by product_id;


select *from production_history
where prod_date='2026-06-23';

SELECT product_id,
       SUM(qty)
FROM production_history
GROUP BY product_id;

SELECT *
FROM production_history
ORDER BY qty DESC;

INSERT INTO production_history
VALUES(5,1,200,'2026-06-24');

INSERT INTO production_history
VALUES(6,2,150,'2026-06-24');

INSERT INTO production_history
VALUES(7,3,90,'2026-06-24');

select *from production_history;

select sum(qty) from production_history;

select product_id, sum(qty)
from production_history
group by product_id;

select max(qty)
from production_history;




















