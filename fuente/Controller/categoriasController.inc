<?php
include_once __DIR__ . "/../Repositorio/categoriasRepositorio.inc";
class CategoriasController
{
	public function librosPorCategoria(){
		$categorias = (new CategoriasRepositorio)->devolverCategorias();//devuelve un array
		include_once __DIR__ .'/../../app/plantillas/visitante/librosPorCategoria.php';
	}//fin metodo

	public function librosPorCategoriaUsuario(){
		$categorias = (new CategoriasRepositorio)->devolverCategorias();//devuelve un array
		include_once __DIR__ .'/../../app/plantillas/usuario/librosPorCategoriaUsuario.php';
	}//fin metodo

	public function librosPorCategoriaSuperAdministrador(){
		$categorias = (new CategoriasRepositorio)->devolverCategorias();//devuelve un array
		include_once __DIR__ .'/../../app/plantillas/administrador/librosPorCategoriaSuperAdministrador.php';
	}//fin metodo

	public function verCategoriasAdministrador(){
		$categorias = (new CategoriasRepositorio)->verCategoriasAdministrador();//devuelve un array
		include_once __DIR__ .'/../../app/plantillas/administrador/verCategoriasAdministrador.php';
	}//fin metodo

	public function verCategoriasAdministradorTienda(){
		$categorias = (new CategoriasRepositorio)->devolverCategorias();//devuelve un array
		include_once __DIR__ .'/../../app/plantillas/administradorTienda/verCategoriasAdministradorTienda.php';
	}//fin metodo

	public function borrarCategoriaAdministrador(){
		$idCategoria = (int)$_GET['idCategoria'];
		$numeroLibrosCategoria = (new CategoriasRepositorio)->devolverNumeroLibrosCategoria($idCategoria);
		if($numeroLibrosCategoria  < 1){
				$borra = (new CategoriasRepositorio)->borrarCategoriaAdministrador($_GET['idCategoria']);
				$error = 'La categoria ha sido borrada';
		}else{
				$error = 'La categoria no ha sido borrada porque tiene libros dependientes';
		}

		$categorias = (new CategoriasRepositorio)->verCategoriasAdministrador();//devuelve un array
		include_once __DIR__ .'/../../app/plantillas/administrador/verCategoriasAdministrador.php';
	}//fin metodo

	public function modificarCategoriaAdministrador(){
		$idCategoria = $_GET['idCategoria'];
		$categoria = (new CategoriasRepositorio)->devolverCategoriasPorId($idCategoria);
		include_once __DIR__ .'/../../app/plantillas/administrador/modificarCategoriaAdministrador.php';
	}//fin metodo

	public function enviarDatosModificacionCategoria(){
		if($_SERVER['REQUEST_METHOD']=='POST'){
			if(empty($_POST['nombreCategoria']) && isset($_POST['nombreCategoria'])){
				$error = 'El campo nombre de categoria está vacio';
			}elseif(empty($_POST['descripcion']) && isset($_POST['descripcion'])){
				$error = 'El campo descripción está vacio';
			}else{
				$idCategoria = $_POST['idCategoria'];
				$nombreCategoria = $_POST['nombreCategoria'];
				$descripcion = $_POST['descripcion'];
				$boolCategoria = (new CategoriasRepositorio)->modificarCategoriaAdministradorId($idCategoria,$nombreCategoria,$descripcion);
				if($boolCategoria){
					$error = 'La categoria ha sido modificada correctamente';
				}else{
					$error = 'Ha habido algún problema y la categoria no ha sido modifcada';
				}
			}
		}
		$categorias = (new CategoriasRepositorio)->verCategoriasAdministrador();//devuelve un array
		include_once __DIR__ .'/../../app/plantillas/administrador/verCategoriasAdministrador.php';
	}//fin metodo

	public function introducirCategoria(){
			include_once __DIR__ .'/../../app/plantillas/administrador/introducirCategoria.php';
	}//fin metodo

	public function enviarDatosInsercionCategoria(){
		if($_SERVER['REQUEST_METHOD']=='POST'){
			if(empty($_POST['nombreCategoria']) && isset($_POST['nombreCategoria'])){
				$error = 'El campo nombre de categoria está vacio';
			}elseif(empty($_POST['nombreAlias']) && isset($_POST['nombreAlias'])){
				$error = 'Debes poner un nombre de carpeta donde almacenaras imagenes';
			}elseif(empty($_POST['descripcion']) && isset($_POST['descripcion'])){
				$error = 'El campo descripción está vacio';
			}else{
				$nombreCategoria = $_POST['nombreCategoria'];
				$nombreAlias = $_POST['nombreAlias'];
				$descripcion = $_POST['descripcion'];
				//comprobamos que no haya duplicados
				$comprobarDuplicadosNombresCategorias = (new CategoriasRepositorio)->comprobarDuplicadosNombresCategorias($nombreCategoria,$nombreAlias);
				if(!$comprobarDuplicadosNombresCategorias){
						$error = 'El nombre o el nombre de carpeta ya existen';
				}else{
						$boolCategoria = (new CategoriasRepositorio)->introducirCategoriaAdministrador($nombreCategoria,$nombreAlias,$descripcion);
						if($boolCategoria){
							//si la categoria ha sido creada correctamente creamos la carpeta
							$boolCarpeta = (new CategoriasRepositorio)->crearCarpetaCategoria($nombreAlias);
							if($boolCarpeta){
									$error = 'La categoria ha sido modificada correctamente';
							}
						}else{
							$error = 'Ha habido algún problema y la categoria no ha sido modifcada';
						}
				}
			}
		}
		$categorias = (new CategoriasRepositorio)->verCategoriasAdministrador();//devuelve un array
		include_once __DIR__ .'/../../app/plantillas/administrador/introducirCategoria.php';
	}//fin metodo

}//fin clase
?>
