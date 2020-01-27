<?php

class Configuracion {
  private $parametrosConfiguracion = [];

  public function __construct(){
      $this->parametrosConfiguracion = [
          'server' => 'localhost',
          'port' => '3306',
          'database' => 'gestionlibrossql',
          'user' => 'HectorGarcia',
          'password' => 'HectorGarcia',
          'charset' => 'utf-8',
		  'socket' => '',
		  'host' => '127.0.0.1'
      ];
  }

  public function getParametros() :array{
      return $this->parametrosConfiguracion;
  }

}



 ?>
