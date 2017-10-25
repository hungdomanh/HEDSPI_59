jQuery.validator.addMethod('answercheck', function (value, element) {
        return this.optional(element) || /^\bcat\b$/.test(value);
    }, "type the correct answer -_-");

jQuery.validator.addMethod('contact_value_check', function (value, element) {
        return this.optional(element) || /^\bcat\b$/.test(value);
    }, "invalid format -_-");

// validate contact form
$(function() {
    var dataGlobal ;

    $('#contact_type_email, #contact_type_phone').on('click', function(){
        if( $('#contact_type_email').is(':checked') ) {
            $('#contact_value_email').show();
            $('#contact_value_phone').hide();
        } else {
            $('#contact_value_email').hide();
            $('#contact_value_phone').show();
        }
    });

    $('#contact').validate({
        rules: {
            firstname: {
                required: true,
                minlength: 1
            },
            lastname: {
                required: true,
                minlength: 1
            }
            ,
            contact_type: {
                required: true
            },
            contact_value: {
                required: true
            },
            city: {
                required: true
            },
            comment: {
                required: true,
                minlength: 5
            }
        },
        messages: {
            firstname: {
                required: "come on, you have a name don't you?",
                minlength: "first name must consist of at least 1 characters"
            },
            lastname: {
                required: "come on, you have a name don't you?",
                minlength: "last name must consist of at least 1 characters"
            }
            ,
            contact_type: {
                required: "Required"
            },
            contact_value: {
                required: "Required"
            },
            city: {
                required: "Required"
            },
            comment: {
                required: "Required"
            }
        },
        submitHandler: function(form) {
            $(form).ajaxSubmit({
                type:"POST",
                data: $(form).serialize(),
                url:"contact.php",
                success: function(res) {
                    var data = JSON.parse(res);
                    console.log(data);
                    $(".input-form").hide();
                    $("#firstname").html(data.firstname);
                    $("#lastname").html(data.lastname);
                    $("#contact_type").html(data.contact_type);
                    $("#contact_value").html(data.contact_value_email);
                    $("#city").html(data.city);
                    $("#comment").html(data.comment);

                    // alert("Your message was sent successfully! We will be in touch as soon as We can.")

                },
                error: function() {
                    alert("Something went wrong, try refreshing and submitting the form again.");
                }
            });
        }
    });

    $('#calculator').validate({
        rules: {
            financed: {
                required: true
            },
            rate: {
                required: true
            }
        },
        messages: {
            financed: {
                required: "Required"
            },
            rate: {
                required: "Required"
            }
        },
        submitHandler: function(form) {
            $(form).ajaxSubmit({
                type:"POST",
                data: $(form).serialize(),
                url:"calculator.php",
                success: function(data) {
                    console.log(data);
                    $("#payment").html("Montly payment: " + data);
                   
                },
                error: function() {
                    alert("Something went wrong, try refreshing and submitting the form again.");
                }
            });
        }
    });
});