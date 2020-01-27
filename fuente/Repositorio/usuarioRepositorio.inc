<?php

class UsuarioRepositorio
{
	// public function devolverTipoParaUsuario(string $email, string $contrasenia) :int{
	// 	include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
	// 	$con = (new ConexionBaseDatos)->getConexion();$entero = '';
	// 	$sql = "execute dbo.findUsuario ?, ?;";
	// 	$stmt = $con->prepare($sql);
	// 	$stmt->bindParam(1,$email,PDO::PARAM_STR);
	// 	$stmt->bindParam(2,$contrasenia,PDO::PARAM_STR);
  //   $stmt->execute();
	// 	$row = $stmt->fetch(PDO::FETCH_ASSOC);
	//
	//
  //   $stmt = null;
  //   $con = null;
  //   return (int)$row['tipo'];
	// }

	public function devolverTipo(string $email, string $contrasenia) :int{
			include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
			$entero = 0;
			//para usuarios 1
			$con1 = (new ConexionBaseDatos)->getConexion();
			$sql1 = "SELECT Contrasenia FROM Usuario WHERE Email = ?;";
			$stmt1 = $con1->prepare($sql1);
			$stmt1->bindParam(1,$email,PDO::PARAM_STR);

			if($stmt1->execute()){
						$arrayContrasenia = $stmt1->fetch(PDO::FETCH_ASSOC);
						if(password_verify($contrasenia,$arrayContrasenia['Contrasenia'])){
								$entero = 3;//si coincide
						}
			}
		  $stmt1 = null;
			//para administradores tienda 2
			$sql2 = "SELECT Contrasenia FROM AdministradorTienda WHERE Email = ?; ";
			$stmt2 = $con1->prepare($sql2);
			$stmt2->bindParam(1,$email,PDO::PARAM_STR);
			$stmt2->bindParam(2,$contraseniaCodificada,PDO::PARAM_STR);

			if($stmt2->execute()){
					$arrayContrasenia = $stmt2->fetch(PDO::FETCH_ASSOC);
					if(password_verify($contrasenia,$arrayContrasenia['Contrasenia'])){
							$entero = 2;//si coincide
					}
			}
		  $stmt2 = null;

			// //para super administradores super 1
			$sql3 = "SELECT Contrasenia FROM SuperAdministrador WHERE Email = ?; ";
			$stmt3 = $con1->prepare($sql3);
			$stmt3->bindParam(1,$email,PDO::PARAM_STR);
			$stmt3->bindParam(2,$contraseniaCodificada,PDO::PARAM_STR);

		  if($stmt3->execute()){
					$arrayContrasenia = $stmt3->fetch(PDO::FETCH_ASSOC);
					if(password_verify($contrasenia,$arrayContrasenia['Contrasenia'])){
							$entero = 1;//si coincide
					}
			}
		  $stmt3 = null;

		  $con1 = null;
			return $entero;

	}//fin metodo

