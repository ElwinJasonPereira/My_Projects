<?php
 
$conn = "";
  
try {
    $servername = "localhost:3306";
    $dbname = "stockdbms";
    $username = "root";
    $password = "Colinchriston11@";
  
    $conn = new PDO(
        "mysql:host=$servername; dbname=stockdbms",
        $username, $password
    );
     
   $conn->setAttribute(PDO::ATTR_ERRMODE,
                    PDO::ERRMODE_EXCEPTION);
}
catch(PDOException $e) {
    echo "Connection failed: " . $e->getMessage();
}
 
?>