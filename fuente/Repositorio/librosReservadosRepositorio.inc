<?php

class LibrosReservadosRepositorio
{
    public function comprobarLibrosReservadosDuplicados(string $usuario,int $idEjemplar, int $idTienda) :bool{
        $sql = "SELECT IdEjemplar,IdTienda FROM LibrosReservados WHERE Usuario = ?;";
        $respuesta = false;
        include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
    		$con = (new ConexionBaseDatos)->getConexion();
    		$stmt = $con->prepare($sql);
    		$stmt->bindParam(1,$usuario,PDO::PARAM_STR);
        $stmt->bindParam(2,$idTienda,PDO::PARAM_STR);
    		$stmt->execute();
    		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
    			if($row['IdEjemplar'] == $idEjemplar && $row['IdTienda'] == $idTienda){
    				$respuesta = true;
    			}
    		}//FIN WHILE
    		$con = null;
    		$stmt = null;
    		return $respuesta;
    }//fin metodo

    public function insertarLineaReservaLibro(string $usuario,int $idEjemplar,int $cantidad,float $cantidadTotal,int $idTienda) :bool{
        $sql = "INSERT INTO LibrosReservados(Usuario,IdEjemplar,cantidad,pReserva,IdTienda) VALUES(?,?,?,?,?);";
        $respuesta = true;
        include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
        try{
            $con = (new ConexionBaseDatos)->getConexion();
            $con->beginTransaction();
            $stmt = $con->prepare($sql);
            $stmt->bindParam(1,$usuario,PDO::PARAM_STR);
            $stmt->bindParam(2,$idEjemplar,PDO::PARAM_INT);
            $stmt->bindParam(3,$cantidad,PDO::PARAM_INT);
            $stmt->bindParam(4,$cantidadTotal,PDO::PARAM_INT);
            $stmt->bindParam(5,$idTienda,PDO::PARAM_INT);
            if($stmt->execute()){
              $respuesta = false;
            }
            $con->commit();
            return $respuesta;
        }catch(PDOException $ex){
           throw $ex;
           $con->rollBack();
        }finally{
          $con = null;
          $stmt = null;
        }
	}//fin metodo

	public function devolverCarrito(string $usuario) :array{
		include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
		require_once __DIR__ . '/../../fuente/Modelo/librosReservados.inc';
		$librosReservados=[];
		$sql = "SELECT Usuario,IdEjemplar,cantidad,pReserva,IdTienda FROM LibrosReservados
				WHERE Usuario = ?;";
		$con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$usuario,PDO::PARAM_STR);
		$stmt->execute();
		while ( $row = $stmt->fetch( PDO::FETCH_ASSOC ) ){
			$librosReservados[] = new LibrosReservados($row);
		}
		$stmt =null;
		$con=null;
		return $librosReservados;
	}//fin metodo

	public function devolverLineasReservaPorUsuario(string $usuario) :int{
		include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
		$librosCuenta=0;
		$sql = "SELECT COUNT(Usuario) AS NUMERO_LINEAS_RESERVA FROM LibrosReservados WHERE Usuario = ?;";
		$con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$usuario,PDO::PARAM_STR);
		$stmt->execute();
		while ( $row = $stmt->fetch( PDO::FETCH_ASSOC ) ){
		   $librosCuenta = $row['NUMERO_LINEAS_RESERVA'];
		}
		$stmt =null;
	    $con=null;
		return $librosCuenta;
	}//fin metodo

	public function devolverTitulosCarrito(array $carrito) :array{
		$titulos = [];
		include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
		$sql = "SELECT Libros.Titulo AS TITULO_LIBRO FROM Libros
			JOIN Ejemplares ON Ejemplares.IdLibro = Libros.IdLibro
			WHERE IdEjemplar = ?";
		foreach ($carrito as $key => $value) {
			$id  = (int)$value->getIdEjemplar();
			$con = (new ConexionBaseDatos)->getConexion();
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$id,PDO::PARAM_INT);
			$stmt->execute();
			while ( $row = $stmt->fetch( PDO::FETCH_ASSOC ) ){
				$titulos[] = $row['TITULO_LIBRO'];
			}
			$stmt =null;
			$con=null;
		}
		return $titulos;
	}//fin metodo

	public function devolverTiendasCarrito(array $carrito) :array{
		$tiendas = [];
		include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
		$sql = "SELECT Nombre FROM Tiendas WHERE IdTienda =  ?";
		foreach ($carrito as $key => $value) {
			$id  = (int)$value->getIdTienda();
			$con = (new ConexionBaseDatos)->getConexion();
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$id,PDO::PARAM_INT);
			$stmt->execute();
			while ( $row = $stmt->fetch( PDO::FETCH_ASSOC ) ){
				$tiendas[] = $row['Nombre'];
			}
			$stmt =null;
			$con=null;
		}
		return $tiendas;
	}//fin metodo

	public function borrarLineaLibrosReservados(string $usuario,int $idEjemplar, int $IdTienda) :bool{
		$confirmacion =false;
		include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stock= 0;
		try{
			$con->beginTransaction();
			$sql = "DELETE FROM LibrosReservados WHERE usuario = ? AND IdEjemplar = ? AND IdTienda = ?;";
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$usuario,PDO::PARAM_STR);
			$stmt->bindParam(2,$idEjemplar,PDO::PARAM_INT);
      $stmt->bindParam(3,$IdTienda,PDO::PARAM_INT);
			if($stmt->execute()){
				$confirmacion =true;
			}
			$con->commit();
			return $confirmacion;
		}catch(PDOException  $eX ){
			echo "Error: ".$eX;
			$con->rollback();
		}finally {
			$con = null;
			$stmt = null;
		}
	}//fin metodo

  public function devolverLibrosReservadosAlALmacen(array $carrito) :bool{
    include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
    $boolStock= false;
    foreach ($carrito as $key => $value) {
          $con = (new ConexionBaseDatos)->getConexion();
          $sql = "EXEC devolverLibrosReservadosAlALmacen ?,?,?;";
          $boolStock= false; //lo iniciamos en el bucle a false para comprobar que hace bien todas las vueltas
          $cantidad = (int)$value->getCantidad();
          $idTienda = (int)$value->getIdTienda();
          $idEjemplar = (int)$value->getIdEjemplar();
          try{
                $con->beginTransaction();
                $stmt = $con->prepare($sql);
                $stmt->bindParam(1,$cantidad,PDO::PARAM_INT);
                $stmt->bindParam(2,$idTienda,PDO::PARAM_INT);
                $stmt->bindParam(3,$idEjemplar,PDO::PARAM_INT);
            if($stmt->execute()){
                $boolStock= true;
            }
            $con->commit();
          }catch(PDOException  $eX ){
              echo "Error: ".$eX;
              $con->rollback();
          }finally {
              $con = null;
              $stmt = null;
          }

    }
    return $boolStock;
  }//fin metodo

  public function sumarCantidadEjemplarDuplicado(string $usuario,int $idEjemplar,int $idTienda,int $cantidad,float $PVPlibro) :bool{
      include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
      //primero sacamos la antigua $cantidad
      $con1 = (new ConexionBaseDatos)->getConexion();
      $antiguaCantidad = 0;
      $sql1 = "SELECT cantidad FROM LibrosReservados where Usuario = ? and IdEjemplar = ? AND IdTienda = ?";
      $stmt1 = $con1->prepare($sql1);
      $stmt1->bindParam(1,$usuario,PDO::PARAM_STR);
      $stmt1->bindParam(2,$idEjemplar,PDO::PARAM_INT);
      $stmt1->bindParam(3,$idTienda,PDO::PARAM_INT);
      $stmt1->execute();
      while ( $row1 = $stmt1->fetch( PDO::FETCH_ASSOC ) ){
        $antiguaCantidad = $row1['cantidad'];
      }
      $stmt1 =null;
      $con1=null;
      //sumamos la cantidad antigua a la nnueva
      $nuevaCantidad = $antiguaCantidad + $cantidad;
      $pReserva = (float)($PVPlibro*$nuevaCantidad);
      //ahora borramos esa linea
      $con2 = (new ConexionBaseDatos)->getConexion();
      $sql2 = "DELETE FROM LibrosReservados WHERE idTienda = ? AND idEjemplar = ? AND Usuario = ?;";
      try{
            $con2->beginTransaction();
            $stmt2 = $con2->prepare($sql2);
            $stmt2->bindParam(1,$idTienda,PDO::PARAM_INT);
            $stmt2->bindParam(2,$idEjemplar,PDO::PARAM_INT);
            $stmt2->bindParam(3,$usuario,PDO::PARAM_STR);
            $stmt2->execute();
            $con2->commit();
      }catch(PDOException  $eX ){
          echo "Error: ".$eX;
          $con2->rollback();
      }finally {
          $con2 = null;
          $stmt2 = null;
      }
      ///////ahora insertamos otra vez la linea
      $con = (new ConexionBaseDatos)->getConexion();
      $boolDuplica= false;
      $sql = "INSERT INTO LibrosReservados(Usuario,IdEjemplar,cantidad,pReserva,IdTienda) VALUES(?,?,?,?,?);";
      try{
            $con->beginTransaction();
            $stmt = $con->prepare($sql);
            $stmt->bindParam(1,$usuario,PDO::PARAM_STR);
            $stmt->bindParam(2,$idEjemplar,PDO::PARAM_INT);
            $stmt->bindParam(3,$nuevaCantidad,PDO::PARAM_INT);
            $stmt->bindParam(4,$pReserva,PDO::PARAM_INT);
            $stmt->bindParam(5,$idTienda,PDO::PARAM_INT);
        if($stmt->execute()){
            $boolDuplica= true;
        }
        $con->commit();
        return $boolDuplica;
      }catch(PDOException  $eX ){
          echo "Error: ".$eX;
          $con->rollback();
      }finally {
          $con = null;
          $stmt = null;
      }
      return $boolDuplica;
  }//fin metodo





}//fin clase

?>
