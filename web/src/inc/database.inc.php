<?php
	
	$dbConnection = new MySQLi(MYSQL_HOST,MYSQL_USERNAME,MYSQL_PASSWORD,MYSQL_DATABASE);
	if($dbConnection->connect_errno) {
		echo "Can't connect to database";
	}
?>