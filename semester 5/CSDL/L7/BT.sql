1 Đưa ra danh sách phân loại sản phẩm (categories)
select categoryname from categories;

2 Đưa ra danh sách các sản phẩm thuộc loại “Documentary”
select * from Products where category in 
(select category from categories where categoryname='Documentary');

3 Đưa ra danh sách các loại sản phẩm và số lượng sản phẩm thuộc từng loại
select * from categories join
(select category, count(*) from Products group by category order by category) as t using (category) ;

4 Đưa ra danh sách các sản phẩm chưa được đặt hàng
(select prod_id from Products) EXCEPT (select prod_id from Orderlines);

5 Đưa ra danh sách các nước có khách hàng
select distinct country from Customers;

6 Đưa ra danh sách các nước có khách hàng và số lượng khách hàng của từng nước
select country, count(*) as so_khach_hang from Customers group by country;

7 Đưa ra danh sách khách hàng chưa từng đặt hàng
(select customerid from Customers) EXCEPT (select customerid from Orders);

8 Thống kê số đơn đặt hàng theo ngày
select orderdate, count(*) as so_luong from Orders group by orderdate order by so_luong DESC;

9 Thống kê số lượng sản phẩm đặt trong ngày 3/2/2004
select prod_id, sum(quantity) as tong
from Orderlines
where orderdate ='2004-02-03'
group by prod_id
order by tong DESC;

10 Thống kê giá trị trung bình các đơn đặt hàng
select AVG(totalamount) from Orders;

11 Đưa ra danh sách các sản phẩm được đặt nhiều nhất
select prod_id from (select prod_id, count(*) as so_luong from Orderlines group by prod_id) as t
where t.so_luong in (select max(t.so_luong) from
(select prod_id, count(*) as so_luong from Orderlines group by prod_id) as t);

12 Đưa ra danh sách khách hàng thường xuyên 
select * from Customers join
(select customerid, count(*) as so_luong from Orders group by customerid  order by so_luong DESC limit 10) as t using (customerid);

13 Có bao nhiêu khách hàng có thẻ tín dụng hết hạn trong tháng 09/2008
select 	count(*) from Customers where creditcardexpiration = '2008/09';

14 Hãy đưa ra các dòng chi tiết cho một đơn đặt hàng có mã số
942, trong đó cần hiển thị số dòng, mã số mặt hàng, tên mặt
hàng, đơn giá của mặt hàng và thành tiền của từng mặt hàng
trong đơn hàng đó. Với giá tiền và thành tiền, thêm đơn vị đo
lường tiền tệ vào kết quả
select t.orderlineid, t.prod_id, Products.title, t.quantity, (Products.price || '$') as price, (t.totalamount || '$') AS MONEY from
(
(select orderlineid, prod_id, quantity, totalamount,orderid from (Orders join Orderlines using (orderid)))  as t
join Products using (prod_id)
) 
where t.orderid ='942';

15 Khách hàng có mã số 19887 đã từng đặt bao nhiêu đơn hàng  
select count(*)  from orders where customerid='19887';

16 Cho biết họ tên, địa chỉ liên hệ , email , phone của các 
khách hàng có đặt từ 4 đơn hàng trở lên. 
select firstname, lastname, city, country, email, phone 
from Customers where customerid in
(select customerid  from orders group by customerid having count(customerid) > 3);

17 Đơn hàng có giá trị lớn nhất của khách hàng 19887 
được đặt vào ngày nào, với giá trị cụ thể là bao nhiêu 
select customerid, orderdate, totalamount from 
orders where totalamount = (select max(totalamount) 
from (select totalamount from orders where customerid='19887') as t);

18 Đưa ra tên, email của những khách hàng đã 
từng đặt mặt hàng AFFAIR ALAMO vói số lượng lớn nhất 
with t as(
	select * from Orderlines where prod_id = 
	(select prod_id from products where title='AFFAIR ALAMO')
)
select firstname, lastname, email from Customers where customerid in (
	select customerid from orders where orderid in (
		select orderid from  t
		where quantity = (select max(quantity) from t)
	)
);
-- Cách khác
with tmp as(
	select sum(quantity) as totalquantity, customerid from Orders natural join Orderlines ol natural join Products p 
	where  title='AFFAIR ALAMO'
	group by customerid
)
select firstname, lastname, email 
from Customers 
where customerid in (
	select customerid from tmp where totalquantity = (select max(totalquantity) from tmp)
	)
