<?php
include_once __DIR__ . "/../Repositorio/ventaRepositorio.inc";
include_once __DIR__ . "/../Repositorio/librosRepositorio.inc";
include_once __DIR__ . "/../Repositorio/reservaRepositorio.inc";
include_once __DIR__ . "/../Repositorio/detallesVentaRepositorio.inc";
class VentaController
{
		public function confirmarVenta(){
				if($_SERVER['REQUEST_METHOD']=='POST'){
						$envio = true;
						$precioTotal = (float)$_POST['precioTotal'];
						//sacamos el carrito del usuario y comprobamos que no este vacio
						$carrito = (new LibrosReservadosRepositorio)->devolverCarrito($_SESSION['userNombre']);
						if($carrito == null){
							$error = "El carrito está vacio";
						}else{
									//primero insertamos la venta
									$boolConfVenta = (new VentaRepositorio)->insertarVenta($_SESSION['userNombre'],$precioTotal);
									if($boolConfVenta){
												$boolBorrarCarrito = (new ReservaRepositorio())->borrarCarrito($_SESSION['userNombre']);
												if($boolBorrarCarrito){
													//sacamos el id de la venta recien ingresada
													$idVenta = (new VentaRepositorio)->sacarIdVenta($_SESSION['userNombre']);
													//luego insertamos la linea venta, necesitamos el carrito
													$boolIntroducirLineas = (new DetallesVentaRepositorio)->insertarLineaVenta($idVenta,$carrito);
													/////////////////////////////////
													if($boolIntroducirLineas){
														$error ="La venta y sus lineas han sido ingresadas";
													}
												}else{
													$error ="Ha hadido problemas y no ha podido ser ingresada";
												}
									}else{
										$error ="Ha hadido problemas y no ha podido ser ingresada";
									}

						}
				}
				$compras = (new DetallesVentaRepositorio)->devolverLineasVentaCliente($_SESSION['userNombre']);
				$arrayTitulos = (new DetallesVentaRepositorio)->devolverTitulosLineaVenta($compras);
				$arrayTiendas = (new DetallesVentaRepositorio)->devolverTiendasLineaVenta($compras);
        include_once __DIR__ .'/../../app/plantillas/usuario/verMisCompras.php';
    }//fin metodo

		public function verUsuariosCompras(){
			$idTienda = (int)$_SESSION['idTienda'];
			$listaUsuarios = (new VentaRepositorio)->devolverListaUsuariosTienda($idTienda);
			include_once __DIR__ .'/../../app/plantillas/AdministradorTienda/verUsuariosCompras.php';
		}

}//fin clase
