<?php
$servername = "localhost"; 
$username = "root"; 
$password = "";
$database = "paradoteo_03";
$conn = mysqli_connect($servername, $username, $password, $database);


$cookie_name = "id"; // Define cookie name here

if (isset($_GET['submit'])) {
    if (isset($_COOKIE[$cookie_name]))
    {
        // ORDER CREATED 
        
        $user_id = $_COOKIE[$cookie_name];
        $order_create_query = "INSERT INTO orders (date, cost, user_id) VALUES (CURDATE(), 0, '$user_id')";
        $add_order = mysqli_query($conn, $order_create_query);
        if ($add_order) {
            $order_id = mysqli_insert_id($conn);
        
            $number = (int) $_GET['quantity'];
            if($number==0)
            {
                $number = 1 ; 
            }
            
            $prod_name = $_GET['prod_name'];
        
            $prod_price_id_query = "SELECT id, price, avail_amount FROM product WHERE name = '$prod_name'";
            $result = mysqli_query($conn, $prod_price_id_query);
            $product = mysqli_fetch_array($result, MYSQLI_ASSOC);
        
            $prod_amount = (int) $product['avail_amount']; 
            $prod_price = (int) $product['price'];
            $prod_id = $product['id'];
        
            if ($prod_amount < $number) {
                $number = $prod_amount;
            }
        
        
            $add_order_prod_query = "INSERT INTO `order_prod` (order_id, number, prod_id) VALUES ('$order_id', '$number', '$prod_id')";
            $add_order_prod = mysqli_query($conn, $add_order_prod_query);
            header("Location: ../order.php");
        } 
    }
    else 
    {
        echo "<script> alert('You must log in first');</script>";
        header("Location: ../order.php");
    }        
}


if (isset($_GET['add'])) {
    if (isset($_COOKIE[$cookie_name]))
    {
        $user_id = $_COOKIE[$cookie_name];
        //ADD product to the last order of the user 
        $order_select_query = "SELECT id FROM orders WHERE user_id='$user_id' ORDER BY id DESC LIMIT 1"; 
        $result = mysqli_query($conn , $order_select_query); 
        try
        {
            $order_id = mysqli_fetch_array($result, MYSQLI_ASSOC); 
            $order_id =(int) $order_id['id']; 

            $number = (int) $_GET['quantity'];
            $prod_name = $_GET['prod_name'];
            if($number==0)
            {
                $number = 1 ; 
            }

            $prod_price_id_query = "SELECT id, price, avail_amount FROM product WHERE name = '$prod_name'";
            $result = mysqli_query($conn, $prod_price_id_query);
            $product = mysqli_fetch_array($result, MYSQLI_ASSOC);
        
            $prod_amount = (int) $product['avail_amount']; 
            $prod_price = (int) $product['price'];
            $prod_id = $product['id'];
        
            if ($prod_amount < $number) {
                $number = $prod_amount;
            }
        
            $add_order_prod_query = "INSERT INTO `order_prod` (order_id, number, prod_id) VALUES ('$order_id', '$number', '$prod_id')";
            $add_order_prod = mysqli_query($conn, $add_order_prod_query);
            header("Location: ../order.php");
        } 
        catch(Exception )
        {
            echo "<script> alert('There are no submited orders');</script>";
            header("Location: ../order.php");
        }   
    }
    else 
    {
        echo "<script> alert('You must log in first');</script>";
        header("Location: ../order.php");
    }
}

function totalcost()
{
    $servername = "localhost"; 
    $username = "root"; 
    $password = "";
    $database = "paradoteo_03";
    $conn = mysqli_connect($servername, $username, $password, $database);

    $tcost = 0 ; 
    if(isset($_GET['add'])||isset($_GET['submit']))
    {
        try 
        {
            if(isset($_COOKIE['id']))
            {
            $user_id = $_COOKIE['id']; 
            $cost_query = "SELECT cost FROM orders WHERE user_id='$user_id' ORDER BY id DESC LIMIT 1"; 
            $result = mysqli_query($conn , $cost_query); 
            $cost_query =(int) mysqli_fetch_array($result , MYSQLI_ASSOC)['cost'] ; 
            $tcost =$tcost + $cost_query ;
            $x = "Total Cost: ".$tcost."$" ; 
            header("Location: ../order.php");
            }
        }
        catch(Exception)
        {
            echo "<script> alert('You must log in first');</script>";
            header("Location: ../order.php");
        }

    }
}
?>