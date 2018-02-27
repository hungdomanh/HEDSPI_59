
-- Tạo bảng

CREATE TABLE lop (
    malop character(5) NOT NULL,
    tenlop character varying(20) NOT NULL,
    khoavien character varying(20),
    khoa smallint,
    tssv integer
);

CREATE TABLE sinhvien (
    mssv character(10) NOT NULL,
    hoten character varying(30) NOT NULL,
    gioitinh character(1),
    ngaysinh date,
    quequan character varying(40),
    malopql character(5),
    CONSTRAINT chk_gtinh CHECK (((gioitinh = 'F'::bpchar) OR (gioitinh = 'M'::bpchar)))
);


INSERT INTO lop VALUES ('L01  ', 'CNTT 2', NULL, NULL, 2);
INSERT INTO lop VALUES ('L02  ', 'CNTT 4', NULL, NULL, 3);

INSERT INTO sinhvien VALUES ('SV003     ', 'Ng V b', 'M', NULL, 'HN', 'L02  ');
INSERT INTO sinhvien VALUES ('sv003     ', 'B. T. BB', 'F', NULL, NULL, 'L02  ');
INSERT INTO sinhvien VALUES ('sv004     ', 'ab c', 'F', NULL, ' ', 'L01  ');
INSERT INTO sinhvien VALUES ('sv005     ', 'ab c', 'F', NULL, ' ', 'L02  ');
INSERT INTO sinhvien VALUES ('SV010     ', 'Tran Van Bach', 'F', '2010-09-12', 'HN', 'L01  ');

ALTER TABLE ONLY lop
    ADD CONSTRAINT pk_lop PRIMARY KEY (malop);

ALTER TABLE ONLY sinhvien
    ADD CONSTRAINT pk_sv PRIMARY KEY (mssv);
	
ALTER TABLE ONLY sinhvien
    ADD CONSTRAINT fk_sv_lop FOREIGN KEY (malopql) REFERENCES lop(malop);

-- Triggers
CREATE FUNCTION trg_function_sv() RETURNS trigger
    LANGUAGE plpgsql
    AS $$
BEGIN
	IF TG_OP = 'INSERT' THEN
		update LOP set TSSV = TSSV + 1
		where Malop = NEW.MaLopQL;
	ELSIF TG_OP = 'DELETE' THEN
		update LOP set TSSV = TSSV - 1
		where Malop = OLD.MaLopQL;
	ELSIF (TG_OP = 'UPDATE') AND (NEW.MaLopQL != OLD.MaLopQL) THEN
		update LOP set TSSV = TSSV + 1
		where Malop = NEW.MaLopQL;
		
		update LOP set TSSV = TSSV - 1
		where Malop = OLD.MaLopQL;
	END IF;
	RETURN NEW;
END;
$$;

CREATE TRIGGER tg_update_tssv AFTER INSERT OR DELETE OR UPDATE ON sinhvien FOR EACH ROW EXECUTE PROCEDURE trg_function_sv();




