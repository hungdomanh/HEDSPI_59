<?php error_reporting(E_ALL); ?>
<!DOCTYPE html>
<html>
<head>
	<title>Assigment 3</title>
	<!-- <link rel="shortcut icon" type="image/png" href="https://www.hust.edu.vn/documents/21257/147855/BVP-logo+bk-rgb.jpg/c2f94a78-f713-4af1-b9f0-7f6c4cb94438?t=1483699000000&download=true"/> -->

	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta/css/bootstrap.min.css" integrity="sha384-/Y6pD6FV/Vv2HJnA6t+vslU6fwYXjCFtcEpHbNJ0lyAFsXTsjBbfaDjzALeQsN6M" crossorigin="anonymous">
	<link rel="stylesheet" type="text/css" href="style.css">

	<script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.11.0/umd/popper.min.js" integrity="sha384-b/U6ypiBEHpOf/4+1nzFpr53nxSS+GLCkfwBdFNTxtclqqenISfwAzpKaMNFNmj4" crossorigin="anonymous"></script>
	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta/js/bootstrap.min.js" integrity="sha384-h0AbiXch4ZDo7tp9hKZ4TsHbi047NrKGLO3SEJAg45jXxnGIfYzk4Si90RDIqNm1" crossorigin="anonymous"></script>
</head>
<body>
	<?php
		$fileCountName = "file_count.txt";
		if (!file_exists($fileCountName)) {
		    echo "Cannot find file.";
		} else {
			$fileHandle = fopen($fileCountName, "r")or die("Unable to open");
		    $fileCountNumber =  fread($fileHandle,filesize("file_count.txt"));
		    fclose($fileHandle);
		}
	?>

	<div class="container-fluid">
		<div class="row" style="padding: 50px 0px;">
			<div class="col-lg-2">
				<h4 class="text-center">Choose Array: </h4>
				<div style="overflow-y: auto; max-height: 350px">
					<?php 
					for ($i=1; $i < $fileCountNumber; $i++) { 
							echo "<div class='data-file text-center' data-file='$i'>Array ". $i . "</div>";
						}	
					?>
				</div>
			</div>
			<div class="col-lg-10">
				<h4 class="text-center">Content of array <span id="choose-id"></span>: </h4>
				<div id="content-array">
					<div class="row">
						<div class="col array-col-1"><b>1-10</b><br><br><div class="content-array"></div></div>
						<div class="col array-col-2"><b>11-10</b><br><br><div class="content-array"></div></div>
						<div class="col array-col-3"><b>21-30</b><br><br><div class="content-array"></div></div>
						<div class="col array-col-4"><b>31-40</b><br><br><div class="content-array"></div></div>
						<div class="col array-col-5"><b>41-50</b><br><br><div class="content-array"></div></div>
						<div class="col array-col-6"><b>51-60</b><br><br><div class="content-array"></div></div>
						<div class="col array-col-7"><b>61-70</b><br><br><div class="content-array"></div></div>
						<div class="col array-col-8"><b>71-80</b><br><br><div class="content-array"></div></div>
						<div class="col array-col-9"><b>81-90</b><br><br><div class="content-array"></div></div>
						<div class="col array-col-10"><b>91-100</b><br><br><div class="content-array"></div></div>
					</div>
				</div>
			</div>
		</div>
	</div>
		
	<script type="text/javascript">
		$(".data-file").click(function(){
			var id = $(this).data("file");
			$(".data-file").css('font-weight', '500');
			$(this).css('font-weight', '700');
			$(".col .content-array").html("");
	
			$('#choose-id').html(id);
			$.ajax({
				type: "POST",
				url: "open_file.php",
				data: { id: id }
			}).done(function( res ) {
				var data = res.split(" ");
				for (var i = 0; i < 100; i++) {
					if (i < 10) {
						$(".array-col-1 .content-array").append(data[i] + "<br>");
					} else if (i < 20) {
						$(".array-col-2 .content-array").append(data[i] + "<br>");
					} else if (i < 30) {
						$(".array-col-3 .content-array").append(data[i] + "<br>");
					} else if (i < 40) {
						$(".array-col-4 .content-array").append(data[i] + "<br>");
					} else if (i < 50) {
						$(".array-col-5 .content-array").append(data[i] + "<br>");
					} else if (i < 60) {
						$(".array-col-6 .content-array").append(data[i] + "<br>");
					} else if (i < 70) {
						$(".array-col-7 .content-array").append(data[i] + "<br>");
					} else if (i < 80) {
						$(".array-col-8 .content-array").append(data[i] + "<br>");
					} else if (i < 90) {
						$(".array-col-9 .content-array").append(data[i] + "<br>");
					} else if (i < 100) {
						$(".array-col-10 .content-array").append(data[i] + "<br>");
					}
				}
			});    
		})
	</script>

	<!-- Vendor JS -->
	<script src="https://code.jquery.com/jquery-latest.min.js"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery.form/3.32/jquery.form.js"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery-validate/1.11.1/jquery.validate.min.js"></script>

</body>
</html>