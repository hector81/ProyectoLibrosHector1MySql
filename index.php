<?php
session_start();
require_once __DIR__ . '/app/config/rutas.php';
require_once __DIR__ . '/fuente/Controller/almacenController.inc';
require_once __DIR__ . '/fuente/Controller/autoresController.inc';
require_once __DIR__ . '/fuente/Controller/categoriasController.inc';
require_once __DIR__ . '/fuente/Controller/ciudadesController.inc';
require_once __DIR__ . '/fuente/Controller/ventaController.inc';
require_once __DIR__ . '/fuente/Controller/detallesVentaController.inc';
require_once __DIR__ . '/fuente/Controller/editorialesController.inc';
require_once __DIR__ . '/fuente/Controller/ejemplaresController.inc';
require_once __DIR__ . '/fuente/Controller/librosController.inc';
require_once __DIR__ . '/fuente/Controller/librosReservadosController.inc';
require_once __DIR__ . '/fuente/Controller/paisesController.inc';
require_once __DIR__ . '/fuente/Controller/provinciasController.inc';
require_once __DIR__ . '/fuente/Controller/reservaController.inc';
require_once __DIR__ . '/fuente/Controller/subCategoriasController.inc';
require_once __DIR__ . '/fuente/Controller/tiendasController.inc';
require_once __DIR__ . '/fuente/Controller/usuarioController.inc';
require_once __DIR__ . '/fuente/Controller/superAdministradorController.inc';
require_once __DIR__ . '/fuente/Controller/administradorTiendaController.inc';


if(isset($_GET['ctl'])){
    if(isset($mapeoRutas[$_GET['ctl']])){
        $ruta = $_GET['ctl'];
    }else{
        header('Status: 404 not found');
        echo 'La ruta '.$_GET['ctl']. ' no existe' ;
    }
}else{
  $ruta = 'inicio';
}

$controlador = $mapeoRutas[$ruta];

if(method_exists($controlador['controller'],$controlador['action'])){
    call_user_func(array(new $controlador['controller'],$controlador['action']));
}else{
  header('Status: 404 not found');
  echo 'El controlador '.$controlador['action']. ' no existe. No se encuentra el el controlador '.$controlador['controller'] ;
}

?>
