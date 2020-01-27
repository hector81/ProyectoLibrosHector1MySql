<?php
include_once __DIR__ . "/../Repositorio/editorialesRepositorio.inc";
include_once __DIR__ . "/../Repositorio/usuarioRepositorio.inc";
class EditorialesController
{
    public function administrarEditoriales(){
        $editoriales = (new EditorialesRepositorio)->devolverEditorialesTotales();
        $ciudades = (new EditorialesRepositorio)->devolverArrayEditorialesCiudades($editoriales);
        include_once __DIR__ .'/../../app/plantillas/administrador/administrarEditoriales.php';
    }//fin metodo

    public function verEditorialesVisitante(){
        $editoriales = (new EditorialesRepositorio)->devolverEditorialesTotales();
        $ciudades = (new EditorialesRepositorio)->devolverArrayEditorialesCiudades($editoriales);
        include_once __DIR__ .'/../../app/plantillas/visitante/verEditorialesVisitante.php';
    }

    public function verEditorialesUsuario(){
        $editoriales = (new EditorialesRepositorio)->devolverEditorialesTotales();
        $ciudades = (new EditorialesRepositorio)->devolverArrayEditorialesCiudades($editoriales);
        include_once __DIR__ .'/../../app/plantillas/usuario/verEditorialesUsuario.php';
    }

    public function verEditorialesAdministradorTiendas(){
        $idTienda = $_SESSION['idTienda'];
        $editoriales = (new EditorialesRepositorio)->devolverEditorialesTotalesPorTienda($idTienda);
        $ciudades = (new EditorialesRepositorio)->devolverArrayEditorialesCiudades($editoriales);
        include_once __DIR__ .'/../../app/plantillas/administradorTienda/verEditorialesAdministradorTiendas.php';
    }//fin metodo

    public function verLibrosEditorialesVisitantes(){
      $nombreEditorial = $_POST['nombreEditorial'];
      $idEditorial = (int)$_POST['idEditorial'];
      $libros = (new EditorialesRepositorio())->devolverTodosLibrosPorEditorial($idEditorial);
      include_once __DIR__ .'/../../app/plantillas/visitante/verLibrosEditorialesVisitantes.php';
    }//fin metodo

    public function verLibrosEditorialesUsuarios(){
      $nombreEditorial = $_POST['nombreEditorial'];
      $idEditorial = (int)$_POST['idEditorial'];
      $libros = (new EditorialesRepositorio())->devolverTodosLibrosPorEditorial($idEditorial);
      include_once __DIR__ .'/../../app/plantillas/usuario/verLibrosEditorialesUsuarios.php';
    }//fin metodo

    public function verLibrosEditorialesAdministradorTiendas(){
        $nombreEditorial = $_POST['nombreEditorial'];
        $idEditorial = (int)$_POST['idEditorial'];
        $idTienda = (int)$_POST['idTienda'];
        $libros = (new EditorialesRepositorio())->devolverTodosLibrosAlmacenPorEditorial($idTienda,$idEditorial);
        include_once __DIR__ .'/../../app/plantillas/administradorTienda/verLibrosEditorialesAdministradorTiendas.php';
    }//fin metodo

    public function modificarEditorialAdministrador(){
        if($_SERVER['REQUEST_METHOD']=='POST'){
            $idEditorial = (int)$_POST['IdEditorial'];
            $editoriales = (new EditorialesRepositorio)->devolverEditorialesPorId($idEditorial);
        }
        include_once __DIR__ .'/../../app/plantillas/administrador/modificarEditorialAdministrador.php';
    }//fin metodo

    public function borrarEditorialAdministrador(){
        if($_SERVER['REQUEST_METHOD']=='POST'){
            $idEditorial = (int)$_POST['IdEditorial'];
            $numeroLibrosEditorial = (new EditorialesRepositorio)->devolverLibrosPorEditorial($idEditorial);
            if($numeroLibrosEditorial  < 1){
                  $borrarEditorial = (new EditorialesRepositorio)->borrarEditorial($idEditorial);
                  if($borrarEditorial){
                        $error= "Editorial borrada";
                  }else{
                        $error= "Editorial no borrada";
                  }

            }else{
                  $error= "No puedes borrar la editorial porque tiene libros asociados";
            }
        }
        $editoriales = (new EditorialesRepositorio)->devolverEditorialesTotales();
        $ciudades = (new EditorialesRepositorio)->devolverArrayEditorialesCiudades($editoriales);
        include_once __DIR__ .'/../../app/plantillas/administrador/administrarEditoriales.php';
    }//fin metodo

