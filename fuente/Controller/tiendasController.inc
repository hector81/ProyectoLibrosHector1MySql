<?php
include_once __DIR__ . "/../Repositorio/tiendasRepositorio.inc";
class TiendasController
{
	public function tiendas(){
		$tiendaInicial = (new TiendasRepositorio())->devolverTiendaInicial();
		$tiendaTotal = (new TiendasRepositorio())->devolverTiendasTotales();
		$arrayCiudadProvincias = (new TiendasRepositorio)->devolverArrayCiudadProvincias($tiendaInicial);
		include_once __DIR__ .'/../../app/plantillas/visitante/tiendas.php';
	}//fin metodo

	public function verTiendasUsuario(){
		$tiendaInicial = (new TiendasRepositorio())->devolverTiendaInicial();
		$tiendaTotal = (new TiendasRepositorio())->devolverTiendasTotales();
		$arrayCiudadProvincias = (new TiendasRepositorio)->devolverArrayCiudadProvincias($tiendaInicial);
		include_once __DIR__ .'/../../app/plantillas/usuario/verTiendasUsuario.php';
	}//fin metodo

	public function verTiendasUsuarioPorId(){
		$tiendaInicial = (new TiendasRepositorio())->devolverTiendaIndividual($_GET['idTienda']);
		$tiendaTotal = (new TiendasRepositorio())->devolverTiendasTotales();
		$arrayCiudadProvincias = (new TiendasRepositorio)->devolverArrayCiudadProvincias($tiendaInicial);
		include_once __DIR__ .'/../../app/plantillas/usuario/verTiendasUsuarioPorId.php';
	}//fin metodo

	public function verTiendasIndividual(){
		$tiendaTotal = (new TiendasRepositorio())->devolverTiendasTotales();
		if($_SERVER['REQUEST_METHOD']=='GET'){
			if(empty($_GET['idTienda']) && isset($_GET['idTienda'])){
				$tiendaInicial = (new TiendasRepositorio())->devolverTiendaInicial();
				$error = 'Hay algún problema con la base de datos';
			}else{
				$tiendaInicial = (new TiendasRepositorio())->devolverTiendaIndividual($_GET['idTienda']);
			}
		}
		$arrayCiudadProvincias = (new TiendasRepositorio)->devolverArrayCiudadProvincias($tiendaInicial);
		include_once __DIR__ .'/../../app/plantillas/visitante/tiendas.php';
	}//fin metodo

	public function verTiendasIndividualAdministrador(){
		if($_SERVER['REQUEST_METHOD']=='GET'){
			if(empty($_GET['idTienda']) && isset($_GET['idTienda'])){
				$tiendaInicial = (new TiendasRepositorio())->devolverTiendaInicial();
				$error = 'Hay algún problema con la base de datos';
			}else{
				$tiendaInicial = (new TiendasRepositorio())->devolverTiendaIndividual($_GET['idTienda']);
			}
		}
		$arrayCiudadProvincias = (new TiendasRepositorio)->devolverArrayCiudadProvincias($tiendaInicial);
		include_once __DIR__ .'/../../app/plantillas/administrador/verTiendasIndividualAdministrador.php';
	}//fin metodo

	public function verTienda(){
		if($_SERVER['REQUEST_METHOD']=='GET'){
			if(empty($_GET['idTienda']) && isset($_GET['idTienda'])){
				$tiendaInicial = (new TiendasRepositorio())->devolverTiendaInicial();
				$error = 'Hay algún problema con la base de datos';
			}else{
				$tiendaInicial = (new TiendasRepositorio())->devolverTiendaIndividual($_GET['idTienda']);
			}
		}
		$miTienda = (new TiendasRepositorio())->devolverTiendaIndividual($_SESSION['idTienda']);
		$arrayCiudadProvincias = (new TiendasRepositorio)->devolverArrayCiudadProvincias($tiendaInicial);
		include_once __DIR__ .'/../../app/plantillas/administradorTienda/verTienda.php';
	}//fin metodo