;

19 Đưa ra một thống kê về khách hàng đã từng đặt hàng
như sau với từng mặt hàng, với từng giới tính của khách hàng, 
cho biết có bao nhiêu người đặt hàng, độ tuổi và 
thu nhập trung bình của họ là bao nhiêu 
with tmp as (
	select distinct prod_id, c.customerid, age, income, gender
	from Orderlines l, orders o, customers as c 
	where o.orderid = l.orderid and c.customerid = o.customerid 
)
select prod_id, gender, count(distinct tmp.customerid), avg(age), avg(income) 
from tmp
group by prod_id, gender
order by prod_id, gender
limit 100;
-- Ket qua giong nhau
select prod_id, gender, count(distinct c.customerid), avg(age), avg(income) 
from Orderlines ol, orders o, customers as c 
where o.orderid = ol.orderid and c.customerid = o.customerid 
group by prod_id, gender
limit 100;

20. Mặt hàng nào là mặt hàng được khách hàng là nam giới, 
có thu nhập trên 65000 đã từng đặt mua. 
Với mỗi mặt hàng, đưa ra tổng số lượng hàng được đặt và 
sắp xếp kết quả theo chiều giảm dần của số lượng đặt 
select p.prod_id, p.title, sum(quantity)
from Products p, orders o, orderlines ol, customers as c
where p.prod_id = ol.prod_id and o.orderid = ol.orderid
	and c.customerid = o.customerid and gender='M'
	and income > 65000
group by p.prod_id
order by sum(quantity) desc;


21. Tạo lập một bảng high_price_products có cấu trúc giống như bảng products 
drop table if exists high_price_products;
create table high_price_products as 
	select * from products where 1=2;

create table high_price_products as 
	table products
	with no data;

22. Hãy thêm vào trong bảng high_price_products tất cả những mặt hàng có trong products mà giá tiền của mặt hàng đó là lớn hơn 21.99  
insert into high_price_products(prod_id, category, title, actor, price, special, common_prod_id)
	select prod_id, category, title, actor, price, special, common_prod_id
	from products
	where price > 21.99;
-- cach khac
insert into high_price_products
	select * 
	from products
	where price > 21.99;

23. Các mặt hàng đang có category 1 sẽ chuyển hết thành category 2 
update high_price_products
	set category = 2
	where category = 1;

24. Các mặt hàng có giá = 29.99 đều trở thành mặt hàng special 
update high_price_products
	set special = 1
	where price = 29.99;

25. Các mặt hàng có giá trong khoảng 23.00 đến 26.99 đều tăng giá thêm 1 đơn vị 
update high_price_products
	set special = special + 1
	where price = 29.99;

26. Xóa các mặt hàng có giá < 23.00 
delete from ......

27. Xóa bảng high_price_products 















select prod_id, gender, count(distinct c.customerid), avg(age)as tuoiTB, avg(income) as ThuNhapTB 
from Orderlines ol, orders o, customers as c 
where o.orderid = ol.orderid and c.customerid = o.customerid 
group by prod_id, gender, c.customerid;





with a as (
	select orderid from (
		Orderlines join (
			select * from Orders join Customers using (customerid) 
		) as t	using (orderid)
	) as t group by orderid;
)
select a.prod_id, a.orderid 
from a 
where orderid =''; 


select orders.orderid, customers.gender from orders left join customers using (customerid) order by orders.orderid;

group by a.orderid;
DESC
-- group by orderid;
;

select orderid, orderlines.prod_id from orders join orderlines using (orderid) order by orderid;





Categories(category, categoryname)

cust_hist(customerid, orderid, prod_id)

Customers(customerid, firstname, lastname, address1,
	address2, city, state, zip, country, region, email,
	phone, creditcardtype, creditcard,
	creditcardexpiration, username, password, age, income,
	gender
)

Inventory(prod_id, quan_in_stock,sales)

Orderlines(orderlineid, orderid, prod_id, quantity, orderdate)

Orders(orderid, orderdate, customerid, netamount, tax, totalamount)

Products(prod_id, category, title, actor, price, special, common_prod_id)





