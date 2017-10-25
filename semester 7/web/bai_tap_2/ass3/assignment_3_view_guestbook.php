<!doctype html>
<html lang="en">
<head>
    <link rel="stylesheet" href="style_view.css">
    <meta charset="UTF-8">
    <meta name="viewport"
          content="width=device-width, user-scalable=no, initial-scale=1.0, maximum-scale=1.0, minimum-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>All guest</title>
</head>
<a id="logo" href="/web/vi/home" title="Trở về Trang chủ"> 
        <img src="https://www.hust.edu.vn/hust-theme/images/logoEn.png" alt="Cổng thông tin HUST"> 
    </a><br><br><br><br><br><br
><h1>
    <center>All Guest</center>
</h1>
<body>

<table style="width: 100%">
    <tr>
        <th>First Name</th>
        <th>Last Name</th>
        <th>Contact Information</th>
        <th>City Reside</th>
        <th>Comments</th>
    </tr>
    <?php
    $file_handle = fopen("guestbook.txt", "rb");

    while (!feof($file_handle)) {
        $line_of_text = fgets($file_handle);
        $parts = explode(' ', $line_of_text);
        echo "<tr>
                <td>$parts[0]</td>
                <td>$parts[1]</td>
                <td>$parts[2]</td>
                <td>$parts[3]</td>
                <td>$parts[4]</td>
              </tr>";
    }
    fclose($file_handle);
    ?>
</table>
</body>
</html>