<?php 

        // Bước 1: Lấy tham số
$firstname = isset($_POST['firstname']) ? $_POST['firstname'] : '';
$lastname = isset($_POST['lastname']) ? $_POST['lastname'] : '';
$contact_type = isset($_POST['contact_type']) ? $_POST['contact_type'] : '';
$contact_value_email = isset($_POST['contact_value_email']) ? $_POST['contact_value_email'] : '';
$contact_value_phone = isset($_POST['contact_value_phone']) ? $_POST['contact_value_phone'] : '';
$city = isset($_POST['city']) ? $_POST['city'] : '';
$comment = isset($_POST['comment']) ? $_POST['comment'] : '';

$result->firstname = $firstname;
$result->lastname = $lastname;
$result->contact_type = $contact_type;
$result->contact_value_email = $contact_value_email;
$result->contact_value_phone = $contact_value_phone;
$result->city = $city;
$result->comment = $comment;

$resultJSON = json_encode($result);

echo $resultJSON;

?>