	public function comprobarEmailExisteUsuario(string $email) :bool{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$comprobarUsuario = false;$sql = "SELECT Email FROM Usuario WHERE Email = ?;";
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$email,PDO::PARAM_STR);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			if($row['Email'] == $email){
				$comprobarUsuario = true;//devolvera true si existe
			}
      }
      $stmt = null;
      $con = null;
      return $comprobarUsuario;
	}//fin metodo

	public function comprobarContraseniaUsuario(string $email, string $contrasenia) :bool{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$ComprobarUsuario = true;
		if($tipo == 3){
				$sql = "SELECT contrasenia FROM Usuario WHERE Email = ?;";
		}
		if($tipo == 2){
				$sql = "SELECT contrasenia FROM AdministradorTienda WHERE Email = ?;";
		}
		if($tipo == 1){
				$sql = "SELECT contrasenia FROM SuperAdministrador WHERE Email = ?;";
		}
        $stmt = $con->prepare($sql);
        $stmt->bindParam(1,$email,PDO::PARAM_STR);
        if($stmt->execute()){
            $arrayContrasenia = $stmt->fetch(PDO::FETCH_ASSOC);
            if(password_verify($contrasenia,$arrayContrasenia['contrasenia'])){
				$ComprobarUsuario = false;//coincide
            }else{
                $ComprobarUsuario = true;//no coincide
            }
        }else{
            $ComprobarUsuario = true;//no hace bien la select
        }
        $stmt = null;
        $con = null;
        return $ComprobarUsuario;
	}//fin metodo

	public function devolverContraseniaUsuario(string $email) :string{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$password = '';
		$sql = "SELECT Contrasenia FROM dbo.usuario WHERE Email = ?;";
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$email,PDO::PARAM_STR);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			$password = $row['Contrasenia'];//devolvera la contraseña codificada
		}
		$stmt = null;
		$con = null;
		return $password;
	}//fin metodo

	public function comprobarUsuarioExiste(string $usuario) :bool{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$comprobarUsuario = false;
		$sql = "SELECT Usuario.usuario AS USER_NICK  FROM usuario WHERE Usuario.usuario = ?;";
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$usuario,PDO::PARAM_STR);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			if($row['USER_NICK'] == $usuario){
				$comprobarUsuario = true;//devolvera true si existe
			}
		}
		$stmt = null;
		$con = null;
		return $comprobarUsuario;
	}//fin metodo

	//Con esta funcion comprobamos que el dni es valido
	public function validarDni(string $dni) :bool{
		$boolDni = false;
		$numeros=  substr($dni,0,8);
		$letra = strtoupper(substr($dni,-1));
		if (substr("TRWAGMYFPDXBNJZSQVHLCKE",$numeros%23,1) == $letra){
			$boolDni = true;
		}else{
			$boolDni = false;
		}
		return $boolDni;
	}//fin metodo

	//Con esta funcion comprobamos que el dni tiene un formato valido
	public function comprobarFormatoDni(string $dni) :bool{
		$boolDni = true;
		$ultimaLetra=  substr($dni,-1);
		$primerosOchoNumeros =substr($dni,0,8);
		if (strlen($dni) != 9){ //comprobamos que la longitud no sea diferente a 9
			$boolDni = false;
		}
		if(!is_numeric($primerosOchoNumeros)){//comprobamos que los 8 primeros caracteres sean numeros
			$boolDni = false;
		}
		if(is_numeric($ultimaLetra)){//comprobamos que el ultimo caracter sea una letra
			$boolDni = false;
		}
		return $boolDni;
	}

	public function comprobarDniRepetido(string $dni) :bool{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$ComprobarDniRepetido = true;
		$sql = "SELECT COUNT(Nif) AS CONTADOR FROM dbo.usuario WHERE Nif = ?";
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$dni,PDO::PARAM_STR);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			if($row['CONTADOR'] > 0){
				$ComprobarDniRepetido = false;
			}
		}
		$stmt = null;
		$con = null;
		return $ComprobarDniRepetido;
	}//fin metodo

	public function devolverUsuarioLogueado(string $email) :array{
				include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
				include_once __DIR__ . '/../../fuente/modelo/usuario.inc';
				$con = (new ConexionBaseDatos)->getConexion();
				$user=[];
				$sql = "SELECT DISTINCT Usuario.Usuario,Usuario.Contrasenia,Usuario.IdGrupoUsuario,Usuario.Nombre,Usuario.PrimerApellido,
						Usuario.SegundoApellido,Usuario.IdCiudad,Usuario.Telefono,Usuario.Direccion,Usuario.Nif,
						Usuario.Fax,Usuario.Email,Usuario.Activo
						FROM Usuario
						WHERE Usuario.Email = ?";
				$stmt = $con->prepare($sql);
				$stmt->bindParam(1,$email,PDO::PARAM_STR);
				$stmt->execute();
				while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
					$user[] = new Usuario($row);
				}
				$stmt = null;
				$con = null;
				return $user;
	}//fin metodo

	public function devolverUsuarioPorNick(string $user) :array{
				include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
				include_once __DIR__ . '/../../fuente/modelo/usuario.inc';
				$con = (new ConexionBaseDatos)->getConexion();
				$userTotal=[];
				$sql = "SELECT DISTINCT Usuario.Usuario,Usuario.Contrasenia,Usuario.IdGrupoUsuario,Usuario.Nombre,Usuario.PrimerApellido,
						Usuario.SegundoApellido,Usuario.IdCiudad,Usuario.Telefono,Usuario.Direccion,Usuario.Nif,
						Usuario.Fax,Usuario.Email,Usuario.Activo
						FROM Usuario
						WHERE Usuario.Usuario = ?";
				$stmt = $con->prepare($sql);
				$stmt->bindParam(1,$user,PDO::PARAM_STR);
				$stmt->execute();
				while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
					$userTotal[] = new Usuario($row);
				}
				$stmt = null;
				$con = null;
				return $userTotal;
	}//fin metodo

	public function devolverSuperAdministradorLogueado(string $email) :array{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		include_once __DIR__ . '/../../fuente/modelo/superAdministrador.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$user=[];
		$sql = "SELECT superAdministrador.Usuario,superAdministrador.Contrasenia,superAdministrador.IdGrupoUsuario,superAdministrador.Nombre,
			superAdministrador.PrimerApellido,
			superAdministrador.SegundoApellido,superAdministrador.IdCiudad,superAdministrador.Telefono,superAdministrador.Direccion,
			superAdministrador.Nif,
			superAdministrador.Fax,superAdministrador.Email,superAdministrador.Activo
		FROM superAdministrador
		WHERE superAdministrador.Email = ?";
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$email,PDO::PARAM_STR);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			$user[] = new SuperAdministrador($row);
		}
		$stmt = null;
		$con = null;
		return $user;
	}

	//funcion para el telefono
	public function comprobarTelefono(string $tlfno): bool{
		if(!preg_match("/^[0-9]{9}$/", $tlfno)){
			return false;
	    }
	    return true;
    }//fin metodo

	//funcion para comprobar el email
	public function validarEmail(string $eCorreo): bool{
		if (!filter_var($eCorreo, FILTER_VALIDATE_EMAIL)){
			return false;
		}
		return true;
	}//fin metodo

	public function introducirUsuario(string $nickUsuario,string $contrasenia,int $idGrupoUsuario, string $nombre,
		string $primerApellido,string $segundoApellido
		,int $idCiudad,string $telefono,string $direccionUsuario,string $nifUsuario,
		string $faxUsuario,string $emailUsuario) :bool{
		$boolActivo = true;
		$contraseniaCodificada = password_hash($contrasenia, PASSWORD_DEFAULT);//codificarContrasenia, es un string lo que da
		$sql = "INSERT INTO Usuario(
        Usuario, Contrasenia, IdGrupoUsuario, Nombre, PrimerApellido, SegundoApellido, IdCiudad, Telefono, Direccion, Nif,Fax, Email,Activo)
			VALUES(?,?,?,?,?,?,?,?,?,?,?,?);";
		$respuesta = true;
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		try{
		    $con = (new ConexionBaseDatos)->getConexion();
			$con->beginTransaction();
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$nickUsuario,PDO::PARAM_STR);
			$stmt->bindParam(2,$contraseniaCodificada,PDO::PARAM_STR);
			$stmt->bindParam(3,$idGrupoUsuario,PDO::PARAM_INT);
			$stmt->bindParam(4,$nombre,PDO::PARAM_STR);
			$stmt->bindParam(5,$primerApellido,PDO::PARAM_STR);
			$stmt->bindParam(6,$segundoApellido,PDO::PARAM_STR);
			$stmt->bindParam(7,$idCiudad,PDO::PARAM_INT);
			$stmt->bindParam(8,$telefono,PDO::PARAM_STR);
			$stmt->bindParam(9,$direccionUsuario,PDO::PARAM_STR);
			$stmt->bindParam(10,$nifUsuario,PDO::PARAM_STR);
			$stmt->bindParam(11,$faxUsuario,PDO::PARAM_STR);
			$stmt->bindParam(12,$emailUsuario,PDO::PARAM_STR);
			$stmt->bindParam(13,$boolActivo,PDO::PARAM_STR);
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


}//fin clase
