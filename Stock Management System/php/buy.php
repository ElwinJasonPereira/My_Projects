<?php

$servername = "localhost:3306";
$username = "root";
$password = "Colinchriston11@";
$dbname = "stockdbms";
$conn = new mysqli($servername, $username, $password, $dbname);
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}


$company =  $_REQUEST['name'];
$id =  $_REQUEST['id'];
$price = $_REQUEST['Price'];
$email =  $_REQUEST['email'];
$number =  $_REQUEST['Balance'];



 $sql= "INSERT  into buy (compName,compId,email,price,NoofStocks)  VALUES ('$company','$id','$email','$price','$number')";
 


// Execute the multiple SQL queries
if($conn->query($sql) === TRUE){
  header("Location:../html/sucessPage.html");
    }
    else{
        echo "ERROR: Hush! Sorry $sql. "
          . mysqli_error($conn);
      }

  mysqli_close($conn);
?>