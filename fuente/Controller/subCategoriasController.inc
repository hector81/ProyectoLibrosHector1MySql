<?php
include_once __DIR__ . "/../Repositorio/subCategoriasRepositorio.inc";
include_once __DIR__ . "/../Repositorio/categoriasRepositorio.inc";
class SubCategoriasController
{
	public function verSubcategorias_de_Categorias(){
		if($_SERVER['REQUEST_METHOD']=='POST'){
			if(!empty($_POST['IdCategoria']) && isset($_POST['IdCategoria'])){
				$subCategorias = (new SubCategoriasRepositorio)->devolverSubCategorias($_POST['IdCategoria']);//devuelve un array
			}
		}
		if($_SERVER['REQUEST_METHOD']=='GET'){
			if(!empty($_GET['IdCategoria']) && isset($_GET['IdCategoria'])){
				$subCategorias = (new SubCategoriasRepositorio)->devolverSubCategorias($_GET['IdCategoria']);//devuelve un array
			}
		}
		include_once __DIR__ .'/../../app/plantillas/visitante/verSubcategorias_de_Categorias.php';
	}//fin metodo

	//USUARIO
	public function verSubcategorias_de_CategoriasUsuario(){
		if($_SERVER['REQUEST_METHOD']=='POST'){
			if(!empty($_POST['IdCategoria']) && isset($_POST['IdCategoria'])){
				$subCategorias = (new SubCategoriasRepositorio)->devolverSubCategorias($_POST['IdCategoria']);//devuelve un array
			}
		}
		if($_SERVER['REQUEST_METHOD']=='GET'){
			if(!empty($_GET['IdCategoria']) && isset($_GET['IdCategoria'])){
				$subCategorias = (new SubCategoriasRepositorio)->devolverSubCategorias($_GET['IdCategoria']);//devuelve un array
			}
		}
		include_once __DIR__ .'/../../app/plantillas/usuario/verSubcategorias_de_CategoriasUsuario.php';
	}//fin metodo

	public function verSubcategorias_de_CategoriasAdministradorTienda(){
		if($_SERVER['REQUEST_METHOD']=='POST'){
			if(!empty($_POST['IdCategoria']) && isset($_POST['IdCategoria'])){
				$subCategorias = (new SubCategoriasRepositorio)->devolverSubCategorias($_POST['IdCategoria']);//devuelve un array
			}
		}
		if($_SERVER['REQUEST_METHOD']=='GET'){
			if(!empty($_GET['IdCategoria']) && isset($_GET['IdCategoria'])){
				$subCategorias = (new SubCategoriasRepositorio)->devolverSubCategorias($_GET['IdCategoria']);//devuelve un array
			}
		}
		include_once __DIR__ .'/../../app/plantillas/administradorTienda/verSubcategorias_de_CategoriasAdministradorTienda.php';
	}//fin metodo

	/////////////////ADMINISTRADOR
	public function verSubcategorias_de_CategoriasAdministrador(){
		if($_SERVER['REQUEST_METHOD']=='POST'){
			if(!empty($_POST['IdCategoria']) && isset($_POST['IdCategoria'])){
				$subCategorias = (new SubCategoriasRepositorio)->devolverSubCategorias($_POST['IdCategoria']);//devuelve un array
			}
		}
		if($_SERVER['REQUEST_METHOD']=='GET'){
			if(!empty($_GET['IdCategoria']) && isset($_GET['IdCategoria'])){
				$subCategorias = (new SubCategoriasRepositorio)->devolverSubCategorias($_GET['IdCategoria']);//devuelve un array
			}
		}
		include_once __DIR__ .'/../../app/plantillas/administrador/verSubcategorias_de_CategoriasAdministrador.php';
	}//fin metodo

	public function verSubCategoriasAdministrador(){
		$subCategorias = (new SubCategoriasRepositorio)->verSubCategoriasAdministrador();//devuelve un array
		$arrayNombresCategorias = (new SubCategoriasRepositorio)->devolverArrayNombresCategorias($subCategorias);//devuelve un array
		include_once __DIR__ .'/../../app/plantillas/administrador/verSubCategoriasAdministrador.php';
	}//fin metodo

	public function borrarSubCategoriaAdministrador(){
		$idSubCategoria = (int)$_GET['idSubCategoria'];
		$numeroLibrosSubCategoria = (new SubCategoriasRepositorio)->devolverNumeroLibrosSubCategoria($idSubCategoria);
		if($numeroLibrosSubCategoria  < 1){
				$borra = (new SubCategoriasRepositorio)->borrarSubCategoriaAdministrador($_GET['idSubCategoria']);
				$error = 'La subcategoria ha sido borrada';
		}else{
				$error = 'La subcategoria no ha sido borrada porque tiene libros dependientes';
		}

		$subCategorias = (new SubCategoriasRepositorio)->verSubCategoriasAdministrador();//devuelve un array
		$arrayNombresCategorias = (new SubCategoriasRepositorio)->devolverArrayNombresCategorias($subCategorias);//devuelve un array
		include_once __DIR__ .'/../../app/plantillas/administrador/verSubCategoriasAdministrador.php';
	}//fin metodo

