<?php
include_once __DIR__ . "/../Repositorio/librosRepositorio.inc";
include_once __DIR__ . "/../Repositorio/tiendasRepositorio.inc";
include_once __DIR__ . "/../Repositorio/autoresRepositorio.inc";
include_once __DIR__ . "/../Repositorio/editorialesRepositorio.inc";
include_once __DIR__ . "/../Repositorio/paisesRepositorio.inc";
include_once __DIR__ . "/../Repositorio/ejemplaresRepositorio.inc";
class LibrosController
{
    public function librosPaginaPrincipal(){
        $librosPaginaPrincipal = (new LibrosRepositorio)->mostrarlibrosPaginaPrincipal();//es un multarray de 2
        $params = [
            'mensaje' => 'Bienvenido a la página de la gestión de libros',
            'dia' => date('Y-m-d'),
            'hora' => date('H:i:s')
        ];
        include_once __DIR__ .'/../../app/plantillas/visitante/inicio.php';
    }//fin metodo

    public function librosPaginaPrincipalUsuario(){
        $librosPaginaPrincipal = (new LibrosRepositorio)->mostrarlibrosPaginaPrincipal();//es un multarray de 2
        $params = [
            'mensaje' => 'Bienvenido a la página de la gestión de libros',
            'dia' => date('Y-m-d'),
            'hora' => date('H:i:s')
        ];
        include_once __DIR__ .'/../../app/plantillas/usuario/inicioUsuario.php';
    }//fin metodo

    public function librosPaginaPrincipalAdministradorTienda(){
        $librosPaginaPrincipal = (new LibrosRepositorio)->mostrarlibrosPaginaPrincipal();//es un multarray de 2
        $params = [
            'mensaje' => 'Bienvenido a la página de la gestión de libros',
            'dia' => date('Y-m-d'),
            'hora' => date('H:i:s')
        ];
        include_once __DIR__ .'/../../app/plantillas/administradorTienda/inicioAdministradorTienda.php';
    }//fin metodo

    public function librosPaginaPrincipalAdministrador(){
        $librosPaginaPrincipal = (new LibrosRepositorio)->mostrarlibrosPaginaPrincipal();//es un multarray de 2
        $params = [
            'mensaje' => 'Bienvenido a la página de la gestión de libros',
            'dia' => date('Y-m-d'),
            'hora' => date('H:i:s')
        ];
        include_once __DIR__ .'/../../app/plantillas/administrador/inicioAdministrador.php';
    }//fin metodo

    public function busquedaVisitante(){
		if($_SERVER['REQUEST_METHOD']=='POST'){
            if(!empty($_POST['palabraBusqueda']) && isset($_POST['palabraBusqueda'])){
                $palabra = $_POST['palabraBusqueda'];
                $libros = (new LibrosRepositorio)->resultadosBusqueda($palabra);
            }
		}
		include_once __DIR__ .'/../../app/plantillas/visitante/busquedaVisitante.php';
	} //fin metodo

	public function busquedaSuperAdministrador(){
		if($_SERVER['REQUEST_METHOD']=='POST'){
			if(!empty($_POST['palabraBusqueda']) && isset($_POST['palabraBusqueda'])){
				$palabra = $_POST['palabraBusqueda'];
				$libros = (new LibrosRepositorio)->resultadosBusqueda($palabra);
			}
		}
		include_once __DIR__ .'/../../app/plantillas/administrador/busquedaSuperAdministrador.php';
	} //fin metodo


  public function busquedaTiendaAdministrador(){
		if($_SERVER['REQUEST_METHOD']=='POST'){
			if(!empty($_POST['palabraBusqueda']) && isset($_POST['palabraBusqueda'])){
				$palabra = $_POST['palabraBusqueda'];
				$libros = (new LibrosRepositorio)->resultadosBusqueda($palabra);
			}
		}
		include_once __DIR__ .'/../../app/plantillas/administradorTienda/busquedaTiendaAdministrador.php';
	} //fin metodo

	public function busquedaUsuarioRegistrado(){
		if($_SERVER['REQUEST_METHOD']=='POST'){
			if(!empty($_POST['palabraBusqueda']) && isset($_POST['palabraBusqueda'])){
				$palabra = $_POST['palabraBusqueda'];
				$libros = (new LibrosRepositorio)->resultadosBusqueda($palabra);
			}
		}
		include_once __DIR__ .'/../../app/plantillas/usuario/busquedaUsuarioRegistrado.php';
	} //fin metodo

