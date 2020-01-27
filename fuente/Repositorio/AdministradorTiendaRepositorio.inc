<?php

class AdministradorTiendaRepositorio
{
  public function devolverAdministradoresTiendasPorEmail(string $email) :array{
    	include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
    	include_once __DIR__ . '/../../fuente/modelo/administradorTienda.inc';
    	$usuario = [];
    	$con = (new ConexionBaseDatos)->getConexion();
    	$sql = "SELECT Usuario, Contrasenia,IdGrupoUsuario,Nombre,PrimerApellido,SegundoApellido,IdCiudad,Telefono,Direccion,Nif,Fax,Email,IdTienda,Activo
    		  FROM AdministradorTienda WHERE Email = ?;";
    	$stmt = $con->prepare($sql);
    	$stmt->bindParam(1,$email,PDO::PARAM_STR);
    	$stmt->execute();
    	while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
    		$usuario[] = new AdministradorTienda($row);
    	}
    	$stmt = null;
    	$con = null;
    	return $usuario;
  }//fin metodo

  public function modificarAdministradorTienda(string $nickUsuario,string $nombreUsuario,string $apellidos1,string $apellidos2,string $direccionUsuario
		,int $IdCiudadUsuario,string $tlfnoUsuario,string $nifUsuario,string $eCorreoUsuario,string $faxUsuario,string $emailAntiguo
		,string $contraseniaUsuarioNUEVA,string $contraseniaUsuarioVIEJA) :bool{
		$respuesta = true;
		$sql ="UPDATE AdministradorTienda SET
			Usuario = ?,
			Nombre = ?,
			PrimerApellido = ?,
			SegundoApellido = ?,
			Telefono = ?,
			Direccion = ?,
			Nif = ?,
			Fax = ?,
			Email = ?,
			Contrasenia = ?,
			IdCiudad = ? WHERE Email = ?";
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		try{
			$con = (new ConexionBaseDatos)->getConexion();
			$con->beginTransaction();
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$nickUsuario,PDO::PARAM_STR);
			$stmt->bindParam(2,$nombreUsuario,PDO::PARAM_STR);
			$stmt->bindParam(3,$apellidos1,PDO::PARAM_STR);
			$stmt->bindParam(4,$apellidos2,PDO::PARAM_STR);
			$stmt->bindParam(5,$tlfnoUsuario,PDO::PARAM_STR);
			$stmt->bindParam(6,$direccionUsuario,PDO::PARAM_STR);
			$stmt->bindParam(7,$nifUsuario,PDO::PARAM_STR);
			$stmt->bindParam(8,$faxUsuario,PDO::PARAM_STR);
			$stmt->bindParam(9,$eCorreoUsuario,PDO::PARAM_STR);
			//esto es por si ha introducido un password vacio, entonces se introduce la antigua
			if($contraseniaUsuarioNUEVA != ''){
				$contraseniaCodificada = password_hash($contraseniaUsuarioNUEVA, PASSWORD_DEFAULT);//codificarContrasenia, es un string lo que da
				$stmt->bindParam(10,$contraseniaCodificada,PDO::PARAM_STR);
			}else{
				$stmt->bindParam(10,$contraseniaUsuarioVIEJA,PDO::PARAM_STR);
			}
			$stmt->bindParam(11,$IdCiudadUsuario,PDO::PARAM_INT);
			$stmt->bindParam(12,$emailAntiguo,PDO::PARAM_STR);
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

}//FIN CLASE
?>
