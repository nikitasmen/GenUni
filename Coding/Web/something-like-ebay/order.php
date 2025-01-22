<?php
    $servername = "localhost"; 
    $username = "root"; 
    $password = "";
    $database = "paradoteo_03";
    $conn = mysqli_connect($servername, $username, $password, $database);
?>

<!DOCTYPE html>
<html>
<head>
    <title>Final</title>
    <link href="style/style.css" rel="stylesheet" type="text/css">
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style id="compiled-css" type="text/css">
        select{
            text-align-last:center;
            padding-right: 29px;
            direction: rtl;
        }
        select.inputstyle {
            width:178px !important;
            height:27px !important;
            margin-top:6px !important;
            direction:rtl !important;
            text-align:left;
        }
        select .lt { text-align: center; }
    </style>
   
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
        </nav> 
    </header>
    <h1>Order</h1>

    <h2>Products</h2>
    <form id="product" action="backend/orders.php" method="get">
        <label for="prod_name">Products:</label>
        <select name="prod_name" id="prod_name" class="inputstyle">    
            <?php 
            $query = "SELECT product.name, price, store.name AS store_name FROM product INNER JOIN store ON product.store_id = store.id WHERE product.avail_amount!=0";
            $result = $conn->query($query);

            if ($result->num_rows > 0) {
                while ($optionData = $result->fetch_assoc()) {
                    $name = $optionData['name'];
                    $price = $optionData['price'];
                    $store_name = $optionData['store_name'];
            ?>
              <option class='lt' value="<?php echo $name; ?>"><?php echo $name.',   '.$price.'$, '.$store_name; ?></option>
            
              <?php }} ?>
        </select>
       
        <br><br>
        <label for="quantity">Quantity:</label>
        <input type="number" name="quantity" min="1" step="1"> 
        <br><br> 

        <p><?php require "backend/orders.php" ; totalcost(); ?></p>
        
        <button type="submit"  name="add">Add Product</button>
        <button type="submit"  name="submit">Submit Order</button>
    </form>
    <br><br>
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
