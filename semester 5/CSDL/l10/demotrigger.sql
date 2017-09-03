CREATE OR REPLACE FUNCTION tg_checkquantity() RETURNS trigger AS
$$DECLARE
luongton int4;
luongcanthem int4;
BEGIN
	select into luongton quan_in_stock 
	from inventory
	where prod_id = NEW.prod_id;
	
	IF TG_OP = 'UPDATE' AND NEW.prod_id = OLD.prod_id THEN
		luongcanthem = NEW.quantity - OLD.quantity;
	ELSE
		luongcanthem = NEW.quantity;
	END IF;
	
	IF luongcanthem > luongton THEN
			RAISE NOTICE 'luong ton khong du';
			RETURN NULL;
	END IF;
	RETURN NEW;
END;
$$ LANGUAGE plpgsql VOLATILE;

CREATE TRIGGER tg_checkSL 
BEFORE INSERT OR UPDATE ON orderlines
FOR EACH ROW
EXECUTE PROCEDURE tg_checkquantity();

CREATE OR REPLACE FUNCTION tg_updateinventory() RETURNS trigger AS
$$DECLARE
oldquan int4;
oldsales int4;
BEGIN
	
		IF TG_OP = 'INSERT' THEN
			update inventory 
				set quan_in_stock = quan_in_stock - new.quantity, sales = sales + new.quantity 
			where prod_id = new.prod_id;
		END IF;
	RETURN NEW;
END;
$$ LANGUAGE plpgsqlVOLATILE;

-- Trigger: tg_insert on orderlines
-- DROP TRIGGER tg_insert ON orderlines;

CREATE TRIGGER tg_insert
  AFTER INSERT
  ON orderlines
  FOR EACH ROW
  EXECUTE PROCEDURE tg_updateinventory();
 
 --- ======================
 --- Test

Select * from inventory where prod_id = 1;
Select * from inventory where prod_id = 2;


Select * from orderlines where orderid = 1405;

insert into orderlines (orderlineid, orderid, prod_id, quantity, orderdate) values (8,1405, 1, 5, '2011-11-02');
--delete from orderlines where orderlineid = 8 and orderid = 1405;

--insert into orderlines (orderlineid, orderid, prod_id, quantity, orderdate) values (8,1405, 1, 5, '2011-11-02');
--update orderlines set quantity = 10 where orderlineid = 8 and orderid = 1405

--update orderlines set prod_id = 2 where orderlineid = 8 and orderid = 1405;
--delete from orderlines where orderlineid = 8 and orderid = 1405;

--select * from orderlines where orderlineid = 8 and orderid = 1405;
