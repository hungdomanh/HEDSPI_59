
create table phong(
	map int not null primary key, 
	tenphong varchar(255) not null,
	gia1ngaydem int not null
);

create table khoadieutri(
	mak int not null primary key,
	khoa varchar(255) not null
);

create table thuoc(
	mat int not null primary key,
	thuoc varchar(255) not null,
	gia int not null
);

create table benh(
	mab int not null primary key,
	benh varchar(255) not null,
	mat int not null,
	foreign key (mat) references thuoc(mat)
);

create table bacsi(
	mabs int not null primary key,
	hoten varchar(255) not null,
	ngaysinh varchar(255) not null,
	gioitinh varchar(255) not null,
	diachi varchar(255) not null,
	mak int not null,
	kinhnghiem int,
	foreign key (mak) references khoadieutri(mak)
);

create table benhnhan(
	mabn int not null primary key,
	hoten varchar(255) not null,
	ngaysinh varchar(255) not null,
	gioitinh varchar(255) not null,
	diachi varchar(255) not null,
	dienthoai varchar(12) not null,
	trangthai int not null default 0
);

create table khambenh(
	makb int not null primary key,
	mabn int not null, 
	foreign key (mabn) references benhnhan(mabn),
	mabs int, 
	foreign key (mabs) references bacsi(mabs),
	map int, 
	foreign key (map) references phong(map),
	mab int,
	foreign key (mab) references benh(mab),
	trieuchung varchar(10000) not null,
	noidungkham varchar(10000),
	ngaydangki date not null,
	ngaynhankham date,
	ngaykham date,
	ngayravien date,
	tienthuoc int,
	tienphong int,
	tongchiphi int,
	trangthai int not null default 0
);

create table donthuoc(
	mat int not null,
	foreign key (mat)  references thuoc(mat),
	soluong int not null,
	gia int not null,
	makb int not null,
	foreign key (makb) references khambenh(makb)
);


create table user(
	id varchar(255) not null primary, 
	pass varchar(255) not null,
	type varchar(255) not null,
	more text
);



insert into users
values 
	('hung','1','boss',''),
	('lam','1','boss',''),
	('chinh','1','boss',''),
	('khanhhang','1','benhnhan',''),
	('nhanvien','1','bacsi','');


benhnhan.trangthai 	1.dang kham benh , 0.khoe manh
bacsi.trangthai  dang kham bao nhieu benh nhan

khambenh.trangthai 0.chua xuat vien, 1.da xuat vien
dangkikhambenh.trangthai 0.dang cho kham benh, 1.dang kham benh, 2.kham benh xong.



update khambenh set trangthai = 0;
update benhnhan set trangthai = 0;
update bacsi set trangthai = 0;
update phong set trangthai = 0;
delete from donthuoc;
delete from khambenh;
delete from benhan;
delete from khambenh;
trangthai dangkikhambenh:
	0. đang chờ khám
	1. đang khám
	2. đã khám chưa ra viện
	3. đã khám và ra viện rồi -> khoe manh




select hoten, mat, thuoc.thuoc, soluong, donthuoc.gia, makb from donthuoc left join thuoc using (mat) left join (select * from khambenh left join benhnhan using(mabn)) as t using(makb);

select makb, mabn, benhnhan.hoten as benhnhan, mabs, bacsi.hoten as bacsi, map, phong.phong, mab, benh.benh, ngaykham, noidung, khambenh.gia from khambenh left join benhnhan using (mabn) left join bacsi using (mabs) left join phong using (map) left join benh using(mab)


SELECT makb, khambenh.mabn, benhnhan.hoten as benhnhan, mabs, bacsi.hoten as bacsi, map, phong.phong, hoadon.tienphong, hoadon.tongchiphi, khambenh.mab, benh.benh, khambenh.ngaykham, khambenh.noidung, hoadon.tienthuoc, khambenh.trangthai from khambenh left join benhnhan using(mabn) left join bacsi using(mabs) left join phong using(map) left join benh using(mab) left join hoadon using(makb)  order by makb;

select * from dangkikhambenh left join khambenh using(madkkb) left join hoadon using(madkkb);
slide
http://www.bkosborne.com/jquery-waterwheel-carousel 