	public function administrarTiendas(){
		$tiendaTotal = (new TiendasRepositorio())->devolverTiendasTotales();
		$arrayCiudadProvincias = (new TiendasRepositorio)->devolverArrayCiudadProvincias($tiendaTotal);
		include_once __DIR__ .'/../../app/plantillas/administrador/administrarTiendas.php';
	}//fin metodo



	public function borrarTiendaAdministradores(){
		if($_SERVER['REQUEST_METHOD']=='GET'){
			if(empty($_GET['idTienda']) && isset($_GET['idTienda'])){
				$error = 'Hay algún problema con la base de datos y no ha podido ser borrada';
			}else{
			if(!$_GET['activo']){//no tiene administrador. se puede borrarTienda
					$idTienda = (int)$_GET['idTienda'];
					$borrarTiendaBool = (new TiendasRepositorio())->borrarTienda($idTienda);
					if($borrarTiendaBool){
						$error = 'La tienda ha sido eliminada';
					}else{
						$error = 'Hay algún problema con la base de datos y no ha podido ser borrada';
					}
				}else{//si tiene administrador
						$error = 'La tienda no puede ser eliminada porque tiene un administrador.Primero hay que borrar el administrador';
				}
			}
		}
		$tiendaTotal = (new TiendasRepositorio())->devolverTiendasTotales();
		include_once __DIR__ .'/../../app/plantillas/administrador/administrarTiendas.php';
	}//fin metodo

	public function modificarTiendaAdministrador(){
		if(empty($_GET['idTienda']) && isset($_GET['idTienda'])){
			$error = 'Hay algún problema con la base de datos y no pueden mostrarse los datos';
		}else{
			$tienda = (new TiendasRepositorio())->devolverTiendaIndividual($_GET['idTienda']);
			$idTienda =(int)$_GET['idTienda'];
			$nombreCiudad = (new TiendasRepositorio())->devolverCiudadTienda($idTienda);
		}
		include_once __DIR__ .'/../../app/plantillas/administrador/modificarTiendaAdministrador.php';
	}//fin metodo

	public function modificarTiendaAdministradorTienda(){
		if(empty($_GET['idTienda']) && isset($_GET['idTienda'])){
			$error = 'Hay algún problema con la base de datos y no pueden mostrarse los datos';
		}else{
			$tienda = (new TiendasRepositorio())->devolverTiendaIndividual($_GET['idTienda']);
		}
		include_once __DIR__ .'/../../app/plantillas/administradorTienda/modificarTiendaAdministradorTienda.php';
	}//fin metodo

	public function enviarDatosModificacionTienda(){
		if($_SERVER['REQUEST_METHOD'] == 'POST'){
            if(empty($_POST['nombreTienda']) && isset($_POST['nombreTienda'])){
								$error = "Debes poner un nombre";
            }elseif(empty($_POST['municipio']) && isset($_POST['municipio'])){
                $error = "Debes poner un municipio";
            }elseif(empty($_POST['telefonoTienda']) && isset($_POST['telefonoTienda'])){
                $error = "Debes poner un teléfono";
            }elseif(empty($_POST['direccionTienda']) && isset($_POST['direccionTienda'])){
                $error = "Debes poner una dirección";
            }else{
								//estos son el resto de Datos
								$nombreTienda = $_POST['nombreTienda'];
								$municipio = (int)$_POST['municipio'];
								$telefonoTienda = $_POST['telefonoTienda'];
								$direccionTienda = $_POST['direccionTienda'];
								$idTienda = (int)$_POST['idTienda'];
								$activo=true;
								if(empty($_FILES['imagenTienda']['name']) && isset($_FILES['imagenTienda']['name'])){
										//insertamos la tiendas
										$boolInsertarTienda = (new TiendasRepositorio())->insertarTiendaModificadaSinFoto($nombreTienda,$municipio,$telefonoTienda
										,$direccionTienda,$idTienda,$activo);//devuelve un boolval
										if($boolInsertarTienda){
												$error = "Tienda insertada correctamente";
										}else{
												$error = "Ha habido un error y la tienda no ha sido insertada correctamente";
										}
								}else{
										//estos datos son de la imagen
										$subirFoto = null;
										$name = $_FILES['imagenTienda']['name'];//array(5) { ["name"]=> string(0) "" ["type"]=> string(0) "" ["tmp_name"]=> string(0) "" ["error"]=> int(4) ["size"]=> int(0) }
										$type= $_FILES['imagenTienda']['type'];
										$tmp_name = $_FILES['imagenTienda']['tmp_name'];
										$error = $_FILES['imagenTienda']['error'];
										$size = $_FILES['imagenTienda']['size'];

										//subimos la foto
										$subirFoto = (new TiendasRepositorio())->insertarImagenYsacarRutaImagen($name,$type,$tmp_name,$error,$size);//envia un array
										//insertamos la tiendas
										$boolInsertarTienda = (new TiendasRepositorio())->insertarTiendaModificada($subirFoto,$nombreTienda,$municipio,$telefonoTienda
										,$direccionTienda,$idTienda,$activo);//devuelve un boolval
										if($boolInsertarTienda){
												$error = "Tienda insertada correctamente";
										}else{
												$error = "Ha habido un error y la tienda no ha sido insertada correctamente";
										}
								}

            }
		}
		$idTienda = (int)$_POST['idTienda'];
		$nombreCiudad = (new TiendasRepositorio())->devolverCiudadTienda($idTienda);
		$tienda = (new TiendasRepositorio())->devolverTiendaIndividual($idTienda);
		include_once __DIR__ .'/../../app/plantillas/administrador/modificarTiendaAdministrador.php';
	}//fin metodo

