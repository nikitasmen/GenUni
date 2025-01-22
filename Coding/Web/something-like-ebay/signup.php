<?php
   
$servername = "localhost"; 
$username = "root"; 
$password = "";

$database = "paradoteo_03";

 // Create a connection 
 $conn = mysqli_connect($servername, $username, $password, $database);

     if(isset($_POST['submit']))
     {
           
      $full_name = $_POST['name'];
      $age = $_POST['age'];
      $gender = $_POST['gender'];
      $psd = $_POST['psd'];
      $psdrepeat = $_POST['psdrepeat'];
      $date = date("Y-m-d");
        if ($psd == $psdrepeat)
        {

          $query = "SELECT full_name FROM user WHERE full_name= '$full_name'";
          $result = mysqli_query($conn,$query);
        
          if(mysqli_num_rows($result)<1)
          {
          
            $query = "INSERT INTO user (full_name,password,age,gender,date_of_sign) VALUES ('$full_name','$psd','$age','$gender','$date')";
            $result = mysqli_query($conn,$query);
            mysqli_close($conn);
            echo '<script type="text/javascript"> alert("You signed up succesfull") </script>';
          }
          else
          {
            echo '<script type="text/javascript"> alert("User exists"); </script>';
          }
        }
        else 
        {
          echo '<script type="text/javascript"> alert("Passwords must be the same"); </script>';
        }
      }
  
?>

<!DOCTYPE html>
<html>
<head>
  <meta charset="utf-8">
  <title>Final</title>
  <style>
      body {font-family: Arial, Helvetica, sans-serif;}
      * {box-sizing: border-box;}
      
      /* Full-width input fields */
      input[type=text], input[type=password], input[tpye=number]{
        width: 100%;
        padding: 15px;
        margin: 5px 0 22px 0;
        display: inline-block;
        border: none;
        background: #f1f1f1;
      }
      
      /* Add a background color when the inputs get focus */
      input[type=text]:focus, input[type=password]:focus , input[type=number]:focus {
        background-color: #ddd;
        outline: none;
      }
      
      /* Set a style for all buttons */
      button {
        background-color: #2196F3;
        color: white;
        padding: 14px 20px;
        margin: 8px 0;
        border: none;
        cursor: pointer;
        width: 100%;
        opacity: 0.9;
      }
      
      button:hover {
        opacity:1;
      }
      
      /* Extra styles for the cancel button */
      .cancelbtn {
        padding: 14px 20px;
        background-color: #f44336;
      }
      
      /* Float cancel and signup buttons and add an equal width */
      .cancelbtn, .signupbtn {
        float: left;
        width: 50%;
      }
      
      /* Add padding to container elements */
      .container {
        padding: 16px;
      }
      
      /* The Modal (background) */
      .modal {
        display: none; /* Hidden by default */
        position: fixed; /* Stay in place */
        z-index: 1; /* Sit on top */
        left: 0;
        top: 0;
        width: 100%; /* Full width */
        height: 100%; /* Full height */
        overflow: auto; /* Enable scroll if needed */
        background-color: #474e5d;
        padding-top: 50px;
      }
      
      /* Modal Content/Box */
      .modal-content {
        background-color: #fefefe;
        margin: 5% auto 15% auto; /* 5% from the top, 15% from the bottom and centered */
        border: 1px solid #888;
        width: 80%; /* Could be more or less, depending on screen size */
      }
      
      /* Style the horizontal ruler */
      hr {
        border: 1px solid #f1f1f1;
        margin-bottom: 25px;
      }
      
      /* The Close Button (x) */
      .close {
        position: absolute;
        right: 35px;
        top: 15px;
        font-size: 40px;
        font-weight: bold;
        color: #f1f1f1;
      }
      
      .close:hover,
      .close:focus {
        color: #f44336;
        cursor: pointer;
      }
      
      /* Clear floats */
      .clearfix::after {
        content: "";
        clear: both;
        display: table;
      }
      
      /* Change styles for cancel button and signup button on extra small screens */
      @media screen and (max-width: 300px) {
        .cancelbtn, .signupbtn {
          width: 100%;
        }
      }
      </style>

      
      <link href="style/style.css" rel=" stylesheet" type="text/css">
</head>
<body>
    <header id="topHead">
      <nav id="topnav">  
        <a href="backend/logout.php">Log out</a>          
        <a href="signup.php">Sign up</a>
        <a href="stores.html">Stores</a>
        <a href="order.php">Order</a>
        <a class="active" href="index.html">Home</a> 
       </nav> 
    </header>

    <button onclick="document.getElementById('id01').style.display='block'" style="width:auto;">Sign Up</button>
    <div id="id01" class="modal">
      <span onclick="document.getElementById('id01').style.display='none'" class="close" title="Close Modal">&times;</span>
      
      <form class="modal-content" id="input" action="signup.php" method="post">
      
        <div class="container">
          <h1>Sign Up</h1>
          <p>Please fill in this form to create an account.</p>
          <hr>
          <label for="name"><b>Full Name</b></label>
          <input type="text" placeholder="Enter Full Name" name="name" id="name" required>

          <label for="age"><b>Age</b></label>
          <input type="number" placeholder="Enter Age" name="age" id="age" required><br><br>

          <label for="gender"><b>Gender</b></label>
          <input type="text" placeholder="Enter Gender" name="gender" id="gender" required>

          
          <label for="psd"><b>Password</b></label>
          <input type="text" placeholder="Enter Password" name="psd" id="psd" required>

          <label for="psdrepeat"><b>Password</b></label>
          <input type="text" placeholder="Enter Password again" name="psdrepeat" id="psdrepeat" required>

          <div class="clearfix">
            <button type="button" onclick="document.getElementById('id01').style.display='none'" class="cancelbtn">Cancel</button>
            <button type="submit"  onclick="document.getElementById('id01').style.display='none'"  name="submit" class="signupbtn" >Submit</button>
          </div>
        </div>
      </form>
    </div>
    <link href="style/login_style.css" rel=" stylesheet" type="text/css">
            
            <button class="open-button" onclick="openForm()">Open Form</button>
    
            <div class="form-popup" id="myForm">
            <form action="backend/loginform.php" class="form-container">
                <h1>Login</h1>
    
                <label for="name"><b>Full Name</b></label>
                <input type="text" id="name" placeholder="Enter Full Name" name="name" required>
    
                <label for="psw"><b>Password</b></label>
                <input type="password" id="name" placeholder="Enter Password" name="psd" required>
    
                <button type="submit" class="btn" onclick="setcoockie()" >Login</button>
                <button type="button" class="btn cancel" onclick="closeForm()">Close</button>
            </form>
            </div>
    
    <script>
    function openForm() {
      document.getElementById("myForm").style.display = "block";
    }
    
    function closeForm() {
      document.getElementById("myForm").style.display = "none";
    }
    
    function setcoockie() {
      let name = document.getElementById("name").value;
      let psd = document.getElementById("psd").value;
      const d = new Date();
      d.setTime(d.getTime() + (86400 * 1000)); // Set cookie expiration to 1 day
      let expires = "expires=" + d.toUTCString();
      document.cookie = "name=" + name + ";" + expires + ";path=/";
      document.cookie = "psd=" + psd + ";" + expires + ";path=/";
    }
    </script>
</body>    
</html>
