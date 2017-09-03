--(
--	cmd
--	cd C:..\..\bin
--	dropdb -U postgres sisinfo
--	psql -U postgres -d sisinfo -f ...\sisinfo.sql
--)
-- xóa database 
-- drop database sisinfo;
-- tạo database 
create database sisinfo;

-- connect vào database sisinfo
\connect sisinfo 
-- chuyen connect tới CSDL vừa tạo, đây là lệnh dùng cho psql. Nếu dùng pgAmdin thì chỉ cần chọn kết nối lại tren giao diện bảng cách click vào database đó thôi.

-- tạo bảng sinh viên
create table student(
	id char(4) not null,
	name varchar(20) not null,
	suburb varchar(25),
	constraint pk_stu primary key (id)
);

-- tạo bảng course
create table course
(
	no char(3) not null,
	name varchar(10) not null,
	dept varchar(20) not null,
	constraint pk_crs primary key (no)
);

-- tạo bảng enrol cùng các khóa chính, khóa ngoài
create table enrol (
	sid char(4) not null,
	course char(3) not null,
	constraint pk_enrol primary key (sid, course),
	constraint fk_2student foreign key (sid) references student(id),
	constraint fk_2course foreign key (course) references course(no)
);
-- thêm dữ liệu vào bảng student
insert into student(id, name, suburb) values ('1108', 'Robert', 'Kew');
insert into student(id, name, suburb) values ('3936', 'Glen', 'Bundoora');
insert into student(id, name, suburb) values ('8507', 'Normal', 'Bundoora');
insert into student(id, name, suburb) values ('8452', 'Mary', 'Balawyn');

-- thêm dữ liệu vào bảng course
insert into course(no, name, dept) values ('113', 'BCS', 'CSCE');
insert into course(no, name, dept) values ('101','MCS', 'CSCE');

-- thêm dữ liệu vào bảng enrol (sv có thể thử thêm DL vào bảng enrol trước bảng course để xem kết quả)
insert into enrol(sid, course) values 
('3936', '101'), 
('1108', '113'), 
('8507', '101'); 

-- tao bảng takes, chưa có khóa ngoài
create table takes(
	sid char(4) not null,
	sno char(2) not null,
	constraint pk_tks primary key (sid, sno)
);
-- tạo bảng subject, chưa có khóa chính
create table subject (
	no char(2) not null,
	name varchar(20) not null,
	dept varchar(25)
);
-- thêm ràng buộc khóa chính cho bảng subject
alter table subject add constraint pk_sbj primary key (no);

-- thêm khóa ngoài cho bảng takes
alter table takes add constraint fk_tks2stu foreign key (sid) references student(id);
alter table takes add constraint fk_tks2sbj foreign key (sno) references subject(no);

-- thêm DL vào bảng subject
insert into subject(no, name, dept) values 
('21', 'Systems', 'CSCE'), 
('23', 'Database', 'CSCE'), 
('29', 'VB', 'CSCE'),
('18', 'Algebra', 'Maths');

-- thêm dữ liệu vào bảng takes
insert into takes(sid, sno) values 
('1108', '21'),
('1108', '23'),
('1108', '29'),
('8507', '23'),
('8507', '29');