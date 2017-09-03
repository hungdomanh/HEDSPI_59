CREATE VIEW prod_special AS
	SELECT prod_id, title, price
	FROM products
	WHERE special = 1 
;

CREATE VIEW prod_special_noUpdatable AS
	SELECT prod_id, title, price
	FROM products
	WHERE special = 1 limit 10;
;



CREATE FUNCTION updateviewSpecial() RETURNS TRIGGER AS
$$
BEGIN
	UPDATE products SET prod_id = new.prod_id,
						title = new.title, price = new.price
					WHERE prod_id = old.prod_id;
	RETURN  new;
END;
$$
LANGUAGE plpgsql;

-- trigger
CREATE TRIGGER tg_updateView
INSTEAD OF UPDATE ON prod_special_noUpdatable
FOR EACH ROW
EXECUTE PROCEDURE updateviewSpecial();

DELETE FROM prod_special_noUpdatable WHERE prod_id = 5; -- ko chay


----------

CREATE FUNCTION deleteviewSpecial() RETURNS TRIGGER AS
$$
BEGIN
	delete from products WHERE prod_id = old.prod_id;
	RETURN  NULL;
END;
$$
LANGUAGE plpgsql;

-- trigger
CREATE TRIGGER deleteView
INSTEAD OF delete ON prod_special_noUpdatable
FOR EACH ROW
EXECUTE PROCEDURE deleteviewSpecial();



DELETE FROM prod_special_noUpdatable WHERE prod_id = 5; --  chay
-- UPDATE prod_special_noUpdatable set price = 0 where 