	public function modificarSubCategoriaAdministrador(){
		$idSubCategoria = $_GET['idSubCategoria'];
		$subCategorias = (new SubCategoriasRepositorio)->devolverSubCategoriasPorId($idSubCategoria);
		$arrayNombresCategorias = (new SubCategoriasRepositorio)->devolverArrayNombresCategorias($subCategorias);//devuelve un array
		include_once __DIR__ .'/../../app/plantillas/administrador/modificarSubCategoriaAdministrador.php';
	}//fin metodo

	public function enviarDatosModificacionSubCategoria(){
		if($_SERVER['REQUEST_METHOD']=='POST'){
			if(empty($_POST['nombreSubCategoria']) && isset($_POST['nombreSubCategoria'])){
				$error = 'El campo nombre de subcategoria está vacio';
			}elseif(empty($_POST['descripcion']) && isset($_POST['descripcion'])){
				$error = 'El campo descripción está vacio';
			}else{
				$idSubCategoria = $_POST['idSubCategoria'];
				$nombreSubCategoria = $_POST['nombreSubCategoria'];
				$descripcion = $_POST['descripcion'];
				$boolSubCategoria = (new SubCategoriasRepositorio)->modificarSubCategoriaAdministradorId($idSubCategoria,$nombreSubCategoria,$descripcion);
				if($boolSubCategoria){
					$error = 'La subcategoria ha sido modificada correctamente';
				}else{
					$error = 'Ha habido algún problema y la subcategoria no ha sido modifcada';
				}
			}
		}
		$subCategorias = (new SubCategoriasRepositorio)->verSubCategoriasAdministrador();//devuelve un array
		$arrayNombresCategorias = (new SubCategoriasRepositorio)->devolverArrayNombresCategorias($subCategorias);//devuelve un array
		include_once __DIR__ .'/../../app/plantillas/administrador/verSubCategoriasAdministrador.php';
	}//fin metodo

	public function introducirSubCategoria(){
			$categorias = (new CategoriasRepositorio)->verCategoriasAdministrador();//devuelve un array
			include_once __DIR__ .'/../../app/plantillas/administrador/introducirSubCategoria.php';
	}//fin metodo

	public function enviarDatosInsercionSubCategoria(){
			if($_SERVER['REQUEST_METHOD']=='POST'){
				if(empty($_POST['nombreSubCategoria']) && isset($_POST['nombreSubCategoria'])){
					$error = 'El campo nombre de subcategoria está vacio';
				}elseif(empty($_POST['nombreAlias']) && isset($_POST['nombreAlias'])){
					$error = 'Debes poner un nombre de carpeta donde almacenaras imagenes';
				}elseif(empty($_POST['idCategoria']) && isset($_POST['idCategoria'])){
					$error = 'Debes seleccionar una categoría';
				}elseif(empty($_POST['descripcion']) && isset($_POST['descripcion'])){
					$error = 'El campo descripción está vacio';
				}else{
					$nombreSubCategoria = $_POST['nombreSubCategoria'];
					$nombreAlias = $_POST['nombreAlias'];
					$descripcion = $_POST['descripcion'];
					$idCategoria = (int)$_POST['idCategoria'];
					//comprobamos que no haya duplicados
					$comprobarDuplicadosNombresSubCategorias = (new SubCategoriasRepositorio)->comprobarDuplicadosNombresSubCategorias($nombreSubCategoria,$nombreAlias);
					if(!$comprobarDuplicadosNombresSubCategorias){
							$error = 'El nombre o el nombre de carpeta ya existen';
					}else{
							$boolSubCategoria = (new SubCategoriasRepositorio)->introducirSubCategoriaAdministrador($nombreSubCategoria,$nombreAlias,$descripcion,$idCategoria);
							if($boolSubCategoria){
								//si la subcategoria ha sido creada correctamente creamos la carpeta
								$categoria = (new CategoriasRepositorio)->devolverCategoriasPorId($idCategoria);
								$boolCarpeta = (new SubCategoriasRepositorio)->crearCarpetaSubCategoria($nombreAlias,$categoria);
								if($boolCarpeta){
										$error = 'La subcategoria ha sido creada correctamente';
								}
							}else{
								$error = 'Ha habido algún problema y la subcategoria no ha sido modifcada';
							}
					}

				}
			}
			$categorias = (new CategoriasRepositorio)->verCategoriasAdministrador();//devuelve un array
			include_once __DIR__ .'/../../app/plantillas/administrador/introducirSubCategoria.php';
	}//fin metodo

}//fin clase
?>
