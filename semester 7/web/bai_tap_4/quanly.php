<!DOCTYPE html>
<html>
<head>
	<title>Quan Ly</title>
	<link rel="shortcut icon" type="image/png" href="https://www.hust.edu.vn/documents/21257/147855/BVP-logo+bk-rgb.jpg/c2f94a78-f713-4af1-b9f0-7f6c4cb94438?t=1483699000000&download=true"/>

	<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta/css/bootstrap.min.css" integrity="sha384-/Y6pD6FV/Vv2HJnA6t+vslU6fwYXjCFtcEpHbNJ0lyAFsXTsjBbfaDjzALeQsN6M" crossorigin="anonymous">
	<link rel="stylesheet" type="text/css" href="style.css">

	<script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.11.0/umd/popper.min.js" integrity="sha384-b/U6ypiBEHpOf/4+1nzFpr53nxSS+GLCkfwBdFNTxtclqqenISfwAzpKaMNFNmj4" crossorigin="anonymous"></script>
	<script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0-beta/js/bootstrap.min.js" integrity="sha384-h0AbiXch4ZDo7tp9hKZ4TsHbi047NrKGLO3SEJAg45jXxnGIfYzk4Si90RDIqNm1" crossorigin="anonymous"></script>
</head>
<body>

<?php echo $user; ?>
	<table class="table">
		<thead>
			<tr>
				<th>No</th>
				<th>Họ và tên</th>
				<th>Ngày tháng năm sinh</th>
				<th>MSSV</th>
				<th>Số điện thoại</th>
				<th>Lớp học</th>
				<th>Quản lý</th>
			</tr>
		</thead>
		<tfoot>
			<tr>
				<th>Add</th>
				<th></th>
				<th>Back</th>
				<th>Next</th>
			</tr>
		</tfoot>
		<tbody>
			<tr>
				<td>Cell</td>
				<td>Cell</td>
				<td>Cell</td>
				<td>Cell</td>
				<td>Cell</td>
				<td>Cell</td>
				<td>
					<button>edit</button>
					<button>delete</button>
				</td>
			</tr>
		</tbody>
	</table>

	<!-- Vendor JS -->
	<script src="https://code.jquery.com/jquery-latest.min.js"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery.form/3.32/jquery.form.js"></script>
	<script src="https://cdnjs.cloudflare.com/ajax/libs/jquery-validate/1.11.1/jquery.validate.min.js"></script>

</body>
</html>