<?php

require_once('../config/config.inc.php');

if (!isset($_POST['table']) || !isset($_POST['columnsName']))
  return ;

$table = $_POST['table'];
$columns_name = $_POST['columnsName'];

$cfdtdp = array();
$columns = array();

foreach ($columns_name as $key => $value)
{
  $cfdtdp[$value] = $key;
  $columns[] = array(
    'db' => $value,
    'dt' => $key,
    'dp' => $value,
  );
}

if ($_SERVER['REMOTE_ADDR'] == '127.0.0.1')
    $access = accessBdd();
else
    $access = accessBdd('axis');
$sql_details = array (
    'user' => $access['user'],
    'pass' => $access['pass'],
    'db' => $access['base'],
    'host' => $access['host']
);

require('ssp.class.php');

$result = SSP::simple($_POST, $sql_details, $table, $_POST['columnsName'][0], $columns, '');

echo (json_encode($result));