	public function enviarDatosModificacionTiendaAdministrador(){
		if($_SERVER['REQUEST_METHOD'] == 'POST'){
            if(empty($_POST['nombreTienda']) && isset($_POST['nombreTienda'])){
                $error = "Debes poner un nombre";
            }elseif(empty($_POST['telefonoTienda']) && isset($_POST['telefonoTienda'])){
                $error = "Debes poner un teléfono";
            }elseif(empty($_POST['direccionTienda']) && isset($_POST['direccionTienda'])){
                $error = "Debes poner una dirección";
            }else{
								//estos son el resto de Datos
								$activo=true;
								$nombreTienda = $_POST['nombreTienda'];
								$telefonoTienda = $_POST['telefonoTienda'];
								$direccionTienda = $_POST['direccionTienda'];
								$idTienda = (int)$_SESSION['idTienda'];
								//si no se envia foto
								if(empty($_FILES['imagenTienda']['name']) && isset($_FILES['imagenTienda']['name'])){
										//insertamos la tienda sin foto
										$boolInsertarTienda = (new TiendasRepositorio())->insertarTiendaModificadaAdministradorSinFoto($nombreTienda,$telefonoTienda
										,$direccionTienda,$idTienda,$activo);//devuelve un boolval
										if($boolInsertarTienda){
												$error = "Tienda insertada correctamente";
										}else{
												$error = "Ha habido un error y la tienda no ha sido insertada correctamente";
										}
								}else{
										//estos datos son de la imagen
										$subirFoto = null;
										$name = $_FILES['imagenTienda']['name'];
										$type= $_FILES['imagenTienda']['type'];
										$tmp_name = $_FILES['imagenTienda']['tmp_name'];
										$error = $_FILES['imagenTienda']['error'];
										$size = $_FILES['imagenTienda']['size'];

										//subimos la foto
										$subirFoto = (new TiendasRepositorio())->insertarImagenYsacarRutaImagen($name,$type,$tmp_name,$error,$size);//envia un array
										//insertamos la tiendas
										$boolInsertarTienda = (new TiendasRepositorio())->insertarTiendaModificadaAdministrador($subirFoto,$nombreTienda,$telefonoTienda
										,$direccionTienda,$idTienda,$activo);//devuelve un boolval
										if($boolInsertarTienda){
												$error = "Tienda insertada correctamente";
										}else{
												$error = "Ha habido un error y la tienda no ha sido insertada correctamente";
										}
								}

            }
		}
		$idTienda = (int)$_SESSION['idTienda'];
		$miTienda = (new TiendasRepositorio())->devolverTiendaIndividual($idTienda);
		include_once __DIR__ .'/../../app/plantillas/administradorTienda/verMiTienda.php';
	}//fin metodo

