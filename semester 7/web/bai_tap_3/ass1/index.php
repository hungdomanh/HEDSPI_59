<!DOCTYPE html>
<html>
<head>
	<title>Assigment 1</title>
	<link rel="shortcut icon" type="image/png" href="https://www.hust.edu.vn/documents/21257/147855/BVP-logo+bk-rgb.jpg/c2f94a78-f713-4af1-b9f0-7f6c4cb94438?t=1483699000000&download=true"/>

	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta/css/bootstrap.min.css" integrity="sha384-/Y6pD6FV/Vv2HJnA6t+vslU6fwYXjCFtcEpHbNJ0lyAFsXTsjBbfaDjzALeQsN6M" crossorigin="anonymous">
	<link rel="stylesheet" type="text/css" href="style.css">

	<!-- <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.11.0/umd/popper.min.js" integrity="sha384-b/U6ypiBEHpOf/4+1nzFpr53nxSS+GLCkfwBdFNTxtclqqenISfwAzpKaMNFNmj4" crossorigin="anonymous"></script>
	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta/js/bootstrap.min.js" integrity="sha384-h0AbiXch4ZDo7tp9hKZ4TsHbi047NrKGLO3SEJAg45jXxnGIfYzk4Si90RDIqNm1" crossorigin="anonymous"></script> -->
</head>
<body>

	<?php
        function displayPage($firstname, $hourslept, $birthyear) {
			$yearslept = round((2017 - $birthyear) * $hourslept/24, 2);
			echo "<br><h4 class='displayPage-text'>Tên bạn là $firstname , bạn đã dùng $yearslept năm để ngủ.</h4>";
			$old = 2017 - $birthyear;
			if ($old > 50 && $yearslept > 15 ) {
				echo "<h4 class='displayPage-text'>Bạn tốt nhất nên nghỉ hưu.</h4>";
			} else {
				echo "<h4 class='displayPage-text'>Làm tiếp đi, chưa cần nghỉ hưu.</h4>";
			}
		}
		function doValidation($firstname, $hourslept, $birthyear)  {
			if (empty($firstname)){
		        $error['firstname'] = 'You must enter a First Name';
		    }
		 
		    if (empty($hourslept)){
		        $error['hourslept'] = 'You must enter the hours you sleep';
		    } else if(!is_numeric($hourslept)) {
		    	$error['hourslept'] = 'The hours you sleep must be numeric';
		    }

		    if (empty($birthyear)){
		        $error['birthyear'] = 'You must enter your birthyear';
		    } else if(!is_numeric($birthyear)) {
		    	$error['birthyear'] = 'Your Birth Year must be numeric';
		    } else if(strlen($birthyear) != 4 ) {
		    	$error['birthyear'] = 'Your Birth Year must be exaclty four numbers';
		    }

		    if ($error['firstname'] == '' && $error['hourslept'] == '' && $error['birthyear'] == '') {
		    	return true;
		    }
		    return false;
		}

		if (!empty($_POST['info_action'])) {
			$firstname = isset($_POST['firstname']) ? $_POST['firstname'] : '';
			$hourslept = isset($_POST['hourslept']) ? $_POST['hourslept'] : '';
			$birthyear = isset($_POST['birthyear']) ? $_POST['birthyear'] : '';		    
			if (doValidation($firstname, $hourslept, $birthyear)) {
		    	displayPage($firstname, $hourslept, $birthyear);
			}
		}

		

	?>

	<form method="post" action="index.php" style="width: 400px;margin: 100px auto;">
		<h3>Function - data in and out</h3>
		First Name:	<br>
		<input type="text" name="firstname" value="<?php echo isset($firstname) ? $firstname : ''; ?>">  
		<span class="error"><?php echo isset($error['firstname']) ? $error['firstname'] : ''; ?></span>
		<br> <br>
		How many hours do you sleep at night?:	<br>
		<input type="text" name="hourslept" value="<?php echo isset($hourslept) ? $hourslept : ''; ?>">  
		<span class="error"><?php echo isset($error['hourslept']) ? $error['hourslept'] : ''; ?></span>
		<br> <br>
		Birth Year: <br>
		<input type="text" name="birthyear" value="<?php echo isset($birthyear) ? $birthyear : ''; ?>">  
		<span class="error"><?php echo isset($error['birthyear']) ? $error['birthyear'] : ''; ?></span>
		<br> <br>

		<input type="submit" value="Submit Information" name="info_action">

	</form>



	<!-- Vendor JS -->
	<script src="https://code.jquery.com/jquery-latest.min.js"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery.form/3.32/jquery.form.js"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery-validate/1.11.1/jquery.validate.min.js"></script>

</body>
</html>