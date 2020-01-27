<?php
include_once __DIR__ . "/../Repositorio/librosRepositorio.inc";
include_once __DIR__ . "/../Repositorio/reservaRepositorio.inc";
include_once __DIR__ . "/../Repositorio/almacenRepositorio.inc";
include_once __DIR__ . "/../Repositorio/tiendasRepositorio.inc";
include_once __DIR__ . "/../Repositorio/librosReservadosRepositorio.inc";
class ReservaController
{
  public function comprarLibroUsuarioReserva(){
     $tiendas = (new TiendasRepositorio())->devolverTiendasTotales();

     $tiendas = (new TiendasRepositorio)->devolverTiendasTotales();
     $nombreCategoria = $_POST['nombreCategoria'];$idLibro = (int)$_POST['idLibro'];
     $idCategoria = (new LibrosRepositorio)->devolverIdCategoria($nombreCategoria);
     $libroIndividual = (new LibrosRepositorio)->verLibrosIndividual($idLibro);
     $existenciasLibroPorTienda =(new TiendasRepositorio)->devolverExistenciasLibroPorTienda($tiendas,$idLibro);


     $libroIndividual = (new LibrosRepositorio)->verLibrosIndividual((int)$_POST['idLibro']);
     if($_SERVER['REQUEST_METHOD']=='POST'){
         if(empty($_POST['idTienda']) && isset($_POST['idTienda'])){
             $error = 'Debes seleccionar una tienda';
             include_once __DIR__ . "/../../app/plantillas/usuario/verLibrosIndividualUsuario.php";
         }elseif(empty($_POST['cantidad']) && isset($_POST['cantidad']) && !is_numeric($_POST['cantidad']) ){
             $error = 'Debes seleccionar una cantidad y esta tiene que ser mayor que 0';
             include_once __DIR__ . "/../../app/plantillas/usuario/verLibrosIndividualUsuario.php";
         }else{
             $cantidad = (int)$_POST['cantidad'];
                 if($cantidad > 0){
                   //primero comprobamos que haya existencias en esa tienda
                   //capturamos variables
                   $idLibro = (int)$_POST['idLibro'];
                   $usuario = $_SESSION['userNombre'];//es el nombre de nick //
                   $idEjemplar = (int)$_POST['IdEjemplar'];
                   $idTienda = (int)$_POST['idTienda'];
                   //comprobamos que hay existencias y que la cantidad sea menor o igual que el stock
                   $boolHayExistencias = (new AlmacenRepositorio())->comprobarStockExistencias($idTienda,$idEjemplar);
                   $compararPedidoExistenciaCantidad = (new AlmacenRepositorio())->compararPedidoExistenciaStockEjemplar($idTienda,$idEjemplar,$cantidad);
                   if($boolHayExistencias){
                      if($compararPedidoExistenciaCantidad){
                            //Si hay existencias comprobamos que este usuario tenga reservas
                            $tieneClientesMasRerservas = (new ReservaRepositorio())->comprobarClienteNumeroReserva($usuario);
                            //si no tiene reservas ,insertamos una
                            if($tieneClientesMasRerservas){
                               $boolReservaInsertada = (new ReservaRepositorio())->insertarReserva($usuario);
                               include_once __DIR__ . "/../../app/plantillas/usuario/comprarLibroUsuarioReserva.php";

                            }else{
                                include_once __DIR__ . "/../../app/plantillas/usuario/comprarLibroUsuarioReserva.php";
                            }
                      }else{
                            $error = 'La cantidad de libros sobrepasa el stock del libro en esta tienda';
                            include_once __DIR__ . "/../../app/plantillas/usuario/verLibrosIndividualUsuario.php";
                      }
                   }else{
                      $error = 'En esta tienda no hay stock para este libro';
                      include_once __DIR__ . "/../../app/plantillas/usuario/verLibrosIndividualUsuario.php";
                   }
                 }else{
                   $error = 'La cantidad a reservar no puede ser menor de 1';
                   include_once __DIR__ . "/../../app/plantillas/usuario/verLibrosIndividualUsuario.php";
                 }

         }
     }else{
         $error = 'Se ha producido algún error';
         include_once __DIR__ . "/../../app/plantillas/usuario/verLibrosIndividualUsuario.php";
     }
  }//fin metodo

  public function cancelarReservaUsuario(){
    include_once __DIR__ . "/../Repositorio/librosReservadosRepositorio.inc";
    $tiendas = (new TiendasRepositorio())->devolverTiendasTotales();
        if($_SERVER['REQUEST_METHOD']=='POST'){
          //capturamos variables
          $idLibro = (int)$_POST['idLibro'];
          $usuario = $_SESSION['userNombre'];//es el nombre de nick //
          $cantidad = (int)$_POST['cantidad'];
          $idEjemplar = (int)$_POST['IdEjemplar'];
          $idTienda = (int)$_POST['IdTienda'];
          //comprobamos el numero de reservas que tiene el usuario
          $numeroLineasReserva = (new LibrosReservadosRepositorio)->devolverLineasReservaPorUsuario($usuario);
          //si el numero de reservas no tenía lineas borramos, en caso contrario no borramos
          if($numeroLineasReserva == 0){
                (new ReservaRepositorio())->borrarReservaUsuario($usuario);
          }
          $error = 'Has cancelado la última reserva';
          $carrito = (new LibrosReservadosRepositorio)->devolverCarrito($_SESSION['userNombre']);
          $arrayTitulos = (new LibrosReservadosRepositorio)->devolverTitulosCarrito($carrito);
          $arrayTiendas = (new LibrosReservadosRepositorio)->devolverTiendasCarrito($carrito);
          include_once __DIR__ . "/../../app/plantillas/usuario/verCarrito.php";
        }
  }//fin metodo



}//fin clase

?>
