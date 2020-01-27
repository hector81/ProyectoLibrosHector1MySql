<?php
include_once __DIR__ . "/../Repositorio/librosReservadosRepositorio.inc";
class LibrosReservadosController
{
    public function confirmarReservaUsuario(){
    		if($_SERVER['REQUEST_METHOD']=='POST'){
      			if( (empty($_POST['IdEjemplar']) && isset($_POST['IdEjemplar']))
      				&& (empty($_POST['cantidad']) && isset($_POST['cantidad']))
      				&& (empty($_POST['pReserva']) && isset($_POST['pReserva']))
      				&& (empty($_POST['IdTienda']) && isset($_POST['IdTienda']))){
		              $error = 'Algún dato no ha sido bien enviado y no se puede realizar la reserva';
		         }else{///capturamos variables
                $usuario = $_SESSION['userNombre'];
                $idEjemplar = (int)$_POST['IdEjemplar'];
                $cantidad = (int)$_POST['cantidad'];
                $cantidadTotal = (float)$_POST['pReserva'];
                $idTienda = $_POST['IdTienda'];
                ///comprobamos que en la reserva no este duplicada el mismo ejemplar y en la misma tienda
                $boolLibrosReservadosDuplicados = (new LibrosReservadosRepositorio())->comprobarLibrosReservadosDuplicados($usuario
                ,$idEjemplar,$idTienda);
                if(!$boolLibrosReservadosDuplicados){//si no esta duplicado el mismo ejemplar y en la misma tienda
                    //inseertamos
                    $boolInsercionLibrosReservados = (new LibrosReservadosRepositorio())->insertarLineaReservaLibro($usuario,$idEjemplar,$cantidad,$cantidadTotal,$idTienda) ;
                    if(!$boolInsercionLibrosReservados){//si ha insertado la venta
                      //quitamos la cantidad del almacen de la tienda
                      $boolQuitarStockCantidad = (new AlmacenRepositorio())->quitarStockExistencias($idTienda,$idEjemplar,$cantidad);
                          if($boolQuitarStockCantidad){
                            $carrito = (new LibrosReservadosRepositorio)->devolverCarrito($_SESSION['userNombre']);
                            $arrayTitulos = (new LibrosReservadosRepositorio)->devolverTitulosCarrito($carrito);
                            $arrayTiendas = (new LibrosReservadosRepositorio)->devolverTiendasCarrito($carrito);
                            $error = 'El artículo ha sido reservado y está insertado en reservas';
                          }else{
                            $carrito = (new LibrosReservadosRepositorio)->devolverCarrito($_SESSION['userNombre']);
                            $arrayTitulos = (new LibrosReservadosRepositorio)->devolverTitulosCarrito($carrito);
                            $arrayTiendas = (new LibrosReservadosRepositorio)->devolverTiendasCarrito($carrito);
                            $error = 'Ha habido un error y no se ha podido realizar la reserva';
                          }
                    }else{
                        $error = 'El artículo no ha sido reservado por algun problema';
                    }
                }//y si esta duplucado en la misma tienda el mismo ejemplar
                else{
                    //si esta duplicada cogemos el carrito del usuario y le sumamos la cantidad a la que ya tiene
                    $PVPlibro = (float)$_POST['PVPlibro'];
                    $boolSumarCANTIDADejemplarDUPLICADO = (new LibrosReservadosRepositorio)->sumarCantidadEjemplarDuplicado($usuario,$idEjemplar,$idTienda,$cantidad,$PVPlibro);
                        if($boolSumarCANTIDADejemplarDUPLICADO){
                            //una vez hecho el paso anterior quitamos la cantidad del stock del almacen
                            $boolQuitarStockCantidad = (new AlmacenRepositorio())->quitarStockExistencias($idTienda,$idEjemplar,$cantidad);
                            if($boolQuitarStockCantidad){
                              $carrito = (new LibrosReservadosRepositorio)->devolverCarrito($_SESSION['userNombre']);
                              $arrayTitulos = (new LibrosReservadosRepositorio)->devolverTitulosCarrito($carrito);
                              $arrayTiendas = (new LibrosReservadosRepositorio)->devolverTiendasCarrito($carrito);
                              $error = 'El artículo estaba ya reservado en la misma tienda y lo que hemos hecho es sumar la nueva cantidad a la ya pedida';
                            }else{
                              $carrito = (new LibrosReservadosRepositorio)->devolverCarrito($_SESSION['userNombre']);
                              $arrayTitulos = (new LibrosReservadosRepositorio)->devolverTitulosCarrito($carrito);
                              $arrayTiendas = (new LibrosReservadosRepositorio)->devolverTiendasCarrito($carrito);
                              $error = 'Ha habido un error y no se ha podido realizar la reserva';
                            }
                        }else{
                            $error = 'Algún dato no ha sido bien enviado y no se puede realizar la reserva';
                        }
                }
              }
        }
        $carrito = (new LibrosReservadosRepositorio)->devolverCarrito($_SESSION['userNombre']);
        $arrayTitulos = (new LibrosReservadosRepositorio)->devolverTitulosCarrito($carrito);
        $arrayTiendas = (new LibrosReservadosRepositorio)->devolverTiendasCarrito($carrito);
        include_once __DIR__ . "/../../app/plantillas/usuario/verCarrito.php";
    }//fin metodo

