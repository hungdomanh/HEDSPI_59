var page = 1;
// $(function() {
    var getUrlParameter = function (sParam) {
        var sPageURL = decodeURIComponent(window.location.search.substring(1)),
            sURLVariables = sPageURL.split('&'),
            sParameterName,
            i;

        for (i = 0; i < sURLVariables.length; i++) {
            sParameterName = sURLVariables[i].split('=');

            if (sParameterName[0] === sParam) {
                if (sParameterName[1] === undefined) {
                    return 1;
                }
                return sParameterName[1];
            }
        }
    };

    page = getUrlParameter('page');
    if (page == 1 || !page) {
        page = 1;
        $('.btn-back').addClass("disabled");
        $(".btn-paging span").html(page);
    }

    $('.btn-back').click(function(){
        if (!$(this).hasClass('disabled')) {
            if (page > 1) {
                page--;
            }
            updatePaging();
        }
    })
    $('.btn-next').click(function(){
        if (!$(this).hasClass('disabled')) {
            page++;
            updatePaging();
        }
    })

    var updatePaging = function() {
        if (page == 1) {
            $('.btn-back').addClass("disabled");
        } else {
            $('.btn-back').removeClass("disabled");
        }
        $(".btn-paging span").html(page);
        history.pushState({
            param: window.location.href
        }, 'Products', '?page='+page);
        getData();
    }
    
    var getData = function(){

        $.ajax({
            type: 'GET',
            url: 'quanly.php?page='+page,
            success: function(data) {
                // console.log(data);
                // console.log(JSON.parse(data));
                var sinhvien = JSON.parse(data);
                var list = $('.list');
                list.html('');

                sinhvien.forEach(function(sv, index){
                    list.append('\
                        <tr class="sv-' + sv.id + '" data-id=' + sv.id +'>\
                        <td class="no">' + ((index+1)+(page-1)*20) + '</td>\
                        <td class="name">' + sv.name + '</td>\
                        <td class="birth">' + sv.birth + '</td>\
                        <td class="mssv">' + sv.mssv + '</td>\
                        <td class="phone">' + sv.phone + '</td>\
                        <td class="class">' + sv.class + '</td>\
                        <td>\
                            <button data-id=' + sv.id +' class="btn-edit btn btn-warning" data-toggle="modal" data-target="#modalEdit">edit</button>\
                            <button data-id=' + sv.id +' class="btn-delete btn btn-danger">delete</button>\
                        </td>\
                    </tr>')
                })

                if (sinhvien.length<10) {
                    $('.btn-next').addClass("disabled");
                } else {
                    $('.btn-next').removeClass("disabled");
                }
            },
            error: function(data) {
                console.log('error!!!!!!!')
                console.error(data);
            }
        });
    }

    $('.list').on("click", ".btn-edit", function(event){
        var id = $(this).data('id');
        var sv = $(this).parent().parent();
        var modalEdit = $('#modalEdit');

        modalEdit.find('.name').val(sv.find('.name').html());
        modalEdit.find('.birth').val(sv.find('.birth').html());
        modalEdit.find('.mssv').val(sv.find('.mssv').html());
        modalEdit.find('.phone').val(sv.find('.phone').html());
        modalEdit.find('.class').val(sv.find('.class').html());

        modalEdit.on("click", ".btn-save-edit", function(event){
            var name = modalEdit.find('.name').val();
            var birth = modalEdit.find('.birth').val();
            var mssv = modalEdit.find('.mssv').val();
            var phone = modalEdit.find('.phone').val();
            var _class = modalEdit.find('.class').val();

            $.ajax({
                type: 'PUT',
                url: 'quanly.php?id='+id+'&name='+name+'&birth='+birth+'&mssv='+mssv+'&phone='+phone+'&class='+_class,
                success: function(data) {
                    modalEdit.modal('hide');
                    getData();
                },
                error: function(data) {
                    console.log('error!!!!!!!')
                    console.error(data);
                }
            });
        })

    })

    $('.list').on("click", ".btn-delete", function(event){
        var id = $(this).data('id');

        $(this).parent().parent().hide();
        $.ajax({
            type: 'DELETE',
            url: 'quanly.php?id=' + id,
            success: function(data) {
                getData();
            },
            error: function(data) {
                console.log('error!!!!!!!')
                console.error(data);
            }
        });
    });

    var modalAdd = $("#modalAdd");
    modalAdd.on("click", ".btn-save-add", function(event){
        var name = modalAdd.find('.name').val();
        var birth = modalAdd.find('.birth').val();
        var mssv = modalAdd.find('.mssv').val();
        var phone = modalAdd.find('.phone').val();
        var _class = modalAdd.find('.class').val();

        $.ajax({
            type: 'POST',
            url: 'quanly.php',
            data: {
                name : name,
                birth : birth,
                mssv : mssv,
                phone : phone,
                _class : _class
            },
            success: function(data) {
                modalAdd.modal('hide');
                getData();
                // console.log(data);
            },
            error: function(data) {
                console.log('error!!!!!!!')
                console.error(data);
            }
        });
    })

    getData();
// });;