    public function enviarDatosModificacionAdministradorEditorial(){
        if($_SERVER['REQUEST_METHOD']=='POST'){
          if(empty($_POST['nombre']) && isset($_POST['nombre'])){
            $error= "Debes poner un nombre de editorial";
          }elseif(empty($_POST['direccion']) && isset($_POST['direccion'])){
            $error= "Debes poner una dirección";
          }elseif(empty($_POST['municipio']) && isset($_POST['municipio'])){
            $error= "Debes elegir una ciudad";
          }elseif(empty($_POST['telefono']) && isset($_POST['telefono'])){
            $error= "Debes elegir u pais";
          }elseif(empty($_POST['email']) && isset($_POST['email'])){
            $error= "Debes poner un email";
          }else{
            $booleanTelefono =(new UsuarioRepositorio())->comprobarTelefono($_POST['telefono']);//devolvera false si no es correcto
            if(!$booleanTelefono){
                $error= "El formato de telefono debe ser correcto";
            }else{
                $nombre = $_POST['nombre'];
                $direccion = $_POST['direccion'];
                $idCiudad =(int)$_POST['municipio'];
                $telefono = $_POST['telefono'];
                $email = $_POST['email'];
                $fax = $_POST['fax'];
                $idEditorial = (int)$_POST['IdEditorial'];
                $boolModificarEditorial= (new EditorialesRepositorio)->modificarEditorial(
                  $nombre,$direccion,$idCiudad,$telefono,$email,$fax,$idEditorial
                );
                if($boolModificarEditorial){
                    $error= "La editorial ha sido modificada correctamente";
                }else{
                    $error= "La editorial no ha sido modificada correctamente";
                }
            }


          }
        }
        $editoriales = (new EditorialesRepositorio)->devolverEditorialesTotales();
        $ciudades = (new EditorialesRepositorio)->devolverArrayEditorialesCiudades($editoriales);
        include_once __DIR__ .'/../../app/plantillas/administrador/administrarEditoriales.php';
    }//fin metodo

    public function introducirEditoriales(){
        include_once __DIR__ .'/../../app/plantillas/administrador/introducirEditoriales.php';
    }//fin metodo

    public function enviarDatosintroduccionAdministradorEditorial(){
      if($_SERVER['REQUEST_METHOD']=='POST'){
        if(empty($_POST['nombre']) && isset($_POST['nombre'])){
          $error= "Debes poner un nombre de editorial";
        }elseif(empty($_POST['direccion']) && isset($_POST['direccion'])){
          $error= "Debes poner una dirección";
        }elseif(empty($_POST['municipio']) && isset($_POST['municipio'])){
          $error= "Debes elegir una ciudad";
        }elseif(empty($_POST['telefono']) && isset($_POST['telefono'])){
          $error= "Debes elegir u pais";
        }elseif(empty($_POST['email']) && isset($_POST['email'])){
          $error= "Debes poner un email";
        }else{
          $booleanTelefono =(new UsuarioRepositorio())->comprobarTelefono($_POST['telefono']);//devolvera false si no es correcto
          if(!$booleanTelefono){
              $error= "El formato de telefono debe ser correcto";
          }else{
              $nombre = $_POST['nombre'];
              $direccion = $_POST['direccion'];
              $idCiudad =(int)$_POST['municipio'];
              $telefono = $_POST['telefono'];
              $email = $_POST['email'];
              $fax = $_POST['fax'];
              $boolIntroducirEditorial= (new EditorialesRepositorio)->introducirEditorial(
                $nombre,$direccion,$idCiudad,$telefono,$email,$fax
              );
              if($boolIntroducirEditorial){
                  $error= "La editorial ha sido introducida correctamente";
              }else{
                  $error= "La editorial no ha sido introducida correctamente";
              }
          }


        }
      }
      $editoriales = (new EditorialesRepositorio)->devolverEditorialesTotales();
      $ciudades = (new EditorialesRepositorio)->devolverArrayEditorialesCiudades($editoriales);
      include_once __DIR__ .'/../../app/plantillas/administrador/administrarEditoriales.php';
    }


}//fin clase
?>
