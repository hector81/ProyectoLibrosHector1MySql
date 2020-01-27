<?php
include_once __DIR__ . "/../Repositorio/almacenRepositorio.inc";
include_once __DIR__ . "/../Repositorio/tiendasRepositorio.inc";
class AlmacenController
{
    public function administrarAlmacen(){
        $tiendaTotal = (new TiendasRepositorio())->devolverTiendasTotales();
        include_once __DIR__ .'/../../app/plantillas/administrador/administrarAlmacen.php';
    }//fin metodo

    public function verTodosMisLibrosAdministradorTienda(){
      $idTienda = (int)$_SESSION['idTienda'];
      $librosAlmacen = (new AlmacenRepositorio)->devolverTodosLibrosAlmacen($idTienda);
      include_once __DIR__ .'/../../app/plantillas/administradorTienda/verTodosMisLibrosAdministradorTienda.php';
    }

    public function enviarDatosAlmacen(){
        $tiendaTotal = (new TiendasRepositorio())->devolverTiendasTotales();
    		if($_SERVER['REQUEST_METHOD']=='POST'){
    			if(empty($_POST['tienda']) && isset($_POST['tienda'])){
    				$error= "Debes elegir una tienda";include_once __DIR__ .'/../../app/plantillas/administrador/administrarAlmacen.php';
    			}elseif(empty($_POST['categoria']) && isset($_POST['categoria'])){
    				$error= "Debes elegir una categoria";include_once __DIR__ .'/../../app/plantillas/administrador/administrarAlmacen.php';
    			}elseif(empty($_POST['subcategoria']) && isset($_POST['subcategoria'])){
    				$error= "Debes elegir una subcategoria";include_once __DIR__ .'/../../app/plantillas/administrador/administrarAlmacen.php';
    			}else{
    				$idTienda = (int)$_POST['tienda'];
    				$idCategoria = (int)$_POST['categoria'];
    				$idSubcategoria = (int)$_POST['subcategoria'];
    				$librosAlmacen = (new AlmacenRepositorio)->devolverLibrosAlmacen($idTienda,$idCategoria,$idSubcategoria);
            include_once __DIR__ .'/../../app/plantillas/administrador/verLibrosAlmacen.php';
    			}
    		}


    }//fin metodo

    public function enviarDatosAlmacenAdministradorTienda(){
    		if($_SERVER['REQUEST_METHOD']=='POST'){
    			if(empty($_POST['categoria']) && isset($_POST['categoria'])){
    				$error= "Debes elegir una categoria";
    			}elseif(empty($_POST['subcategoria']) && isset($_POST['subcategoria'])){
    				$error= "Debes elegir una subcategoria";
    			}else{
    				$idTienda = (int)$_SESSION['idTienda'];
    				$idCategoria = (int)$_POST['categoria'];
    				$idSubcategoria = (int)$_POST['subcategoria'];
    				$librosAlmacen = (new AlmacenRepositorio)->devolverLibrosAlmacen($idTienda,$idCategoria,$idSubcategoria);
    			}
    		}
		include_once __DIR__ .'/../../app/plantillas/administradorTienda/verLibrosAlmacen.php';
    }//fin metodo

    public function modificarStockTienda(){
          $idTienda = (int)$_POST['idTienda'];
          $idCategoria = (int)$_POST['idCategoria'];
          $idSubcategoria = (int)$_POST['idSubcategoria'];
          $idEjemplar = (int)$_POST['idEjemplar'];
    		if($_SERVER['REQUEST_METHOD']=='POST'){
    			if(empty($_POST['stockModificado']) && isset($_POST['stockModificado'])){
    				$error= "Debes poner un stock";
    			}else{
                $stockModificado = (int)$_POST['stockModificado'];
                if($stockModificado < 1){
                    $error= "Debes poner un número positivo o 0";
                }else{
                    $booleanModificadoStock = (new AlmacenRepositorio)->modificarStock($idTienda,$idEjemplar,$stockModificado);
                    if($booleanModificadoStock){
                      $error= "El stock ha sido modificado";
                    }else{
                      $error= "El stock no ha sido modificado";
                    }
                }
    			}
    		}
        $librosAlmacen = (new AlmacenRepositorio)->devolverLibrosAlmacen($idTienda,$idCategoria,$idSubcategoria);
        if($_SESSION['grupoUser'] == 'administradorTienda'){
            include_once __DIR__ .'/../../app/plantillas/administradorTienda/verLibrosAlmacen.php';
        }
        if($_SESSION['grupoUser'] == 'superAdministrador'){
            include_once __DIR__ .'/../../app/plantillas/administrador/verLibrosAlmacen.php';
        }

    }//fin metodo


}//fin clase
?>
