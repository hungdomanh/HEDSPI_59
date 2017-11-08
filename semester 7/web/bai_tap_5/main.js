var bai1 = $('#bai_1');
var bai2 = $('#bai_2')
var bai3 = $('#bai_3')
var bai4 = $('#bai_4')
var bai5 = $('#bai_5')
var bai6 = $('#bai_6')
var bai7 = $('#bai_7')
var bai8 = $('#bai_8')
var bai9 = $('#bai_9')
var bai10 = $('#bai_10')
var bai11 = $('#bai_11')
var bai = $('#bai_')

bai1.find('.btn-welcome').click(function(){
	alert(bai1.find('input').val());
})

bai2.find('.btn-blue').click(function(){
	bai2.css('background', 'blue');
})
bai2.find('.btn-red').click(function(){
	bai2.css('background', 'red');
})

bai3.find('select').change(function(){ 
    var value = $(this).val();
  	bai3.css('background', value);  
});

bai4.find('#noiDung').on('change input paste keyup', function(){
	bai4.find('#soKyTu').val($(this).val().length);
})


bai6.find('#donGia, #soLuong, #thanhTien').on('change input paste keyup', function(){
	bai6.find('#thanhTien').val(bai6.find('#soLuong').val() * bai6.find('#donGia').val());
})

bai7.find('.btn-default').on('click', function(){
	document.write("<b>"+bai7.find('.name').val()+"</b> <u>"+bai7.find('.age').val()+"</u>");
})

bai8.find('.btn-default').on('click', function(){
	var page = bai8.find('.page-number').val();
	if (page == 1) {
		window.open('http://www.facebook.com');
	} else if (page == 2) {
		window.open('http://www.hust.edu.vn');
	} else {
		window.open('http://www.google.com');
	}
})

// bai9
function updateTitle(){
	var d = new Date();
	document.title = d.getHours() +"h : "+ d.getMinutes() +"m";
}
updateTitle();
bai9.find('.btn-default').on('click', function(){
	updateTitle();
})
////

bai10.find('input').on('change input paste keyup', function(){
	bai10.find('.show').html(2017 - bai10.find('input').val());
});

// bai 11
function getValue(){

	var a = Number(bai11.find('.el1').val());
	var b = Number(bai11.find('.el2').val());
	var sign = bai11.find('.btn.active').html();

	if (sign == '+') {
		return	a+b;
	} else if (sign == '-') {
		return	a-b;
	} else if (sign == '*') {
		return	a*b;
	} else if (sign == '/') {
		return	a/b;
	} else if (sign == '^') {
		return	Math.pow(a,b);
	}
}

function calculator(result) {
	bai11.find('.result').val(result);
}


bai11.find('.btn').on('click', function(){
	$(this).addClass('active').siblings().removeClass('active');
	calculator(getValue());
})
bai11.find('input').on('change input paste keyup', function(){
	calculator(getValue());	
})

////