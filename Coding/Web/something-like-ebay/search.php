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
                <div class="search-container">
                <form action="search.php" method="get">
                  <input type="text" placeholder="Search.." name="search">
                  <button type="submit">Submit</button>
                </form>
              </div>
            
             </nav> 
        </header>
        <h1>SEARCH</h1>
        <?php
            $servername = "localhost"; 
            $username = "root"; 
            $password = "";
            $database = "paradoteo_03";
            $conn = mysqli_connect($servername, $username, $password, $database);
            $search = $_GET['search'];
            $search_prod_query = "SELECT * FROM product WHERE name LIKE '$search%' ";
            $result1 = mysqli_query($conn, $search_prod_query);
            ?>

        <table border="1" cellspacing="0" cellpadding="10">
        <tr>
            <th>ID</th>
            <th>Name</th>
            <th>Available Amount</th>
            <th>Price</th>
            <th>Store</th>
           
            </tr>
                <?php
                if (mysqli_num_rows($result1) > 0) {
                    while($data = mysqli_fetch_assoc($result1)) {
                        $store_id = $data['store_id'];
                        $search_store_query = "SELECT name FROM store WHERE id='$store_id' ";
                        $result2 = mysqli_query($conn, $search_store_query);
                        $store = mysqli_fetch_assoc($result2)['name']; 
                ?>
            <tr>
            <td><?php echo $data['id']; ?> </td>
            <td><?php echo $data['name']; ?> </td>
            <td><?php echo $data['avail_amount']; ?> </td>
            <td><?php echo $data['price']; ?> </td>
            <td><?php echo $store; ?> </td>
            
            <tr>
                <?php
                }} else { ?>
                <tr>
                    <td colspan="8">No data found</td>
                </tr>
                <?php } ?>
        </table>
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
