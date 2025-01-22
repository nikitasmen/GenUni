<?php
$servername = "localhost"; 
$username = "root"; 
$password = "";
$database = "paradoteo_03";

// Create a connection 
$conn = mysqli_connect($servername, $username, $password, $database);

$name = $_GET['name']; 
$psd = $_GET['psd']; 

$login_query = "SELECT id FROM user WHERE (full_name = '$name' AND password='$psd' )"; 
$result = mysqli_query($conn , $login_query); 
if(mysqli_num_rows($result)>0)
{
    $user_id = mysqli_fetch_array($result,MYSQLI_ASSOC)['id']; 
    $user_id = (int) $user_id ; 
    setcookie("name", "", time()-3600);
    setcookie("psd","",time()-3600);
    setcookie("id",$user_id,time()+3600,"/");
    header("Location: ../index.html");
}
else 
{
    echo '<script type="text/javascript"> alert("Username or password is incorrect"); </script>';
    header("Location: ../index.html");
}
?>