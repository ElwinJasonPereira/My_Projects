<?php

$servername = "localhost:3306";
$username = "root";
$password = "DanielLoy@21";
$dbname = "stockdbms";
$conn = new mysqli($servername, $username, $password, $dbname);
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}


$fname =  $_REQUEST['Firstname'];
$lname = $_REQUEST['Lastname'];
$email =  $_REQUEST['Email'];
$pass =  $_REQUEST['Password'];
$phone = $_REQUEST['Phone'];
if($phone ===''){
  
// header("Location:../html/signup.html");
echo '<script type="text/JavaScript"> 
     alert("GeeksForGeeks");
     </script>'
;
exit();
  
}

$sql="INSERT into register  VALUES ('$fname','$lname','$email','$pass','$phone')";
if($conn->query($sql) === TRUE){
  //   header("Location:../html/loginpage.html");
  header("Location:../html/loginpage.html");
    }
    else{
          echo "<script language='javascript'>";
          echo "alert('User is already registered ')";
          echo "</script>";
          header("Location:../html/stocksdemo.html");
      }

// header("Location:../html/loginpage.html");


  mysqli_close($conn);
?>