    public function verLibrosIndividual(){
		if($_SERVER['REQUEST_METHOD']=='POST'){
			$nombreCategoria = $_POST['nombreCategoria'];
			$idCategoria = (new LibrosRepositorio)->devolverIdCategoria($nombreCategoria);
			$libroIndividual = (new LibrosRepositorio)->verLibrosIndividual($_POST['idLibro']);
			include_once __DIR__ . "/../../app/plantillas/visitante/verLibrosIndividual.php";
		}
		if($_SERVER['REQUEST_METHOD']=='GET'){
			$nombreCategoria = $_GET['nombreCategoria'];
			$idCategoria = (new LibrosRepositorio)->devolverIdCategoria($nombreCategoria);
			$libroIndividual = (new LibrosRepositorio)->verLibrosIndividual($_GET['idLibro']);
			include_once __DIR__ . "/../../app/plantillas/visitante/verLibrosIndividual.php";
		}
	}//fin metodo

	public function verLibrosPorSubCategoria(){
		if($_SERVER['REQUEST_METHOD']=='POST'){
			if(!empty($_POST['IdSubCategoria']) && isset($_POST['IdSubCategoria'])){
				$libros = (new LibrosRepositorio)->verLibrosPorSubCategoria($_POST['IdSubCategoria']);//devuelve un array
				$nombreSubCategoria = $libros[0]['NombreSubCategoria'];
			}
		}
		if($_SERVER['REQUEST_METHOD']=='GET'){
			if(!empty($_GET['IdSubCategoria']) && isset($_GET['IdSubCategoria'])){
				$libros = (new LibrosRepositorio)->verLibrosPorSubCategoria($_GET['IdSubCategoria']);//devuelve un array
				$nombreSubCategoria = $libros[0]['NombreSubCategoria'];
			}
		}
		include_once __DIR__ .'/../../app/plantillas/visitante/verLibrosPorSubCategoria.php';
	}//fin metodo

	public function verLibrosIndividualUsuario(){
		if($_SERVER['REQUEST_METHOD']=='POST'){
            $idLibro = (int)$_POST['idLibro'];
            $tiendas = (new TiendasRepositorio)->devolverTiendasTotales();
            $nombreCategoria = $_POST['nombreCategoria'];
            $idCategoria = (new LibrosRepositorio)->devolverIdCategoria($nombreCategoria);
            $libroIndividual = (new LibrosRepositorio)->verLibrosIndividual($idLibro);
            $existenciasLibroPorTienda =(new TiendasRepositorio)->devolverExistenciasLibroPorTienda($tiendas,$idLibro);
            include_once __DIR__ . "/../../app/plantillas/usuario/verLibrosIndividualUsuario.php";
		}
		if($_SERVER['REQUEST_METHOD']=='GET'){
            $idLibro = (int)$_GET['idLibro'];
            $tiendas = (new TiendasRepositorio)->devolverTiendasTotales();
            $nombreCategoria = $_GET['nombreCategoria'];
            $idCategoria = (new LibrosRepositorio)->devolverIdCategoria($nombreCategoria);
            $libroIndividual = (new LibrosRepositorio)->verLibrosIndividual($idLibro);
            $existenciasLibroPorTienda =(new TiendasRepositorio)->devolverExistenciasLibroPorTienda($tiendas,$idLibro);
            include_once __DIR__ . "/../../app/plantillas/usuario/verLibrosIndividualUsuario.php";
		}
	}//fin metodo

	public function verLibrosPorSubCategoriaUsuario(){
		if($_SERVER['REQUEST_METHOD']=='POST'){
			if(!empty($_POST['IdSubCategoria']) && isset($_POST['IdSubCategoria'])){
				$libros = (new LibrosRepositorio)->verLibrosPorSubCategoria($_POST['IdSubCategoria']);//devuelve un array
				$nombreSubCategoria = $libros[0]['NombreSubCategoria'];
			}
		}
		if($_SERVER['REQUEST_METHOD']=='GET'){
			if(!empty($_GET['IdSubCategoria']) && isset($_GET['IdSubCategoria'])){
				$libros = (new LibrosRepositorio)->verLibrosPorSubCategoria($_GET['IdSubCategoria']);//devuelve un array
				$nombreSubCategoria = $libros[0]['NombreSubCategoria'];
			}
		}
		include_once __DIR__ .'/../../app/plantillas/usuario/verLibrosPorSubCategoriaUsuario.php';
	}//fin metodo


