<?php
include_once __DIR__ . "/../Repositorio/detallesVentaRepositorio.inc";
include_once __DIR__ . "/../Repositorio/almacenRepositorio.inc";
class DetallesVentaController
{
  public function verMisCompras(){
      $compras = (new DetallesVentaRepositorio)->devolverLineasVentaCliente($_SESSION['userNombre']);
      $arrayTitulos = (new DetallesVentaRepositorio)->devolverTitulosLineaVenta($compras);
      $arrayTiendas = (new DetallesVentaRepositorio)->devolverTiendasLineaVenta($compras);
      include_once __DIR__ .'/../../app/plantillas/usuario/verMisCompras.php';
  }//fin metodo

  public function verTodasLasVentas(){
      $compras = (new DetallesVentaRepositorio)->devolverTodasLasVentasClientes();
      $arrayTitulos = (new DetallesVentaRepositorio)->devolverTitulosLineaVenta($compras);
      $arrayTiendas = (new DetallesVentaRepositorio)->devolverTiendasLineaVenta($compras);
      include_once __DIR__ .'/../../app/plantillas/administrador/verTodasLasVentas.php';
  }//fin metodo

  public function verVentasMiTienda(){
      $idTienda =(int)$_SESSION['idTienda'];
      $compras = (new DetallesVentaRepositorio)->devolverTodasLasVentasTienda($idTienda);
      $arrayTitulos = (new DetallesVentaRepositorio)->devolverTitulosLineaVenta($compras);
      include_once __DIR__ .'/../../app/plantillas/administradorTienda/verVentasMiTienda.php';
  }//fin metodo

  public function confirmarPagoLinea(){
      $idTienda =(int)$_POST['IdTienda'];
      $idVenta =(int)$_POST['IdVenta'];
      $idEjemplar =(int)$_POST['IdEjemplar'];
      $boolPago = false;
      $confirmarPagoLinea = (new DetallesVentaRepositorio)->confirmarPagoLinea($idTienda,$idVenta,$idEjemplar,$boolPago);
      if($confirmarPagoLinea){
          $error = 'El pago ha sido confirmado';
      }else{
          $error = 'El pago no ha podido ser confirmado por algún error técnico';
      }
      $idMiTienda =(int)$_SESSION['idTienda'];
      $compras = (new DetallesVentaRepositorio)->devolverTodasLasVentasTienda($idMiTienda);
      $arrayTitulos = (new DetallesVentaRepositorio)->devolverTitulosLineaVenta($compras);
      include_once __DIR__ .'/../../app/plantillas/administradorTienda/verVentasMiTienda.php';
  }//fin metodo

  public function anularLineaPedido(){
      $idTienda =(int)$_POST['IdTienda'];
      $idVenta =(int)$_POST['IdVenta'];
      $idEjemplar =(int)$_POST['IdEjemplar'];
      $boolNulo = false;
      //en este caso devolvemos el stock de este pedido al almacen
      //devolvemos la cantidad reservada al almacen
      $cantidad = (new DetallesVentaRepositorio)->devolverCantidadLineaVenta($idTienda,$idVenta,$idEjemplar);
      $booldevolverStockCantidad = (new AlmacenRepositorio())->sumarCantidadStockExistencias($idTienda,$idEjemplar,$cantidad);
      if($booldevolverStockCantidad){
          $confirmaAnulaLinea = (new DetallesVentaRepositorio)->anularLineaPedido($idTienda,$idVenta,$idEjemplar,$boolNulo);
          if($confirmaAnulaLinea){
              $error = 'El pedido ha sido anulado';
          }else{
              $error = 'El pedido no ha sido anulado por algún error técnico';
          }
      }else{
          $error = 'El pedido no ha sido anulado por algún error técnico';
      }

      $idMiTienda =(int)$_SESSION['idTienda'];
      $compras = (new DetallesVentaRepositorio)->devolverTodasLasVentasTienda($idMiTienda);
      $arrayTitulos = (new DetallesVentaRepositorio)->devolverTitulosLineaVenta($compras);
      include_once __DIR__ .'/../../app/plantillas/administradorTienda/verVentasMiTienda.php';
  }//fin metodo

  public function anularLineaPedidoSuperAdministrador(){
      $idTienda =(int)$_POST['IdTienda'];
      $idVenta =(int)$_POST['IdVenta'];
      $idEjemplar =(int)$_POST['IdEjemplar'];
      $boolNulo = false;
      //en este caso devolvemos el stock de este pedido al almacen
      //devolvemos la cantidad reservada al almacen
      $cantidad = (new DetallesVentaRepositorio)->devolverCantidadLineaVenta($idTienda,$idVenta,$idEjemplar);
      $booldevolverStockCantidad = (new AlmacenRepositorio())->sumarCantidadStockExistencias($idTienda,$idEjemplar,$cantidad);
      if($booldevolverStockCantidad){
          $confirmaAnulaLinea = (new DetallesVentaRepositorio)->anularLineaPedido($idTienda,$idVenta,$idEjemplar,$boolNulo);
          if($confirmaAnulaLinea){
              $error = 'El pedido ha sido anulado';
          }else{
              $error = 'El pedido no ha sido anulado por algún error técnico';
          }
      }else{
          $error = 'El pedido no ha sido anulado por algún error técnico';
      }

      $compras = (new DetallesVentaRepositorio)->devolverTodasLasVentasTienda($idTienda);
      $arrayTitulos = (new DetallesVentaRepositorio)->devolverTitulosLineaVenta($compras);
      $nombreTienda = (new DetallesVentaRepositorio)->devolverNombreTiendaPorIdTiendaVenta($idTienda);
      include_once __DIR__ .'/../../app/plantillas/administrador/verVentasTiendaSuperAdministrador.php';
  }

  public function confirmarPagoLineasuperAdministrador(){
      $idTienda =(int)$_POST['IdTienda'];
      $idVenta =(int)$_POST['IdVenta'];
      $idEjemplar =(int)$_POST['IdEjemplar'];
      $boolPago = false;
      $confirmarPagoLinea = (new DetallesVentaRepositorio)->confirmarPagoLinea($idTienda,$idVenta,$idEjemplar,$boolPago);
      if($confirmarPagoLinea){
          $error = 'El pago ha sido confirmado';
      }else{
          $error = 'El pago no ha podido ser confirmado por algún error técnico';
      }
      $nombreTienda =$_POST['nombreTienda'];
      $compras = (new DetallesVentaRepositorio)->devolverTodasLasVentasTienda($idTienda);
      $arrayTitulos = (new DetallesVentaRepositorio)->devolverTitulosLineaVenta($compras);
      include_once __DIR__ .'/../../app/plantillas/administrador/verVentasTiendaSuperAdministrador.php';
  }//fin metodo

  public function verVentasTiendaSuperAdministrador(){
      $idTienda =(int)$_POST['idTienda'];
      $nombreTienda =$_POST['nombreTienda'];
      $compras = (new DetallesVentaRepositorio)->devolverTodasLasVentasTienda($idTienda);
      $arrayTitulos = (new DetallesVentaRepositorio)->devolverTitulosLineaVenta($compras);
      include_once __DIR__ .'/../../app/plantillas/administrador/verVentasTiendaSuperAdministrador.php';
  }//fin metodo

}//fin clase
?>
