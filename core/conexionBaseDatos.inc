<?php
require_once __DIR__ . '/../app/config/config.php';

class conexionBaseDatos {
    private $con;

    public function __construct(){
          $parametrosConfig = (new Configuracion())->getParametros();
		  $this->con = new PDO("mysql:host=localhost;dbname=". $parametrosConfig['database'] . "", $parametrosConfig['user'], $parametrosConfig['password']);
    }//fin constructor

    public function getConexion(){
        return $this->con;
    }
}




 ?>