	public function verLibrosPorSubCategoriaAdministradorTienda(){
    $idTienda = (int)$_SESSION['idTienda'];
		if($_SERVER['REQUEST_METHOD']=='POST'){
			if(!empty($_POST['IdSubCategoria']) && isset($_POST['IdSubCategoria'])){
				$libros = (new LibrosRepositorio)->verLibrosPorSubCategoriaIdTienda($_POST['IdSubCategoria'],$idTienda);//devuelve un array
				$nombreSubCategoria = $libros[0]['NombreSubCategoria'];
			}
		}
		if($_SERVER['REQUEST_METHOD']=='GET'){
			if(!empty($_GET['IdSubCategoria']) && isset($_GET['IdSubCategoria'])){
				$libros = (new LibrosRepositorio)->verLibrosPorSubCategoriaIdTienda($_GET['IdSubCategoria'],$idTienda);//devuelve un array
				$nombreSubCategoria = $libros[0]['NombreSubCategoria'];
			}
		}
		include_once __DIR__ .'/../../app/plantillas/administradorTienda/verLibrosPorSubCategoriaAdministradorTienda.php';
	}//fin metodo

	public function verLibrosIndividualAdministrador(){
		if($_SERVER['REQUEST_METHOD']=='POST'){
            $nombreCategoria = $_POST['nombreCategoria'];
            $idCategoria = (new LibrosRepositorio)->devolverIdCategoria($nombreCategoria);
            $libroIndividual = (new LibrosRepositorio)->verLibrosIndividual($_POST['idLibro']);
            include_once __DIR__ . "/../../app/plantillas/administrador/verLibrosIndividualAdministrador.php";
		}
		if($_SERVER['REQUEST_METHOD']=='GET'){
            $nombreCategoria = $_GET['nombreCategoria'];
            $idCategoria = (new LibrosRepositorio)->devolverIdCategoria($nombreCategoria);
            $libroIndividual = (new LibrosRepositorio)->verLibrosIndividual($_GET['idLibro']);
            include_once __DIR__ . "/../../app/plantillas/administrador/verLibrosIndividualAdministrador.php";
		}
	}//fin metodo

  public function verLibrosIndividualAdministradorTienda(){
		if($_SERVER['REQUEST_METHOD']=='POST'){
            $nombreCategoria = $_POST['nombreCategoria'];
            $idCategoria = (new LibrosRepositorio)->devolverIdCategoria($nombreCategoria);
            $libroIndividual = (new LibrosRepositorio)->verLibrosIndividual($_POST['idLibro']);
            include_once __DIR__ . "/../../app/plantillas/administradorTienda/verLibrosIndividualAdministradorTienda.php";
		}
		if($_SERVER['REQUEST_METHOD']=='GET'){
            $nombreCategoria = $_GET['nombreCategoria'];
            $idCategoria = (new LibrosRepositorio)->devolverIdCategoria($nombreCategoria);
            $libroIndividual = (new LibrosRepositorio)->verLibrosIndividual($_GET['idLibro']);
            include_once __DIR__ . "/../../app/plantillas/administradorTienda/verLibrosIndividualAdministradorTienda.php";
		}
	}//fin metodo

  public function borrarLibroAdministrador(){
      if($_SERVER['REQUEST_METHOD']=='GET'){
          $idLibro = (int)$_GET['idLibro'];
          $nombreCategoria = $_GET['nombreCategoria'];
          $idCategoria = (new LibrosRepositorio)->devolverIdCategoria($nombreCategoria);
          $libroIndividual = (new LibrosRepositorio)->verLibrosIndividual($idLibro);
          //comprobamos el numero de ventas asociadas a este libro
          $numeroVentasAsociadasLibro = (new LibrosRepositorio)->devolverNumeroVentasAsociadasLibro($idLibro);
          $numeroReservasAsociadasLibro = (new LibrosRepositorio)->devolverNumeroReservasAsociadasLibro($idLibro);
          if($numeroVentasAsociadasLibro > 0){
                $error = 'Hay una venta asociada a este libro y no puede ser borrado';
          }elseif($numeroReservasAsociadasLibro > 0){
                $error = 'Hay una reserva asociada a este libro y no puede ser borrado';
          }else{
              $boolBorrarLibro = (new LibrosRepositorio)->borrarLibro($idLibro);
              if($boolBorrarLibro){
                  $error = 'El libro ha sido borrado';
              }else{
                  $error = 'El libro no ha sido borrado por algún problema técnico';
              }
          }
      }
      $libros = (new LibrosRepositorio)->verLibrosPorSubCategoria($_GET['idSubCategoria']);//devuelve un array
      $nombreSubCategoria = $libros[0]['NombreSubCategoria'];
      include_once __DIR__ . "/../../app/plantillas/administrador/verLibrosPorSubCategoriaAdministrador.php";
  }//fin metodo



