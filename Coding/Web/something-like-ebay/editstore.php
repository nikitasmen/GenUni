<?php
$servername = "localhost"; 
$username = "root"; 
$password = "";

$database = "paradoteo_03";

 // Create a connection 
 $conn = mysqli_connect($servername, $username, $password, $database);

     if(isset($_POST['add']))
     {
           
        $name = $_POST['name'];
        $pname = $_POST['pname'];
        $amount = $_POST['avail_amount'];
        $price = $_POST['price'];
        $query = "SELECT id FROM store WHERE name= '$name'";
        $result = mysqli_query($conn,$query);
        if (mysqli_num_rows($result) > 0) {
            $row = mysqli_fetch_array($result);
            $id = $row['id'];
            
            $query ="SELECT name FROM product WHERE name='$pname' AND store_id ='$id'";
            $result = mysqli_query($conn,$query);
            if (mysqli_num_rows($result) ==1) {
        
                $query = "UPDATE product SET avail_amount='$amount' , price='$price' WHERE name='$pname' AND store_id='$id'"; 
                $result = mysqli_query($conn, $query);
                mysqli_close($conn);
                echo '<script type="text/javascript"> alert("Product updated succesfully") </script>';
            }
            else
            {  $query = "INSERT INTO product (name, avail_amount, price, store_id) VALUES ('$pname', '$amount', '$price', '$id')";
                $result = mysqli_query($conn, $query);
                mysqli_close($conn);
                echo '<script type="text/javascript"> alert("Product added succesfully") </script>';
            }
        } 
        else 
        {
            echo '<script type="text/javascript"> alert("Store does not exist"); </script>';
        }
    }
    if(isset($_POST['del']))
    { 
        $name = $_POST['name'];
        $pname = $_POST['pname'];
        $store_del_query = "SELECT id FROM store WHERE name='$name'"; 
        $result = mysqli_query($conn,$store_del_query);
        if (mysqli_num_rows($result) > 0) {
            $row = mysqli_fetch_array($result);
            $id = $row['id'];
            
            $query ="SELECT name FROM product WHERE name='$pname'";
            $result = mysqli_query($conn,$query);
            if (mysqli_num_rows($result) ==0) {
                echo '<script type="text/javascript"> alert("Product does not exist"); </script>';
            }
            else 
            {
                mysqli_query($conn,"DELETE FROM product WHERE name='$pname'");
                echo '<script type="text/javascript"> alert("Product Deleted"); </script>';
                
            }
        }
        else
        {
            echo '<script type="text/javascript"> alert("Store does not exist"); </script>';
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
        <h1>Edit Store</h1>
        <form action="editstore.php" method="post">
            <label for="name"><b>Store's name:</b></label>
            <input type="text" placeholder="Enter Store's Name" name="name" id="name" required><br><br>

            <label for="pname"><b>Product name:</b></label>
            <input type="text" placeholder="Enter Product's Name" name="pname" id="pname" required><br><br>

            <label for="avail_amount"><b>Available Amount:</b></label>
            <input type="text" placeholder="Enter Available Amount" name="avail_amount" id="avail_amount" ><br><br>

            <label for="price"><b>Product Price:</b></label>
            <input type="number" name="price" id="price" min="0" step="0.01" ><br><br>

            <button type="submit" id="add" name="add">Add</button>
            <button type="submit" id="del" name="del">DELETE</button>

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
