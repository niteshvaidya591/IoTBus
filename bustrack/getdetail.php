<?php
include "config.php";
$response["data"]["bus"]=array();
$sql = mysql_query("SELECT * FROM driver")or die(mysql_error());
if(mysql_affected_rows()>0)
{
	$response["data"]["status"]=1;
	while($row=mysql_fetch_array($sql))
			{
				$profile=array();
				$profile["pc"]=$row['pc'];
				$profile["ac"]=$row['ac'];
				$profile["rc"]=$row['rc'];
				
				array_push($response["data"]["bus"],$profile);
			}
}
else
{
$response["data"]["status"]=0;
}
echo json_encode($response);
?>