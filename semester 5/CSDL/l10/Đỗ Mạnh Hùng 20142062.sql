

1. danh sach cac mat hang thuoc loai special

select * from products where special = 1;

2. 

select categoryname, count from (select category, count(*) from products group by category order by count DESC) as t left join categories using(category);

3.

select title, quan_in_stock, sales from inventory left join products using(prod_id) order by quan_in_stock DESC;

4.

select * from inventory left join products using(prod_id) where sales = 0;

5.

with t as  ( 
	select customerid, sum(totalamount) from (select * from orders left join customers using(customerid)) as t1 group by customerid
	)
select * from  t where sum > 1000000 ;

6.

with t as (
	select prod_id, count(*) from orderlines where orderdate = NOW() group by prod_id
	)
select * from t left join products using(prod_id)
;

7.
select * from products where price in
(select min(price) from products);

8.

with t as (
	select * from orders left join orderlines using(orderid) where date_part('year', orders.orderdate) = '2004'
	)
select prod_id, category, title, actor, price from products where prod_id in (select prod_id from (select prod_id, count(customerid) from t group by prod_id order by count DESC limit 10));





CREATE FUNCTION checkInsertOrders() RETURNS TRIGGER AS
$$
BEGIN
	if new.totalamount = new.netamount + new.tax then 
		RETURN  NEW;
	else
	RETURN  NULL;
	END IF;
END;
$$
LANGUAGE plpgsql;

-- trigger
CREATE TRIGGER tg_checkInsertOrders
BEFORE INSERT ON orders
FOR EACH ROW
EXECUTE PROCEDURE checkInsertOrders();












