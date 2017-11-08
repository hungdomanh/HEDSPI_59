
<!DOCTYPE html>
<html>
<head>
	<title>Conecting...</title>
	<link rel="shortcut icon" type="image/png" href="https://www.hust.edu.vn/documents/21257/147855/BVP-logo+bk-rgb.jpg/c2f94a78-f713-4af1-b9f0-7f6c4cb94438?t=1483699000000&download=true"/>

	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta/css/bootstrap.min.css" integrity="sha384-/Y6pD6FV/Vv2HJnA6t+vslU6fwYXjCFtcEpHbNJ0lyAFsXTsjBbfaDjzALeQsN6M" crossorigin="anonymous">
	<link rel="stylesheet" type="text/css" href="style.css">

	<script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.11.0/umd/popper.min.js" integrity="sha384-b/U6ypiBEHpOf/4+1nzFpr53nxSS+GLCkfwBdFNTxtclqqenISfwAzpKaMNFNmj4" crossorigin="anonymous"></script>
	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta/js/bootstrap.min.js" integrity="sha384-h0AbiXch4ZDo7tp9hKZ4TsHbi047NrKGLO3SEJAg45jXxnGIfYzk4Si90RDIqNm1" crossorigin="anonymous"></script>
</head>
<body>
	<?php 
	session_start();

	$host = isset($_POST['host']) ? $_POST['host'] : '';
	$user = isset($_POST['user']) ? $_POST['user'] : '';
	$password = isset($_POST['password']) ? $_POST['password'] : '';
	$database = isset($_POST['database']) ? $_POST['database'] : '';

	$_SESSION['host'] = $host;
	$_SESSION['user'] = $user;
	$_SESSION['password'] = $password;
	$_SESSION['database'] = $database;

	// Create connection
	$conn = mysqli_connect($host, $user, $password, $database);

	// Check connection
	if (!$conn) {
		die("<div class='alert alert-danger text-center' role='alert'><strong>Connection failed! </strong>" . $conn->connect_error . "</div> " . "<a class='try-again-text' href='/ketnoi.html'>Try Again</a>");
	}  else {
		echo "<div class='alert alert-success text-center' role='alert'><strong>Connected successfully! </strong><a href='/quanly.html'>Redirecting...</a></div>";
	}

	?>
	<h1 id="count">5</h1>


	<script type="text/javascript">
		var count=5;

		var counter=setInterval(timer, 1000);

		function timer() {
			count=count-1;
			if (count <= 0) {
				clearInterval(counter);
				window.location = 'quanly.html';
				return;
			}
			document.getElementById("count").innerHTML = "" + count;
		}
	</script>
</body>
</html>
