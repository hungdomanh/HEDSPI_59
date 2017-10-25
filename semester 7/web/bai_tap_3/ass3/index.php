<?php error_reporting(E_ALL); ?>
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
		if (!empty($_POST['create_array'])) {
			$max_number = isset($_POST['max_number']) ? $_POST['max_number'] : '';
		}
	?>

	<form method="post" action="index.php" style="width: 400px;margin: 100px auto;">
		<h3>Create Random Array[100]</h3> <br>
		<h5>Input max number of array (>1000):</h5>
		<input type="number" name="max_number" min="1000" required="true" value="<?php echo isset($max_number) ? $max_number : ''; ?>">  
		<?php echo isset($$error['max_number']) ? $$error['max_number'] : ''; ?>
		<br><br>
		<input type="submit" value="Create Array[100]" name="create_array">
	</form>

	<?php
		if ($max_number) {
			$fileCountName = "file_count.txt";
			if (!file_exists($fileCountName)) {
			    echo "Cannot find file.";
			} else {
			    $fileHandle = fopen($fileCountName, "r")or die("Unable to open");
			    $fileCountNumber =  fread($fileHandle,filesize("file_count.txt"));
			    $fileHandle = fopen($fileCountName, "w")or die("Unable to open");
			    fwrite($fileHandle, $fileCountNumber+1);
			    fclose($fileHandle);

			    // Create Array
			    $fileNewName = "array_" . $fileCountNumber .".txt";
			    chmod("/", 0755);
			    $fileHandle = fopen($fileNewName, "w")or die("Unable to open");
			    $fileHandle = fopen($fileNewName, "a+")or die("Unable to open");

			    for ($i=0; $i < 100; $i++) { 
					$random_number = rand(0, $max_number);
					$array[$i] = $random_number;
					fwrite($fileHandle, $random_number . "  ");
				}
				fclose($fileHandle);

				// Sort Array
				echo "Your Array: <br>";
				sort($array);
				$fileNewName = "array_" . $fileCountNumber ."_sorted.txt";
				chmod("/", 0755);
				$fileHandle = fopen($fileNewName, "w")or die("Unable to open");

				for ($i=0; $i < 100; $i++) { 
					if ($i != 99) {
						echo $array[$i] . " , ";
					} else {
						echo $array[$i] . " .";
					}
					fwrite($fileHandle, $array[$i] . " ");
				}
				fclose($fileHandle);

			}
		}
	?>

	<!-- Vendor JS -->
	<script src="https://code.jquery.com/jquery-latest.min.js"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery.form/3.32/jquery.form.js"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery-validate/1.11.1/jquery.validate.min.js"></script>

</body>
</html>