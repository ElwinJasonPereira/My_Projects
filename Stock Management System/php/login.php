<?php
 
include_once('connection.php');
  
function test_input($data) {
     
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
}
  
if ($_SERVER["REQUEST_METHOD"] == "POST") {
     
    $username = test_input($_POST["username"]);
    $password = test_input($_POST["password"]);
    $stmt = $conn->prepare("SELECT * FROM register");
    $stmt->execute();
    $users = $stmt->fetchAll();
     
    foreach($users as $user) {
        if(($user['email'] == $username) &&
            ($user['pass'] == $password)) {
                $sql="INSERT into loginpage values('$username' ,'$password')";
                $conn->query($sql);
                header("location:../html/home.html");
        }
    }
            echo "<script language='javascript'>";
            echo "alert('WRONG INFORMATION')";
            echo "</script>";
            
            
    
}
 
?>