<?php
include_once __DIR__ . "/../Repositorio/autoresRepositorio.inc";
include_once __DIR__ . "/../Repositorio/paisesRepositorio.inc";
include_once __DIR__ . "/../Repositorio/EjemplaresRepositorio.inc";
class AutoresController
{
    public function introducirAutores(){
        $paises = (new PaisesRepositorio())->devolverTodosPaises();
        include_once __DIR__ .'/../../app/plantillas/administrador/introducirAutores.php';
    }//fin metodo

    public function verAutores(){
        $autores = (new AutoresRepositorio())->devolverAutoresTotales();
        include_once __DIR__ .'/../../app/plantillas/administrador/verAutores.php';
    }//fin metodo

    public function verAutoresUsuarios(){
        $autores = (new AutoresRepositorio())->devolverAutoresTotales();
        include_once __DIR__ .'/../../app/plantillas/usuario/verAutoresUsuarios.php';
    }//fin metodo

    public function verAutoresVisitante(){
        $autores = (new AutoresRepositorio())->devolverAutoresTotales();
        include_once __DIR__ .'/../../app/plantillas/visitante/verAutoresVisitante.php';
    }//fin metodo

    public function verAutoresAdministradorTienda(){
        $idTienda = $_SESSION['idTienda'];
        $autores = (new AutoresRepositorio())->devolverAutoresTotalesPorTienda($idTienda);
        include_once __DIR__ .'/../../app/plantillas/administradorTienda/verAutoresAdministradorTienda.php';
    }//fin metodo

    public function verLibrosAutorVisitante(){
        $nombreAutor = $_POST['nombreAutor'];
        $idAutor = (int)$_POST['idAutor'];
        $libros = (new AutoresRepositorio())->devolverTodosLibrosPorAutor($idAutor);
        include_once __DIR__ .'/../../app/plantillas/visitante/verLibrosAutorVisitante.php';
    }//fin metodo

    public function verLibrosAutorUsuario(){
        $nombreAutor = $_POST['nombreAutor'];
        $idAutor = (int)$_POST['idAutor'];
        $libros = (new AutoresRepositorio())->devolverTodosLibrosPorAutor($idAutor);
        include_once __DIR__ .'/../../app/plantillas/usuario/verLibrosAutorUsuario.php';
    }//fin metodo  verLibrosAutorUsuario

    public function verLibrosAutorAdministradorTienda(){
        $nombreAutor = $_POST['nombreAutor'];
        $idAutor = (int)$_POST['idAutor'];
        $idTienda = (int)$_POST['idTienda'];
        $libros = (new AutoresRepositorio())->devolverTodosLibrosAlmacenPorAutor($idTienda,$idAutor);
        include_once __DIR__ .'/../../app/plantillas/administradorTienda/verLibrosAutorAdministradorTienda.php';
    }//fin metodo

    public function verListaAutores(){
        $autores = (new AutoresRepositorio())->devolverAutoresTotales();
        include_once __DIR__ .'/../../app/plantillas/visitante/verListaAutores.php';
    }//fin metodo


    public function enviarDatosIntroduccionAutores(){
        if($_SERVER['REQUEST_METHOD']=='POST'){
    			if(empty($_POST['nombreAutor']) && isset($_POST['nombreAutor'])){
    				$error= "Debes poner un nombre de autor";
    			}elseif(empty($_POST['idPais']) && isset($_POST['idPais'])){
    				$error= "Debes elegir u pais";
    			}else{
    				$nombreAutor = $_POST['nombreAutor'];
    				$idPais = (int)$_POST['idPais'];
            $nacionalidad = (new PaisesRepositorio())->devolverNombrePaisPorId($idPais);
    				$boolIntroducirAutor = (new AutoresRepositorio())->introducirAutor($nombreAutor,$idPais,$nacionalidad);
            if($boolIntroducirAutor){
              $error= "Autor introducido";
            }else{
              $error= "Autor no introducido por algún problema";
            }
    			}
    		}
        $paises = (new PaisesRepositorio())->devolverTodosPaises();
    		include_once __DIR__ .'/../../app/plantillas/administrador/introducirAutores.php';
    }//fin metodo

    public function borrarAutorAdministrador(){
      if($_SERVER['REQUEST_METHOD']=='POST'){
        if(empty($_POST['idAutor']) && isset($_POST['idAutor'])){
          $error= "Debes poner un id de autor";
        }else{
            $idAutor =(int)$_POST['idAutor'];
            $contLibroAutor = (new AutoresRepositorio())->devolverNumeroLibrosAutor($idAutor);
            if($contLibroAutor < 1){
                  $boolBorrarAutor = (new AutoresRepositorio())->borrarAutorAdministrador($idAutor);
                  if($boolBorrarAutor){
                    $error= "Autor borrado";
                  }else{
                    $error= "Autor no borrado por algún problema";
                  }
            }else{
                $error= "El autor tiene libros en la base de datos y no puede ser borrado";
            }

        }
      }
      $autores = (new AutoresRepositorio())->devolverAutoresTotales();
      include_once __DIR__ .'/../../app/plantillas/administrador/verAutores.php';
    }//fin metodo

    public function modificarAutorAdministrador(){
        $idAutor = (int)$_POST['idAutor'];
        $autor = (new AutoresRepositorio())->devolverAutorPorId($idAutor);
        $paises = (new PaisesRepositorio())->devolverTodosPaises();
        include_once __DIR__ .'/../../app/plantillas/administrador/modificarAutorAdministrador.php';
    }//fin metodo

    public function enviarDatosModificacionAutor(){
      if($_SERVER['REQUEST_METHOD']=='POST'){
        if(empty($_POST['nombreAutor']) && isset($_POST['nombreAutor'])){
          $error= "Debes poner un nombre de autor";
        }elseif(empty($_POST['idPais']) && isset($_POST['idPais'])){
          $error= "Debes poner un pais de autor";
        }elseif(empty($_POST['idAutor']) && isset($_POST['idAutor'])){
          $error= "Debes poner un id de autor";
        }else{
            $nombreAutor = $_POST['nombreAutor'];
            $idPais = (int)$_POST['idPais'];
            $idAutor = (int)$_POST['idAutor'];
            $nacionalidad = (new PaisesRepositorio())->devolverNombrePaisPorId($idPais);
            $boolModificarAutor =(new AutoresRepositorio())->modificarAutor($nombreAutor,$idPais,$idAutor,$nacionalidad);
            if($boolModificarAutor){
              $error= "Autor modificado";
            }else{
              $error= "Autor no modificado por algún problema";
            }
        }
      }
      $autores = (new AutoresRepositorio())->devolverAutoresTotales();
      include_once __DIR__ .'/../../app/plantillas/administrador/verAutores.php';
    }//fin metodo

}//fin clase
?>
