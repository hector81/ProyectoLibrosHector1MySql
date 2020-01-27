<?php

class ReservaRepositorio
{
	public function insertarReserva(string $usuario) :bool{
		$sql = "INSERT INTO Reserva(Usuario,fReserva) VALUES(?,GETDATE());";
		$respuesta = false;
		$fecha = date('Y-m-d h:i:s');
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		try{
			$con = (new ConexionBaseDatos)->getConexion();
			$con->beginTransaction();
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$usuario,PDO::PARAM_STR);
			//$stmt->bindParam(2,$fecha,PDO::PARAM_STR);
			//$stmt->debugDumpParams();
			if($stmt->execute()){
				$respuesta = true;
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

	public function modificarUsuarioReserva(string $antiguoUsuario,string $nickUsuario) :bool{
		$sql = "UPDATE Reserva SET Usuario = ? WHERE Usuario = ?";
		$respuesta = false;
		$fecha = date('Y-m-d h:i:s');
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		try{
			$con = (new ConexionBaseDatos)->getConexion();
			$con->beginTransaction();
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$nickUsuario,PDO::PARAM_STR);
			$stmt->bindParam(2,$antiguoUsuario,PDO::PARAM_STR);
			if($stmt->execute()){
				$respuesta = true;
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

    public function comprobarClienteNumeroReserva(string $usuario) :bool{
		$sql = "SELECT COUNT(Usuario) AS NUMERO FROM Reserva WHERE Usuario = ?;";
		$respuesta = true;
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$usuario,PDO::PARAM_STR);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			if($row['NUMERO'] >0){//Si es mayor que 0, tenia reserva hecha antes
				$respuesta = false;
			}
		}
		$con = null;
		$stmt = null;
		return $respuesta;
    }//FIN metodo

    public function borrarCarrito(string $usuario) :bool{
        $confirmacion =false;
        include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
        $con = (new ConexionBaseDatos)->getConexion();
        $stock= 0;
        try{
            $con->beginTransaction();
            $sql = "DELETE FROM Reserva WHERE usuario = ?;";
            $stmt = $con->prepare($sql);
            $stmt->bindParam(1,$usuario,PDO::PARAM_STR);
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

		public function borrarReservaUsuario(string $usuario) :bool{
        $confirmacion =false;
        include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
        $con = (new ConexionBaseDatos)->getConexion();
        $stock= 0;
        try{
            $con->beginTransaction();
            $sql = "DELETE FROM Reserva WHERE usuario = ?;";
            $stmt = $con->prepare($sql);
            $stmt->bindParam(1,$usuario,PDO::PARAM_STR);
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

}

?>
