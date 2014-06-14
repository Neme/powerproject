<?php

error_reporting(E_ALL);

// set the new directory
chdir(dirname(__DIR__));

require('bootstrap/bootstrap.php');
$app = new Bootstrap();

?>