	public function verLibrosPorSubCategoriaAdministrador(){
		if($_SERVER['REQUEST_METHOD']=='POST'){
			if(!empty($_POST['IdSubCategoria']) && isset($_POST['IdSubCategoria'])){
				$libros = (new LibrosRepositorio)->verLibrosPorSubCategoria($_POST['IdSubCategoria']);//devuelve un array
				$nombreSubCategoria = $libros[0]['NombreSubCategoria'];
			}
		}
		if($_SERVER['REQUEST_METHOD']=='GET'){
			if(!empty($_GET['IdSubCategoria']) && isset($_GET['IdSubCategoria'])){
				$libros = (new LibrosRepositorio)->verLibrosPorSubCategoria($_GET['IdSubCategoria']);//devuelve un array
				$nombreSubCategoria = $libros[0]['NombreSubCategoria'];
			}
		}
		include_once __DIR__ .'/../../app/plantillas/administrador/verLibrosPorSubCategoriaAdministrador.php';
	}//fin metodo

	//para busquedas
	public function busqueda(){
		$autores = (new AutoresRepositorio)->devolverAutoresTotales();
		$tiendas = (new TiendasRepositorio)->devolverTiendasTotales();
		$editoriales = (new EditorialesRepositorio)->devolverEditorialesTotales();
		$year = (new LibrosRepositorio)->devolverYearLibros();
		include_once __DIR__ .'/../../app/plantillas/usuario/busqueda.php';
	}//fin metodo

  //para busquedas de visitantes
  public function busquedaAvanzada(){
    $autores = (new AutoresRepositorio)->devolverAutoresTotales();
		$tiendas = (new TiendasRepositorio)->devolverTiendasTotales();
		$editoriales = (new EditorialesRepositorio)->devolverEditorialesTotales();
		$year = (new LibrosRepositorio)->devolverYearLibros();
		include_once __DIR__ .'/../../app/plantillas/visitante/busquedaAvanzada.php';
  }

  public function modificarLibrosAdministrador(){
      if($_SERVER['REQUEST_METHOD']=='GET'){
        $libroIndividual = (new LibrosRepositorio)->verLibrosIndividual($_GET['idLibro']);
      }
      include_once __DIR__ .'/../../app/plantillas/administrador/modificarLibrosAdministrador.php';
  }//fin metodo


	//para enseñar los resultados de la busqueda
	public function resultadosBusqueda(){
		$autores = (new AutoresRepositorio)->devolverAutoresTotales();
		$tiendas = (new TiendasRepositorio)->devolverTiendasTotales();
		$editoriales = (new EditorialesRepositorio)->devolverEditorialesTotales();
		$year = (new LibrosRepositorio)->devolverYearLibros();
		if($_SERVER['REQUEST_METHOD']=='POST'){
			if( (empty($_POST['autoresId']) && isset($_POST['autoresId'])) &&
				(empty($_POST['editorialId']) && isset($_POST['editorialId'])) &&
				(empty($_POST['tiendasId']) && isset($_POST['tiendasId'])) &&
				(empty($_POST['yearPublicacion']) && isset($_POST['yearPublicacion'])) &&
        (empty($_POST['categoria']) && isset($_POST['categoria'])) &&
        (empty($_POST['subcategoria']) && isset($_POST['subcategoria'])) &&
        (empty($_POST['titulo']) && isset($_POST['titulo']))
        ) {
					$error = 'No hay resultados en la busqueda';include_once __DIR__ .'/../../app/plantillas/usuario/busqueda.php';
			}else{
				$autoresId = (int)$_POST['autoresId'];
				$editorialId = (int)$_POST['editorialId'];
				$tiendasId = (int)$_POST['tiendasId'];
				$yearPublicacion = $_POST['yearPublicacion'];
        $idcategoria = (int)$_POST['categoria'];
        $idsubcategoria = (int)$_POST['subcategoria'];
        $titulo = $_POST['titulo'];

        $resultadosBusqueda = (new LibrosRepositorio)->busquedaAvanzada($autoresId,$editorialId,$tiendasId,$yearPublicacion,$idcategoria,$idsubcategoria,$titulo);
				include_once __DIR__ .'/../../app/plantillas/usuario/resultadosBusquedaAvanzadaUsuario.php';
			}
		}
	}//fin metodo

