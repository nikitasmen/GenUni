<?php 
   
   $servername = "localhost"; 
   $username = "root"; 
   $password = "";
   
   $database = "paradoteo_03";
   
    // Create a connection 
    $conn = mysqli_connect($servername, $username, $password, $database);
   
        if(isset($_POST['submit']))
        {
              
            $name = $_POST['name'];
            $country = $_POST['country']; 
            
            $query = "SELECT name FROM store WHERE name= '$name'";
            $result = mysqli_query($conn,$query);
           
             if(mysqli_num_rows($result)<1)
             {
             
               $query = "INSERT INTO store (name,country) VALUES ('$name','$country')";
               $result = mysqli_query($conn,$query);
               mysqli_close($conn);
               echo '<script type="text/javascript"> alert("Store created succesfull") </script>';
             }
             else
             {
               echo '<script type="text/javascript"> alert("Store already exists"); </script>';
             }
        }
      
?>

<!DOCTYPE html>
<html>
    <head>
        <title>Final</title>
        <link href="style/style.css" rel=" stylesheet" type="text/css">
        <meta charset="utf-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
       
    </head>
    <body>
        <header id="topHead">
            <nav id="topnav"> 
                <a href="backend/logout.php">Log out</a>   
                <a href="signup.php">Sign up</a>
                <a href="stores.html">Stores</a>
                <a href="order.php">Order</a>
                <a class="active" href="index.html">Home</a>
                <form action="search.php">
                  <input type="text" placeholder="Search.." name="search">
                  <button type="submit">Submit</button>
                </form>
              </div>
         
            
            
             </nav> 
        </header>
        <h1>Add Store</h1>
        <form action="addstore.php" method="post">
        <label for="name"><b>Store's name</b></label>
            <input type="text" placeholder="Enter Store's Name" name="name" id="name" required><br>
            <br>
            <label for="country"><b>Country</b></label>
            <input type="text" placeholder="Enter Country" name="country" id="country" required>
            <br>
            <button type="submit" id="submit" name="submit">Submit</button>
        </form>

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
