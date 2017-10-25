<?php 

$guestbook = fopen("guestbook.txt", "a+") or die("Unable to open file!");

$firstname = isset($_POST['firstname']) ? $_POST['firstname'] : '';
$lastname = isset($_POST['lastname']) ? $_POST['lastname'] : '';
$contact_type = isset($_POST['contact_type']) ? $_POST['contact_type'] : '';
$contact_value_email = isset($_POST['contact_value_email']) ? $_POST['contact_value_email'] : '';
$contact_value_phone = isset($_POST['contact_value_phone']) ? $_POST['contact_value_phone'] : '';
$city = isset($_POST['city']) ? $_POST['city'] : '';
$comment = isset($_POST['comment']) ? $_POST['comment'] : '';

fwrite($guestbook, PHP_EOL . $firstname . ' ' . $lastname . ' ' . $contact_value_email . $contact_value_phone . ' ' . $city . ' ' . $comment);
fclose($guestbook);

echo "DONE"




 ?>