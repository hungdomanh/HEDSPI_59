<!DOCTYPE html>
<html>
<head>
	<title>Assigment 3</title>
	<link rel="shortcut icon" type="image/png" href="https://www.hust.edu.vn/documents/21257/147855/BVP-logo+bk-rgb.jpg/c2f94a78-f713-4af1-b9f0-7f6c4cb94438?t=1483699000000&download=true"/>

	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta/css/bootstrap.min.css" integrity="sha384-/Y6pD6FV/Vv2HJnA6t+vslU6fwYXjCFtcEpHbNJ0lyAFsXTsjBbfaDjzALeQsN6M" crossorigin="anonymous">
	<link rel="stylesheet" type="text/css" href="style.css">

	<!-- <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.11.0/umd/popper.min.js" integrity="sha384-b/U6ypiBEHpOf/4+1nzFpr53nxSS+GLCkfwBdFNTxtclqqenISfwAzpKaMNFNmj4" crossorigin="anonymous"></script>
	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta/js/bootstrap.min.js" integrity="sha384-h0AbiXch4ZDo7tp9hKZ4TsHbi047NrKGLO3SEJAg45jXxnGIfYzk4Si90RDIqNm1" crossorigin="anonymous"></script> -->
</head>
<body>
	<a id="logo" href="/web/vi/home" title="Trở về Trang chủ"> 
		<img src="https://www.hust.edu.vn/hust-theme/images/logoEn.png" alt="Cổng thông tin HUST"> 
	</a><br><br><br><br><br><br>

	<div class="container" style="padding-bottom: 100px">
		<div class="row">
			<div class="col-lg-6 col-md-6">
				<form method="post" action="assignment_3_add_to_guestbook.php">  
					<fieldset>
						<legend>Please sign up on our guest list</legend><br>

						First name:
						<span id="firstname"></span>
						<br>
						<input class="input-form" type="text" name="firstname" value=""><br class="input-form"><br>

						Last name:
						<span id="lastname"></span>
						<br>
						<input class="input-form" type="text" name="lastname" value=""><br class="input-form"><br>

						Contact Infomation:
						<span id="contact_value"></span>
						<br>
						<input class="input-form" id="contact_type_email" type="radio" name="contact_type" value="phone" checked> <span class="input-form">Email</span>
						<input class="input-form" id="contact_type_phone" type="radio" name="contact_type" value="email"> <span class="input-form">Phone</span><br>
						<input class="input-form" id="contact_value_email" type="email" name="contact_value_email">
						<input class="input-form" id="contact_value_phone" type="number" name="contact_value_phone" style="display: none;"><br class="input-form"><br class="input-form">

						City Where You Want to Reside: 
						<span id="city"></span>
						<br>
						<select class="input-form" name="city">
							<option selected="true">Hanoi</option>
							<option>Danang</option>
							<option>HCM</option>
						</select><br class="input-form"><br>

						Comments: 
						<span id="comment"></span>
						<br>
						<textarea class="input-form" name="comment"></textarea><br>

						<input class="input-form" type="submit" value="Submit Infomation" name="ass1">
<br><br>
<p>For Admin Use Only <a href="assignment_3_view_guestbook.php">View Guestbook</a></p>

					</fieldset>
				</form>
			</div>

			<div class="col-lg-5 col-md-6">
				<form method="post" action="contact.php" id="calculator">
					<fieldset>
						<legend>Mortgage Calculator</legend> <br>

						Amount Financed: <input type="number" name="financed"> <br>
						Interest Rate: <input type="number" name="rate" style="margin-left: 33px;"> <br><br>
						<div id="payment"></div>
						<br>

						<button>Calculate Payment</button>
					</fieldset>
				</form>
			</div>

		</div>
	</div>

	<!-- Vendor JS -->
	<script src="https://code.jquery.com/jquery-latest.min.js"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery.form/3.32/jquery.form.js"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery-validate/1.11.1/jquery.validate.min.js"></script>
	<script src="validate-submit.js" type="text/javascript"></script>

</body>
</html>