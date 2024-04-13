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
$price = $_REQUEST['price'];
$email =  $_REQUEST['email'];
$id =  $_REQUEST['companyid'];



 $sql= "INSERT  into cart   VALUES ('$company','$id','$email','$price')";
 


// Execute the multiple SQL queries
if($conn->query($sql) === TRUE){
  //   header("Location:../html/loginpage.html");
  header("Location:../html/stocksdemo.html");
    }
    else{
        // echo "ERROR: Hush! Sorry $sql. "
          // . mysqli_error($conn);
          // echo "alert('Item already added to cart');";
          echo "<script language='javascript'>";
          echo "alert('WRONG INFORMATION')";
          echo "</script>";
          header("Location:../html/stocksdemo.html");
      }


  mysqli_close($conn);
?>