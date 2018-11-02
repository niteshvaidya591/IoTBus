<?php
include "config.php";
$lat=$_REQUEST["lat"];
$lang=$_REQUEST["lang"];

$query=mysql_query("update `driver` set `lat`='$lat',`lng`='$lang' where email='bharathr404@gmail.com'")or die(mysql_error());
if($query)
{
		
	$response["data"]["status"]="1" ;
	
}
else
{	
	$response["data"]["status"]="0";
}
echo json_encode($response);
?>

