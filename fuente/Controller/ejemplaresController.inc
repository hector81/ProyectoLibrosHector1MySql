<?php
include_once __DIR__ . "/../Repositorio/ejemplaresRepositorio.inc";
class EjemplaresController
{
    public function verLibrosPorBoton(){
        if($_SERVER['REQUEST_METHOD']=='GET'){
            if(!empty($_GET['yearPublicacion']) && isset($_GET['yearPublicacion'])){
                  $palabra = $_GET['yearPublicacion'];$redireccion = $_GET['redireccion'] ;
          				if($redireccion == 'usuario'){
                    $libros = (new EjemplaresRepositorio)->verLibrosPorYearUsuario($_GET['yearPublicacion']);//devuelve un array
          					include_once __DIR__ .'/../../app/plantillas/usuario/verLibrosPorBotonUsuario.php';
          				}
          				if($redireccion == 'visitante'){
                    $libros = (new EjemplaresRepositorio)->verLibrosPorYearUsuario($_GET['yearPublicacion']);//devuelve un array
          					include_once __DIR__ .'/../../app/plantillas/visitante/verLibrosPorBotonUsuario.php';
          				}
          				if($redireccion == 'superAdministrador'){
                    $libros = (new EjemplaresRepositorio)->verLibrosPorYearUsuario($_GET['yearPublicacion']);//devuelve un array
          					include_once __DIR__ .'/../../app/plantillas/administrador/verLibrosPorBotonUsuario.php';
          				}
          				if($redireccion == 'administradorTienda'){
                    $idTienda = (int)$_SESSION['idTienda'];
                    $libros = (new EjemplaresRepositorio)->verLibrosPorYearUsuarioTienda($_GET['yearPublicacion'],$idTienda);//devuelve un array
          					include_once __DIR__ .'/../../app/plantillas/administradorTienda/verLibrosPorBotonUsuario.php';
          				}
            }
            elseif(!empty($_GET['autor']) && isset($_GET['autor'])){

          				$palabra = $_GET['autor'];$redireccion = $_GET['redireccion'] ;
          				if( $redireccion == 'usuario'){
                    $libros = (new EjemplaresRepositorio)->verLibrosPorAutorUsuario($_GET['autor']);//devuelve un array
          					include_once __DIR__ .'/../../app/plantillas/usuario/verLibrosPorBotonUsuario.php';
          				}
          				if($redireccion == 'visitante'){
                    $libros = (new EjemplaresRepositorio)->verLibrosPorAutorUsuario($_GET['autor']);//devuelve un array
          					include_once __DIR__ .'/../../app/plantillas/visitante/verLibrosPorBotonUsuario.php';
          				}
          				if($redireccion == 'superAdministrador'){
                    $libros = (new EjemplaresRepositorio)->verLibrosPorAutorUsuario($_GET['autor']);//devuelve un array
          					include_once __DIR__ .'/../../app/plantillas/administrador/verLibrosPorBotonUsuario.php';
          				}
          				if($redireccion == 'administradorTienda'){
                    $idTienda = (int)$_SESSION['idTienda'];
                    $libros = (new EjemplaresRepositorio)->verLibrosPorAutorUsuarioTienda($_GET['autor'],$idTienda);//devuelve un array
          					include_once __DIR__ .'/../../app/plantillas/administradorTienda/verLibrosPorBotonUsuario.php';
          				}
            }elseif(!empty($_GET['categoria']) && isset($_GET['categoria'])){

          				$palabra = $_GET['categoria'];$redireccion = $_GET['redireccion'] ;
          				if($redireccion  == 'usuario'){
                    $libros = (new EjemplaresRepositorio)->verLibrosPorCategoriaUsuarioBoton($_GET['categoria']);//devuelve un array
          					include_once __DIR__ .'/../../app/plantillas/usuario/verLibrosPorBotonUsuario.php';
          				}
          				if($redireccion == 'visitante'){
                    $libros = (new EjemplaresRepositorio)->verLibrosPorCategoriaUsuarioBoton($_GET['categoria']);//devuelve un array
          					include_once __DIR__ .'/../../app/plantillas/visitante/verLibrosPorBotonUsuario.php';
          				}
          				if($redireccion == 'superAdministrador'){
                    $libros = (new EjemplaresRepositorio)->verLibrosPorCategoriaUsuarioBoton($_GET['categoria']);//devuelve un array
          					include_once __DIR__ .'/../../app/plantillas/administrador/verLibrosPorBotonUsuario.php';
          				}
          				if($redireccion == 'administradorTienda'){
                    $idTienda = (int)$_SESSION['idTienda'];
                    $libros = (new EjemplaresRepositorio)->verLibrosPorCategoriaUsuarioBotonTienda($_GET['categoria'],$idTienda);//devuelve un array
          					include_once __DIR__ .'/../../app/plantillas/administradorTienda/verLibrosPorBotonUsuario.php';
          				}
            }
            elseif(!empty($_GET['subCategoria']) && isset($_GET['subCategoria'])){

          				$palabra= $_GET['subCategoria'];$redireccion = $_GET['redireccion'] ;
          				if($redireccion  == 'usuario'){
                    $libros = (new EjemplaresRepositorio)->verLibrosPorSubCategoriaUsuarioBoton($_GET['subCategoria']);//devuelve un array
          					include_once __DIR__ .'/../../app/plantillas/usuario/verLibrosPorBotonUsuario.php';
          				}
          				if($redireccion == 'visitante'){
                    $libros = (new EjemplaresRepositorio)->verLibrosPorSubCategoriaUsuarioBoton($_GET['subCategoria']);//devuelve un array
          					include_once __DIR__ .'/../../app/plantillas/visitante/verLibrosPorBotonUsuario.php';
          				}
          				if($redireccion == 'superAdministrador'){
                    $libros = (new EjemplaresRepositorio)->verLibrosPorSubCategoriaUsuarioBoton($_GET['subCategoria']);//devuelve un array
          					include_once __DIR__ .'/../../app/plantillas/administrador/verLibrosPorBotonUsuario.php';
          				}
          				if($redireccion == 'administradorTienda'){
                    $idTienda = (int)$_SESSION['idTienda'];
                    $libros = (new EjemplaresRepositorio)->verLibrosPorSubCategoriaUsuarioBotonTienda($_GET['subCategoria'],$idTienda);//devuelve un array
          					include_once __DIR__ .'/../../app/plantillas/administradorTienda/verLibrosPorBotonUsuario.php';
          				}
            }
            elseif(!empty($_GET['editorial']) && isset($_GET['editorial'])){

        				$palabra = $_GET['editorial'];$redireccion = $_GET['redireccion'] ;
        				if($redireccion  == 'usuario'){
                  $libros = (new EjemplaresRepositorio)->verLibrosPorEditorialUsuarioBoton($_GET['editorial']);//devuelve un array
        					include_once __DIR__ .'/../../app/plantillas/usuario/verLibrosPorBotonUsuario.php';
        				}
        				if($redireccion == 'visitante'){
                  $libros = (new EjemplaresRepositorio)->verLibrosPorEditorialUsuarioBoton($_GET['editorial']);//devuelve un array
        					include_once __DIR__ .'/../../app/plantillas/visitante/verLibrosPorBotonUsuario.php';
        				}
        				if($redireccion == 'superAdministrador'){
                  $libros = (new EjemplaresRepositorio)->verLibrosPorEditorialUsuarioBoton($_GET['editorial']);//devuelve un array
        					include_once __DIR__ .'/../../app/plantillas/administrador/verLibrosPorBotonUsuario.php';
        				}
        				if($redireccion == 'administradorTienda'){
                  $idTienda = (int)$_SESSION['idTienda'];
                  $libros = (new EjemplaresRepositorio)->verLibrosPorEditorialUsuarioBotonTienda($_GET['editorial'],$idTienda);//devuelve un array
        					include_once __DIR__ .'/../../app/plantillas/administradorTienda/verLibrosPorBotonUsuario.php';
        				}
            }
        }
    }//fin metodo



}//fin clase
?>
