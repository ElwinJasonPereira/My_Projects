<?php

$servername = "localhost:3306";
$username = "root";
$password = "Colinchriston11@";
$dbname = "stockdbms";
$conn = new mysqli($servername, $username, $password, $dbname);
if ($conn->connect_error) {
  die("Connection failed: " . $conn->connect_error);
}

function test_input($data) {
     
        $data = trim($data);
        $data = stripslashes($data);
        $data = htmlspecialchars($data);
        return $data;
    }


if ($_SERVER["REQUEST_METHOD"] == "POST") {
$company = test_input($_POST["name"]);
$id = test_input($_POST["id"]);
$price =test_input($_POST["Price"]);
$email =test_input($_POST["email"]);
$pass = test_input($_POST["number"]);

    $stmt = $conn->prepare("SELECT * FROM buy");
    $stmt->execute();
    $resultSet = $stmt->get_result();
    $users = $resultSet->fetch_all(MYSQLI_ASSOC);
        // $users = $stmt->fetchAll();
     
    foreach($users as $user) {
        if(($user['email'] == $email) &&
            ($user['compName'] == $company) && 
            ($pass<=$user['NoOfStocks']))
             {
                $sql= "INSERT  into sell (compName,compId,email,price,NoofStocks)  VALUES ('$company','$id','$email','$price','$pass')";
             if($conn->query($sql) === TRUE){
 
            header("Location:../html/sucessPage.html");
                }
            else{
                echo "ERROR: Hush! Sorry $sql. "
                    . mysqli_error($conn);
        //         }
            }
               
        }
     
            
    }
}
else{
    echo "ERROR: Hush! Sorry $check. "
      . mysqli_error($conn);
  }
?>