	public function insertarNuevaTiendaAdministrador(){
		include_once __DIR__ .'/../../app/plantillas/administrador/insertarNuevaTiendaAdministrador.php';
	}//fin metodo

	public function enviarDatosInsercionTienda(){
        if($_SERVER['REQUEST_METHOD'] == 'POST'){
			if(empty($_POST['nombreTienda']) && isset($_POST['nombreTienda'])){
				$error = "Debes poner un nombre";
			}elseif(empty($_POST['municipio']) && isset($_POST['municipio'])){
				$error = "Debes poner un municipio";
			}elseif(empty($_POST['telefonoTienda']) && isset($_POST['telefonoTienda'])){
				$error = "Debes poner un teléfono";
			}elseif(empty($_POST['direccionTienda']) && isset($_POST['direccionTienda'])){
				$error = "Debes poner una dirección";
			}elseif(empty($_FILES['imagenTienda']['name']) && isset($_FILES['imagenTienda']['name'])){
				$error = "Debes poner una imagen de tienda. No puedes dejarla vacia";
			}elseif(!is_numeric($_POST['telefonoTienda'])){
				$error = "El teléfono debe ser un número";
			}else{
				//estos datos son de la imagen
				$subirFoto = null;
				$name = $_FILES['imagenTienda']['name'];
				$type= $_FILES['imagenTienda']['type'];
				$tmp_name = $_FILES['imagenTienda']['tmp_name'];
				$error = $_FILES['imagenTienda']['error'];
				$size = $_FILES['imagenTienda']['size'];
				//estos son el resto de Datos
				$nombreTienda = $_POST['nombreTienda'];
				$municipio = (int)$_POST['municipio'];
				$telefonoTienda = $_POST['telefonoTienda'];
				$direccionTienda = $_POST['direccionTienda'];
				$activo=false;
				//subimos la foto
				$subirFoto = (new TiendasRepositorio())->insertarImagenYsacarRutaImagen($name,$type,$tmp_name,$error,$size);//envia un array
				//insertamos la tiendas
				$tipo = $subirFoto['tipo'];//sacamos el tipo de foto
				if ( strpos($tipo, "gif") || strpos($tipo, "jpeg") || strpos($tipo, "jpg") || strpos($tipo, "png") || strpos($tipo, "bmp") ){
							$boolInsertarTienda = (new TiendasRepositorio())->insertarTienda($subirFoto,$nombreTienda,$municipio,$telefonoTienda,$direccionTienda,$activo);//devuelve un boolval
							if($boolInsertarTienda){
								//ahora rellenaremos el catálogo de esa tienda con todos los ejemplares iniciados a 0
								$idUltimaTiendaInsertada = (new TiendasRepositorio())->devolverUltimoIdTienda();
								$numeroEjemplares = (new TiendasRepositorio())->devolverNumerosEjemplaresActuales();
								$insertarCatalagoCeroTienda = (new TiendasRepositorio())->insertarCatalogoNuevaTienda($idUltimaTiendaInsertada,$numeroEjemplares);
								if($insertarCatalagoCeroTienda){
										$error = "Tienda insertada correctamente";
								}

							}else{
								$error = "Ha habido un error y la tienda no ha sido insertada correctamente";
							}
					}else{
							$error = "Debes elegir otro formato de foto como png o jpg";
					}

			}
        }
        $tiendaTotal = (new TiendasRepositorio())->devolverTiendasTotales();
        include_once __DIR__ .'/../../app/plantillas/administrador/administrarTiendas.php';
	}//fin metodo

	public function verVentasPorTiendaAdministrador(){
				$tiendaTotal = (new TiendasRepositorio())->devolverTiendasTotales();
				$arrayCiudadProvincias = (new TiendasRepositorio)->devolverArrayCiudadProvincias($tiendaTotal);
				include_once __DIR__ .'/../../app/plantillas/administrador/verVentasPorTiendaAdministrador.php';
	}//fin metodo


}//fin clase
?>
