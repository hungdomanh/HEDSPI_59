--check: kiem tra 1 rang buoc
--unique: kiem tra gia tri chi xuat hien 1 lan`

INSERT into store."Customer"("CustomerID", "LastName", "FirstName")
VALUES ('1', 'Ho1', 'Ten1'),
	   ('2', 'Ho2', 'Ten2'),
       ('3', 'Ho3', 'Ten3')
       ; 
SELECT * FROM store."Order"

INSERT INTO store."Order"("OrderID","CustomerID","ProductID")
    VALUES ('12', '1', '2'),
           ('23', '2', '3'),
           ('31', '3', '1')
           ; 

DELETE FROM store."Customer" WHERE "CustomerID" = '1';
UPDATE store."Customer" SET "LastName" = "Hero" WHERE "CustomerID"='2';

user:  barney 		pass: barney
Insert into recipes ("name", "ingredients", "directions") 
values ('hung','developer','text1'),
		('do','coder','text2');

SELECT is the clause you use every time you want to query information from a database.
WHERE is a popular command that lets you filter the results of the query based on conditions that you specify.
LIKE and BETWEEN are special operators that can be used in a WHERE clause
AND and OR are special operators that you can use with WHERE to filter the query on two or more conditions.
ORDER BY lets you sort the results of the query in either ascending or descending order.
LIMIT lets you specify the maximum number of rows that the query will return. This is especially important in large tables that have thousands or even millions of rows.

--COUNT
	SELECT COUNT(*) FROM fake_apps;
	SELECT COUNT(*) FROM fake_apps WHERE price = 0;
--GROUP BY	
	SELECT price, COUNT(*) FROM fake_apps GROUP BY price;  -- include distinct
	SELECT price, COUNT(*) FROM fake_apps WHERE downloads > 20000 GROUP BY price;
--SUM
	SELECT SUM(downloads) FROM fake_apps;
	SELECT category, SUM(downloads) FROM fake_apps GROUP BY category;
--MAX
	SELECT MAX(downloads) FROM fake_apps;
	SELECT name, category, MAX(downloads) FROM fake_apps GROUP BY category;
--MIN
	SELECT MIN(downloads) FROM fake_apps;
	SELECT name, category, MIN(downloads) FROM fake_apps GROUP BY category;
--AVG	Average
	SELECT AVG(downloads) FROM fake_apps;
	SELECT price, AVG(downloads) FROM fake_apps GROUP BY price;
--ROUND
	SELECT price, ROUND(AVG(downloads), 2) FROM fake_apps GROUP BY price;
	SELECT price, ROUND(AVG(downloads)) FROM fake_apps GROUP BY price;		lam chon all

	

--Multiple Tables 
--PRIMARY KEY  <duy nhất not NULL>
	CREATE TABLE artists(id INTEGER PRIMARY KEY, name TEXT);
--Foreign key  <do not need to be unique and can be NULL>
	SELECT albums.name, albums.year, artists.name FROM albums, artists;
--Cross Join
	SELECT  * FROM  albums JOIN artists ON albums.artist_id = artists.id;
--Inner Join
	SELECT  * FROM   albums LEFT JOIN artists ON albums.artist_id = artists.id;
--Left Outer Join
	SELECT
		  albums.name AS 'Album',
		  albums.year,
		  artists.name AS 'Artist'
		FROM 
		  albums
		JOIN artists ON
		  albums.artist_id = artists.id
		WHERE
		  albums.year > 1980;

--Table Transformation
--Non-conrrelated Subqueriens I
	SELECT * 
		FROM flights 
		WHERE origin in (
		    SELECT code 
		    FROM airports 
		    WHERE elevation > 2000);
--Non-conrrelated Subqueriens II
	SELECT * 
	FROM flights 
	WHERE origin in (
	    SELECT code 
	    FROM airports 
	    WHERE fac_type = 'SEAPLANE_BASE');
--Non-conrrelated Subqueriens III
      SELECT a.dep_month, a.deP_date,
	       a.dep_day_of_week,
	       AVG(a.flight_distance) AS average_distance
		  FROM (
		         SELECT flights.dep_month,      flights.dep_date,
		              flights.dep_day_of_week,
		         			Sum(flights.distance) AS flight_distance
		          FROM flights GROUP BY flights.dep_month,
		               flights.dep_date, flights.dep_day_of_week
		       ) a
		 GROUP BY 1,2
		 ORDER BY 1,a.dep_date;
--Correlated Subquery
	SELECT id
		FROM flights AS f
		WHERE distance < (
		SELECT AVG(distance)
		FROM flights
	 	WHERE carrier = f.carrier);
--Correlated Subquery II
	SELECT flights.origin, flights.id,
	    (
	      SELECT COUNT(*)
	      FROM flights f
	      WHERE f.id < flights.id
	      AND f.origin=flights.origin
	    ) + 1  AS flight_sequence_number
	FROM flights;
------------------- Subqueries are used to complete an SQL transformation by nesting one query within another query.

- A non-correlated subquery is a subquery that can be run independently of the outer query and can be used to complete a multi-step transformation.

- A correlated subquery is a subquery that cannot be run independently of the outer query. The order of operations in a correlated subquery is as follows:

1. A row is processed in the outer query.

2. Then, for that particular row in the outer query, the subquery is executed. ----------------------


--Table Transformation
	SELECT brand FROM legacy_products union SELECT brand FROM new_products;