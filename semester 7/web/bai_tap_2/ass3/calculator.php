<?php 

// Bước 1: Lấy tham số
$financed = isset($_POST['financed']) ? $_POST['financed'] : '';
$rate = isset($_POST['rate']) ? $_POST['rate'] : '';

$result = ($financed*$rate) / 12;

echo round($result,1);

?>