    public function verCarrito(){
      		$carrito = (new LibrosReservadosRepositorio)->devolverCarrito($_SESSION['userNombre']);
      		$arrayTitulos = (new LibrosReservadosRepositorio)->devolverTitulosCarrito($carrito);
      		$arrayTiendas = (new LibrosReservadosRepositorio)->devolverTiendasCarrito($carrito);
      		include_once __DIR__ . "/../../app/plantillas/usuario/verCarrito.php";
     }//fin metodo

	public function borrarLineaDelCarrito(){
		if($_SERVER['REQUEST_METHOD']=='POST'){
			$idEjemplar = (int)$_POST['idEjemplar'];
      $IdTienda = (int)$_POST['IdTienda'];
      $cantidad = (int)$_POST['cantidad'];
      //borramos esa linea de reserva
			$boolBorrarLineasLibroReserva = (new LibrosReservadosRepositorio)->borrarLineaLibrosReservados($_SESSION['userNombre'], $idEjemplar,$IdTienda);
			if($boolBorrarLineasLibroReserva){
        //devolvemos la cantidad reservada al almacen
        $booldevolverStockCantidad = (new AlmacenRepositorio())->sumarCantidadStockExistencias($IdTienda,$idEjemplar,$cantidad);
        if($booldevolverStockCantidad){
            //comprobamos el numero de reservas que tiene el usuario
            $numeroLineasReserva = (new LibrosReservadosRepositorio)->devolverLineasReservaPorUsuario($_SESSION['userNombre']);
            //si el numero de reservas no tenía lineas borramos, en caso contrario no borramos
            if($numeroLineasReserva == 0){
                  (new ReservaRepositorio())->borrarReservaUsuario($_SESSION['userNombre']);
            }
            $error = 'Ha sido borrada una linea del pedido';
        }

			}
		}
		$carrito = (new LibrosReservadosRepositorio)->devolverCarrito($_SESSION['userNombre']);
		$arrayTitulos = (new LibrosReservadosRepositorio)->devolverTitulosCarrito($carrito);
		$arrayTiendas = (new LibrosReservadosRepositorio)->devolverTiendasCarrito($carrito);
		include_once __DIR__ . "/../../app/plantillas/usuario/verCarrito.php";
	}//fin metodo

  public function borrarCarrito(){
    //primero devolvemos todas las cantidades de las lineas de reserva al almacen
    $carrito = (new LibrosReservadosRepositorio)->devolverCarrito($_SESSION['userNombre']);
    //devolvemos la cantidad de libros reservados al almacen
    $devolverLineasCarritoAlmacen = (new LibrosReservadosRepositorio)->devolverLibrosReservadosAlALmacen($carrito);
    //si devuelve bien todas las lineas canitdades devueltas, borramos el carrito
    $boolBorrarCarrito = (new ReservaRepositorio())->borrarCarrito($_SESSION['userNombre']);
          if($boolBorrarCarrito && $devolverLineasCarritoAlmacen){
               $error = 'Has cancelado todo el carrito';
               $carrito = (new LibrosReservadosRepositorio)->devolverCarrito($_SESSION['userNombre']);
               $arrayTitulos = (new LibrosReservadosRepositorio)->devolverTitulosCarrito($carrito);
               $arrayTiendas = (new LibrosReservadosRepositorio)->devolverTiendasCarrito($carrito);

          }
    include_once __DIR__ . "/../../app/plantillas/usuario/verCarrito.php";
  }//fin metodo


}//fin clase
?>
