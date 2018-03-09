<?php

require_once('../config/config.inc.php');
require_once('../plugins/vendor/autoload.php');

if (!isset($_GET['action']))
  return ;

if ($_SERVER['REMOTE_ADDR'] == '127.0.0.1')
  $access = accessBdd('local');
else
  $access = accessBdd('production');

$em = getManager();

$rp = $em->getRepository('products');

$QBConfig = array(
  'driver' => 'mysql',
  'host' => $access['host'],
  'database' => $access['base'],
  'username' => $access['user'],
  'password' => $access['pass'],
);

new \Pixie\Connection('mysql', $QBConfig, 'QB');

if ($_GET['action'] == 'load_table_names')
{
  echo (json_encode(QB::table('INFORMATION_SCHEMA.TABLES')->select('TABLE_NAME')->where('TABLE_TYPE', '=', 'BASE TABLE')->where('TABLE_SCHEMA', '=', 'secret')->get()));
}

else if ($_GET['action'] == 'load_column_names')
{
  $table_name = $_GET['table'];
  $pdo = QB::pdo();

  $q = $pdo->prepare("SHOW columns FROM " . $table_name);
  $q->execute();
  $table_fields = $q->fetchAll();
  echo (json_encode($table_fields));
}
