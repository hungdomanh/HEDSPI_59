<?php 
session_start();

$host = $_SESSION['host'];
$user = $_SESSION['user'];
$password = $_SESSION['password'];
$database = $_SESSION['database'];
$table = "sinhvien";

// // Create connection
$conn = mysqli_connect($host, $user, $password, $database);
if (!$conn) die('Error ' . mysqli_connect_error());
mysqli_set_charset($conn,"utf8");


$method = $_SERVER['REQUEST_METHOD'];
$request = explode('/', trim($_SERVER['PATH_INFO'],'/'));


switch ($method) {
	case 'GET':
		$page = isset($_GET['page']) ? $_GET['page'] : 1;
		$pageBegin = ($page-1)*20;
		$pageEnd = ($page)*20;
		if (!$page) {
			$pageBegin = 0;
		}
		$sql = "SELECT * FROM $table LIMIT 20 OFFSET $pageBegin";

		$result = mysqli_query($conn, $sql);
		$array_encode = array();
		$i=0;
		while ($row = mysqli_fetch_array($result)) {
			$array_encode[$i]->id = $row["id"];
			$array_encode[$i]->name  = $row["name"];
			$array_encode[$i]->class = $row["class"];
			$array_encode[$i]->phone = $row["phone"];
			$array_encode[$i]->mssv  = $row["mssv"];
			$array_encode[$i]->birth = $row["birth"];
			$i++;
		}

		echo json_encode($array_encode); 
		break;
	case 'PUT':
		$id = isset($_GET['id']) ? $_GET['id'] : '';
		$name = isset($_GET['name']) ? $_GET['name'] : '';
		$class = isset($_GET['class']) ? $_GET['class'] : '';
		$phone = isset($_GET['phone']) ? $_GET['phone'] : '';
		$mssv = isset($_GET['mssv']) ? $_GET['mssv'] : '';
		$birth = isset($_GET['birth']) ? $_GET['birth'] : '';
		
		if ($mssv == false) {
			$mssv = 0;
		}
		
		$sql = "UPDATE $table SET name='$name', birth='$birth', mssv=$mssv, phone='$phone', class='$class' WHERE id=$id";
		$result = mysqli_query($conn, $sql);
		
		echo array_shift($request);
		break;
	case 'POST':
		$id = isset($_POST['id']) ? $_POST['id'] : '';
		$name = isset($_POST['name']) ? $_POST['name'] : '';
		$class = isset($_POST['class']) ? $_POST['class'] : '';
		$phone = isset($_POST['phone']) ? $_POST['phone'] : '';
		$mssv = isset($_POST['mssv']) ? $_POST['mssv'] : '';
		$birth = isset($_POST['birth']) ? $_POST['birth'] : '';

		if ($mssv == false) {
			$mssv = 0;
		}

		$sql = "INSERT INTO $table (name, birth, mssv, phone, class) VALUES ('$name', '$birth', $mssv, '$phone', '$class')";
		echo $sql;
		$result = mysqli_query($conn, $sql);
		echo array_shift($request);
		break;
	case 'DELETE':
		$id = isset($_GET['id']) ? $_GET['id'] : '';
		$sql = "delete from $table where id=$id";
		
		$result = mysqli_query($conn, $sql);

		echo array_shift($request);
		break;
}




// echo json_encode($array_encode);



?>