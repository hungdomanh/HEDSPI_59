<?php 
	$id = isset($_POST['id']) ? $_POST['id'] : '';

	$fileName = "array_" . $id . "_sorted.txt";

	if (!file_exists($fileName)) {
	    echo "Cannot find file.";
	} else {
		$fileHandle = fopen($fileName, "r")or die("Unable to open");
	    $fileContent =  fread($fileHandle,filesize($fileName));
	    echo $fileContent;
	    fclose($fileHandle);
	}

?>