  //para enseñar los resultados de la busqueda
  public function resultadosBusquedaVisitante(){
    $autores = (new AutoresRepositorio)->devolverAutoresTotales();
    $tiendas = (new TiendasRepositorio)->devolverTiendasTotales();
    $editoriales = (new EditorialesRepositorio)->devolverEditorialesTotales();
    $year = (new LibrosRepositorio)->devolverYearLibros();
    if($_SERVER['REQUEST_METHOD']=='POST'){
      if( (empty($_POST['autoresId']) && isset($_POST['autoresId'])) &&
        (empty($_POST['editorialId']) && isset($_POST['editorialId'])) &&
        (empty($_POST['tiendasId']) && isset($_POST['tiendasId'])) &&
        (empty($_POST['yearPublicacion']) && isset($_POST['yearPublicacion'])) &&
        (empty($_POST['categoria']) && isset($_POST['categoria'])) &&
        (empty($_POST['subcategoria']) && isset($_POST['subcategoria'])) &&
        (empty($_POST['titulo']) && isset($_POST['titulo']))
        ) {
          $error = 'No hay resultados en la busqueda';include_once __DIR__ .'/../../app/plantillas/usuario/busqueda.php';
      }else{
        $autoresId = (int)$_POST['autoresId'];
        $editorialId = (int)$_POST['editorialId'];
        $tiendasId = (int)$_POST['tiendasId'];
        $yearPublicacion = $_POST['yearPublicacion'];
        $idcategoria = (int)$_POST['categoria'];
        $idsubcategoria = (int)$_POST['subcategoria'];
        $titulo = $_POST['titulo'];

        $resultadosBusqueda = (new LibrosRepositorio)->busquedaAvanzada($autoresId,$editorialId,$tiendasId,$yearPublicacion,$idcategoria,$idsubcategoria,$titulo);
        include_once __DIR__ .'/../../app/plantillas/visitante/resultadosBusquedaAvanzada.php';
      }
    }
  }//fin metodo

  public function enviarDatosModificacionLibro(){
      if($_SERVER['REQUEST_METHOD'] == 'POST'){
              if(empty($_POST['PVP']) && isset($_POST['PVP'])){
                  $error = "Debes poner un precio";
              }elseif(empty($_POST['descripcion']) && isset($_POST['descripcion'])){
                  $error = "Debes poner una descripción";
              }else{
                  //estos son el resto de Datos
                  $activo=true;
                  $PVP = (float)$_POST['PVP'];
                  $descripcion = $_POST['descripcion'];
                  $idEjemplar = (int)$_POST['idEjemplar'];
                  $idLibro = (int)$_POST['idLibro'];
                  $idCategoria = (int)$_POST['idCategoria'];
                  $idSubCategoria = (int)$_POST['idSubCategoria'];
                  //sacamos la catgoria y $subCategoria para luego ingresar las fotos en su carpeta correspondiente de categorias
                  include_once __DIR__ . "/../Repositorio/categoriasRepositorio.inc";
                  $categoria = (new CategoriasRepositorio)->devolverCategoriasPorId($idCategoria);
                  include_once __DIR__ . "/../Repositorio/subCategoriasRepositorio.inc";
                  $subCategorias = (new SubCategoriasRepositorio)->devolverSubCategoriasPorId($idSubCategoria);
                  if(empty($_FILES['portada']['name']) && isset($_FILES['portada']['name'])){
                      //modificarLibroAdministradorSinFoto
                      $boolmodificadoLibro = (new LibrosRepositorio())->modificarLibroAdministradorSinFoto($PVP,$idEjemplar,$idLibro,$categoria,$subCategorias);

                      if($boolmodificadoLibro){
                          $error = "Libro modificado correctamente";
                      }else{
                          $error = "Ha habido un error y el libro no ha sido modificado correctamente";
                      }
                  }else{
                        //estos datos son de la imagen
                        $subirFoto = null;
                        $name = $_FILES['portada']['name'];
                        $type= $_FILES['portada']['type'];
                        $tmp_name = $_FILES['portada']['tmp_name'];
                        $error = $_FILES['portada']['error'];
                        $size = $_FILES['portada']['size'];


                        //$rutaCarpetaLibro = (new LibrosRepositorio())->devolverRutaCarpetaLibrosCategoriasSub($idCategoria,$idSubCategoria);
                        //subimos la foto
                        $subirFoto = (new LibrosRepositorio())->insertarImagenYsacarRutaImagenLibro($name,$type,$tmp_name,$error,$size,$categoria,$subCategorias);//envia un array
                        //modificamos el libro
                        $boolmodificadoLibro = (new LibrosRepositorio())->modificarLibroAdministrador($subirFoto,$PVP,$idEjemplar,$idLibro,$categoria,$subCategorias);

                        if($boolmodificadoLibro){
                            $error = "Libro modificado correctamente";
                        }else{
                            $error = "Ha habido un error y el libro no ha sido modificado correctamente";
                        }
                  }

              }
      }
      $libroIndividual = (new LibrosRepositorio)->verLibrosIndividual($_POST['idLibro']);
      include_once __DIR__ .'/../../app/plantillas/administrador/modificarLibrosAdministrador.php';
  }//fin metodo

