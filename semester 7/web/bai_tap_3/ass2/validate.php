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

	return $error;
}

?>