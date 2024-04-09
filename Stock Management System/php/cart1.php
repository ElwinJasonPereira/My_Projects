<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <link rel="stylesheet" href="../styles/navbar.css">
    <title>cart</title>
    <style>
        body {
            background-color: lightpurple;
        }

        table, h1 {
            margin-left: 100px;
            color: blue;
        }

        .invisible {
            display: none;
        }
    </style>
    <script src="JS/jquery-1.10.1.min.js"></script>
    <script>
        // function get(){
        check1 = JSON.parse(localStorage.getItem("login"));
        alert(check1[0]);
    </script>
</head>
<body>
<nav class="max-w">
    <div class="nav-div">
        <div><a href="../html/home.html"><img class="logoclass"
                                              src="../images/rocket_3.gif"
                                              style='border-radius:50px';
                                              width="168" height="60" alt="Groww Logo"
                                              itemprop="logo"></a>
        </div>

        <div class="c-search">
            <i class="material-icons"></i><input type="search" id="search"
                                                placeholder="What are you looking for today?"/>
        </div>

        <div id="thirdBox">
            <a href="./loginpage.html"><button id="login-btn" class="dontDisplay">Login/Register</button></a></li>
            <div id="userAcc" class="afterLogin">
                <img id="user" src="https://www.shareicon.net/data/2016/05/26/771188_man_512x512.png">
                <a href="../php/cart1.php"><i class="material-icons">shopping_cart</i></a></li>
            </div>
        </div>
    </div>
</nav>

<!-- ----------- navbar (End) ----------- -->
<div id="logOutDropDown" class="noDropDownDisplay">
    <div class="logout">Log Out</div>
</div>
<div id="dropDown" class="noDropDownDisplay"></div>
<h1>Cart</h1>
<?php
$host = "localhost";
$userName = "root";
$userPass = "Colinchriston11@";
$database = "stockdbms";

// Establish connection to the database
$connectQuery = mysqli_connect($host, $userName, $userPass, $database);

// Check for connection errors
if (mysqli_connect_errno()) {
    echo "Failed to connect to MySQL: " . mysqli_connect_error();
    exit();
}

// Execute query to fetch data from 'cart' table
$selectQuery = "SELECT * FROM cart";
$result = mysqli_query($connectQuery, $selectQuery);

// Check if there are rows in the result set
if (mysqli_num_rows($result) > 0) {
    // Start table and loop through the fetched data
    echo "<table border='3px' style='width:600px; line-height:50px;' id='table1'>";
    echo "<thead>";
    echo "<tr><th>company name</th><th>Company ID</th><th>username</th><th>price</th></tr>";
    echo "</thead>";
    echo "<tbody>";

    while ($row = mysqli_fetch_assoc($result)) {
        echo "<tr>";
        echo "<td class='name'>" . $row['compName'] . "</td>";
        echo "<td>" . $row['compId'] . "</td>";
        echo "<td>" . $row['email'] . "</td>";
        echo "<td>" . $row['price'] . "</td>";
        echo "</tr>";
    }

    echo "</tbody>";
    echo "</table>";
} else {
    header("Location:../html/cart.js");

}

mysqli_close($connectQuery);
?>
<form>
    <input type="text" id="name" name='name' class="invisible" value="1"></input>
    <input type="text" id="price" name='id' class='invisible' value="2"></input>
</form>
</body>
</html>