  public function introducirLibros(){
    include_once __DIR__ . "/../Repositorio/autoresRepositorio.inc";
    include_once __DIR__ . "/../Repositorio/editorialesRepositorio.inc";
    $autores = (new AutoresRepositorio())->devolverAutoresTotales();
    $editoriales = (new EditorialesRepositorio)->devolverEditorialesTotales();
    include_once __DIR__ .'/../../app/plantillas/administrador/introducirLibros.php';
  }//fin metodo

  public function enviarDatosIntroduccionIntroducciónLibros(){
      if($_SERVER['REQUEST_METHOD'] == 'POST'){
              if(empty($_POST['categoria']) && isset($_POST['categoria'])){
                  $error = "Debes poner una categoria";
              }elseif(empty($_POST['subcategoria']) && isset($_POST['subcategoria'])){
                  $error = "Debes poner una subcategoria";
              }elseif(empty($_FILES['portada']['name']) && isset($_FILES['portada']['name'])){
                  $error = "Debes poner una portada. No puedes dejarla vacia";
              }elseif(empty($_POST['titulo']) && isset($_POST['titulo'])){
                  $error = "Debes poner un título";
              }elseif(empty($_POST['nombreAutor']) && isset($_POST['nombreAutor'])){
                  $error = "Debes poner un nombre de autor";
              }elseif(empty($_POST['tipoEncuadernacion']) && isset($_POST['tipoEncuadernacion'])){
                  $error = "Debes poner un tipo de encuadernacion";
              }elseif(empty($_POST['numeroEdicion']) && isset($_POST['numeroEdicion'])){
                  $error = "Debes poner un numero de edicion";
              }elseif(empty($_POST['yearPublicacion']) && isset($_POST['yearPublicacion'])){
                  $error = "Debes poner el año de publicación";
              }elseif(empty($_POST['formato']) && isset($_POST['formato'])){
                  $error = "Debes poner un formato";
              }elseif(empty($_POST['idEditorial']) && isset($_POST['idEditorial'])){
                  $error = "Debes poner una editorial";
              }elseif(empty($_POST['idioma']) && isset($_POST['idioma'])){
                  $error = "Debes poner un idioma";
              }elseif(empty($_POST['isbn']) && isset($_POST['isbn'])){
                  $error = "Debes poner un isbn";
              }elseif(empty($_POST['isbn']) && isset($_POST['isbn'])){
                  $error = "Debes poner un isbn";
              }elseif(empty($_POST['PVP']) && isset($_POST['PVP'])){
                  $error = "Debes poner un precio";
              }elseif(empty($_POST['paginas']) && isset($_POST['paginas'])){
                  $error = "Debes poner las páginas";
              }elseif(empty($_POST['descripcion']) && isset($_POST['descripcion'])){
                  $error = "Debes poner la descripción";
              }elseif(strlen($_POST['yearPublicacion']) != 4){
                  $error = "El año deben ser 4 cifras";
              }else{
                  $boolInsertarEjemplares = (new EjemplaresRepositorio())->comprobarISBNrepetido($_POST['isbn']);
                  if($boolInsertarEjemplares){
                        $idCategoria = (int)$_POST['categoria'];
                        $idSubcategoria = (int)$_POST['subcategoria'];
                        $idAutor = (int)$_POST['nombreAutor'];
                        $tipoEncuadernacion = $_POST['tipoEncuadernacion'];
                        $numeroEdicion = (int)$_POST['numeroEdicion'];
                        $yearPublicacion = $_POST['yearPublicacion'];
                        $titulo = $_POST['titulo'];
                        $formato = $_POST['formato'];
                        $idEditorial = (int)$_POST['idEditorial'];
                        $idioma = $_POST['idioma'];
                        $isbn = $_POST['isbn'];
                        $PVP = (float)$_POST['PVP'];
                        $subirFoto = null;
                        $name = $_FILES['portada']['name'];
                        $type= $_FILES['portada']['type'];
                        $tmp_name = $_FILES['portada']['tmp_name'];
                        $error = $_FILES['portada']['error'];
                        $size = $_FILES['portada']['size'];
                        $descripcion = $_POST['descripcion'];
                        $fechaDisponibilidad = $_POST['fechaDisponibilidad'];
                        $paginas = (int)$_POST['paginas'];
                        //sacamos la catgoria y $subCategoria para luego ingresar las fotos en su carpeta correspondiente de categorias
                        include_once __DIR__ . "/../Repositorio/categoriasRepositorio.inc";
                        $categoria = (new CategoriasRepositorio)->devolverCategoriasPorId($idCategoria);
                        include_once __DIR__ . "/../Repositorio/subCategoriasRepositorio.inc";
                        $subCategorias = (new SubCategoriasRepositorio)->devolverSubCategoriasPorId($idSubcategoria);
                        //primero hayy que ingresar el libro y luego el ejemplar
                        $boolInsertarLibros = (new LibrosRepositorio())->insertarLibro($idSubcategoria,$titulo,$idAutor,$descripcion);
                        if($boolInsertarLibros){
                            $ultimoIdLibroInsertado = (new LibrosRepositorio())->sacarUltimoIdLibro();
                            //subimos la foto
                            $subirFoto = (new LibrosRepositorio())->insertarImagenYsacarRutaImagenLibro($name,$type,$tmp_name,$error,$size,
                                $categoria,$subCategorias);//envia un array
                            $boolInsertarEjemplares = (new EjemplaresRepositorio())->insertarEjemplares($numeroEdicion,$tipoEncuadernacion,
                                $fechaDisponibilidad,$yearPublicacion,$formato,$idEditorial,$idioma,$isbn,$paginas,$PVP,$subirFoto,
                                $ultimoIdLibroInsertado,$categoria,$subCategorias);
                            if($boolInsertarEjemplares){
                                //AHORA HAY QUE INSERTAR ESTE LIBRO EN TODAS LAS TIENDAS CON STOCK CERO
                                //NECESITO TODAS LAS TIENDAS Y NECESITO EL ULTIMO ID DEL EJEMPLAR INTRODUCIDO
                                $tiendaTotal = (new TiendasRepositorio())->devolverTiendasTotales();
                                $ultimoIdEjemplarInsertado = (new LibrosRepositorio())->sacarUltimoIdEjemplar();
                                $insertarLibroCatalogosTienda = (new LibrosRepositorio())->insertarLibroCatalogosTienda($tiendaTotal,$ultimoIdEjemplarInsertado);
                								if($insertarLibroCatalogosTienda){
                										$error = "Libro insertado correctamente";
                								}else{
                                    $error = "Libro no insertado correctamente";
                                }
                            }else{
                                $error = "Libro no insertado";
                            }
                        }
                  }else{
                      $error = "El ISBN está repetido";
                  }

              }
       }
       $autores = (new AutoresRepositorio())->devolverAutoresTotales();
       $editoriales = (new EditorialesRepositorio)->devolverEditorialesTotales();
       include_once __DIR__ .'/../../app/plantillas/administrador/introducirLibros.php';
     }//fin metodo


}//fin clase
?>
