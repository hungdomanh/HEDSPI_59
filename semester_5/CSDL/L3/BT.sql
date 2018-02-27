-- Bai tap . This is comment

1.
SELECT * FROM public."GiangVien"
where "DiaChi" like 'Hai Bà Trưng%' order by "HoTen" DESC;

2.
Select "GiangVien"."HoTen", "GiangVien"."DiaChi", "GiangVien"."NgaySinh"
from "GiangVien" natural join "ThamGia" natural join "DeTai"
where "DeTai"."TenDT" ='Tính toán lưới';

3.
Select "GiangVien"."HoTen", "GiangVien"."DiaChi", "GiangVien"."NgaySinh"
from "GiangVien" natural join "ThamGia" natural join "DeTai"
where "DeTai"."TenDT" ='Phân loại văn bản' or "DeTai"."TenDT" ='Dịch tự động Anh Việt';

7.
SELECT "GiangVien"."HoTen", "GiangVien"."NgaySinh", "DeTai"."TenDT" 
FROM "GiangVien" natural join "ThamGia" natural join "DeTai"
where "GiangVien"."DiaChi"='Tây Hồ, Hà Nội';
//hoặc
SELECT "HoTen", "NgaySinh", "TenDT" 
FROM "GiangVien" natural join "ThamGia" natural join "DeTai"
where "DiaChi"='Tây Hồ, Hà Nội';

10.
Insert into "GiangVien" ("GV#", "HoTen","DiaChi", "NgaySinh")
values ('GV06', 'Ngô Tuấn Phong', 'Đống Đa, Hà Nội', '09-08-1986');

11.
update "GiangVien" 
set "DiaChi" = 'Tây Hồ, Hà Nội' 
where "HoTen"='Vũ Tuyết Trinh';

12.
delete * from "ThamGia"
	where "GV#" ='GV02';

delete from "GiangVien"
	where "GV#" ='GV02';


Hàm trong SQL