<?php

define('DB_SERVER','localhost');
define('DB_USERNAME','ROOT');
define('DB_PASSWORD','');
define('DB_NAME','demo');

//CONNECT TO MYSQL
$mysqli = new mysqli(DB_SERVER,DB_USERNAME,DB_PASSWORD,DB_NAME);

//CHECK CONNECTION
if($mysqli === false){
    die("ERROR: Could not connect. " . $mysqli->connect_error);
}
?>
