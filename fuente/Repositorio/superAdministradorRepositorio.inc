<?php

class SuperAdministradorRepositorio
{
	public function devolverTodosUsuarios() :array{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		include_once __DIR__ . '/../../fuente/modelo/usuario.inc';
		include_once __DIR__ . '/../../fuente/modelo/administradorTienda.inc';
		include_once __DIR__ . '/../../fuente/modelo/superAdministrador.inc';
		$usuario = [];$administrador = [];;$administradorTienda  = [];$listaUsuarios = [];

		$con1 = (new ConexionBaseDatos)->getConexion();
		$sql1 = "SELECT Usuario, Contrasenia,IdGrupoUsuario,Nombre,PrimerApellido,SegundoApellido,IdCiudad,Telefono,Direccion,Nif,Fax,Email,Activo FROM Usuario;";
		$stmt1 = $con1->prepare($sql1);
		$stmt1->execute();
		while($row = $stmt1->fetch(PDO::FETCH_ASSOC)){
			  $usuario[] = new Usuario($row);
		}
        $con1 = null;
        $stmt1 = null;

        $con2 = (new ConexionBaseDatos)->getConexion();
        $sql2 = "SELECT Usuario, Contrasenia,IdGrupoUsuario,Nombre,PrimerApellido,SegundoApellido,IdCiudad,Telefono,Direccion,Nif,Fax,Email,IdTienda,Activo FROM AdministradorTienda;";
		$stmt2 = $con2->prepare($sql2);
		$stmt2->execute();
		while($row = $stmt2->fetch(PDO::FETCH_ASSOC)){
			  $administradorTienda[] = new AdministradorTienda($row);
		}
        $con2 = null;
	    $stmt2 = null;

        $con3 = (new ConexionBaseDatos)->getConexion();
        $sql3 = "SELECT Usuario, Contrasenia,IdGrupoUsuario,Nombre,PrimerApellido,SegundoApellido,IdCiudad,Telefono,Direccion,Nif,Fax,Email,Activo FROM SuperAdministrador;";
		$stmt3 = $con3->prepare($sql3);
		$stmt3->execute();
		while($row = $stmt3->fetch(PDO::FETCH_ASSOC)){
			  $administrador[] = new SuperAdministrador($row);
		}
        $con3 = null;
		$stmt3 = null;

        $listaUsuarios = [
            'Usuario' => $usuario,
            'AdministradorTienda' => $administradorTienda,
            'SuperAdministrador' => $administrador
        ];
        return $listaUsuarios;
	}//fin metodo

	public function devolverUsuarios() :array{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		include_once __DIR__ . '/../../fuente/modelo/usuario.inc';
		$usuario = [];
		$con = (new ConexionBaseDatos)->getConexion();
		$sql = "SELECT Usuario, Contrasenia,IdGrupoUsuario,Nombre,PrimerApellido,SegundoApellido,IdCiudad,Telefono,Direccion,Nif,Fax,Email,Activo FROM Usuario;";
		$stmt = $con->prepare($sql);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			$usuario[] = new Usuario($row);
		}
		$con = null;
		$stmt = null;
		return $usuario;
	}//fin metodo

	public function devolverAdministradoresTiendas() :array{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		include_once __DIR__ . '/../../fuente/modelo/administradorTienda.inc';
		$usuario = [];
		$con = (new ConexionBaseDatos)->getConexion();
		$sql = "SELECT Usuario, Contrasenia,IdGrupoUsuario,Nombre,PrimerApellido,SegundoApellido,IdCiudad,Telefono,Direccion,Nif,Fax,Email,IdTienda,Activo FROM AdministradorTienda;";
		$stmt = $con->prepare($sql);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			$usuario[] = new AdministradorTienda($row);
		}
		$con = null;
		$stmt = null;
		return $usuario;
	}//fin metodo

	public function devolverSuperAdministradores() :array{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		include_once __DIR__ . '/../../fuente/modelo/superAdministrador.inc';
		$usuario = [];
		$con = (new ConexionBaseDatos)->getConexion();
		$sql = "SELECT Usuario, Contrasenia,IdGrupoUsuario,Nombre,PrimerApellido,SegundoApellido,IdCiudad,Telefono,Direccion,Nif,Fax,Email,Activo FROM SuperAdministrador;";
		$stmt = $con->prepare($sql);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			$usuario[] = new SuperAdministrador($row);
		}
		$con = null;
		$stmt = null;
		return $usuario;
	}//fin metodo

	public function borrarUsuarios(string $email) :bool{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$boolBorrado = false;
		$sql = "DELETE FROM Usuario WHERE Email = ? ";
		try{
			$con->beginTransaction();
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$email,PDO::PARAM_STR);
			if($stmt->execute()){
				$boolBorrado = true;
			}else{
				$boolBorrado = false;
			}
			$con->commit();
			return $boolBorrado;
		}catch(PDOException $ex){
			throw $ex;
			$con->rollBack();
		}finally{
			$stmt = null;
			$con = null;
		}
	}//fin metodo

	public function borrarSuperadministrador(string $email) :bool{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$boolBorrado = false;
		$sql = "DELETE FROM SuperAdministrador WHERE Email = ? ";
		try{
			$con->beginTransaction();
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$email,PDO::PARAM_STR);
			if($stmt->execute()){
				$boolBorrado = true;
			}else{
				$boolBorrado = false;
			}
			$con->commit();
			return $boolBorrado;
		}catch(PDOException $ex){
			throw $ex;
			$con->rollBack();
		}finally{
			$stmt = null;
			$con = null;
		}
	}//fin metodo

	public function borrarAdministrador(string $email) :bool{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$boolBorrado = false;
		$sql = "DELETE FROM AdministradorTienda WHERE Email = ? ";
		try{
			$con->beginTransaction();
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$email,PDO::PARAM_STR);
			if($stmt->execute()){
				$boolBorrado = true;
			}else{
				$boolBorrado = false;
			}
			$con->commit();
			return $boolBorrado;
		}catch(PDOException $ex){
			throw $ex;
			$con->rollBack();
		}finally{
			$stmt = null;
			$con = null;
		}
	}//fin metodo

	public function devolverUsuario(string $email) :array{
		$usuario = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		include_once __DIR__ . '/../../fuente/modelo/usuario.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$sql = "SELECT Usuario,Contrasenia,IdGrupoUsuario,Nombre,PrimerApellido,SegundoApellido,IdCiudad,Telefono,Direccion,Nif,Fax,Email,Activo FROM usuario WHERE Email = ?;";
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$email,PDO::PARAM_STR);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			$usuario[] = new Usuario($row);
		}
		$con = null;
		$stmt = null;
		return $usuario;
  }//fin metodo

	public function devolverAdministradorTiendaIndividual(string $email) :array{
		$usuario = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		include_once __DIR__ . '/../../fuente/modelo/administradorTienda.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$sql = "SELECT Usuario,Contrasenia,IdGrupoUsuario,Nombre,PrimerApellido,SegundoApellido,IdCiudad,Telefono,Direccion,Nif,Fax,Email,Activo,IdTienda FROM AdministradorTienda WHERE Email = ?;";
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$email,PDO::PARAM_STR);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			$usuario[] = new AdministradorTienda($row);
		}
		$con = null;
		$stmt = null;
		return $usuario;
	}//fin metodo

	public function devolverAdministradorSuper(string $email) :array{
		$usuario = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		include_once __DIR__ . '/../../fuente/modelo/superAdministrador.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$sql = "SELECT Usuario,Contrasenia,IdGrupoUsuario,Nombre,PrimerApellido,SegundoApellido,IdCiudad,Telefono,Direccion,Nif,Fax,Email,Activo
			FROM superAdministrador WHERE Email = ?;";
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$email,PDO::PARAM_STR);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			$usuario[] = new SuperAdministrador($row);
		}
		$con = null;
		$stmt = null;
		return $usuario;
	}//fin metodo

	public function devolverCiudadUsuario(string $email) :string{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$ciudad='';
		$sql = "SELECT DISTINCT NombreCiudad FROM Ciudades
			JOIN Usuario ON Usuario.IdCiudad = Ciudades.IdCiudad
			JOIN administradorTienda ON administradorTienda.IdCiudad = Ciudades.IdCiudad
			JOIN SuperAdministrador ON SuperAdministrador.IdCiudad = Ciudades.IdCiudad
			WHERE Usuario.Email = ? OR administradorTienda.Email = ? OR SuperAdministrador.Email = ?; ";
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$email,PDO::PARAM_STR);
		$stmt->bindParam(2,$email,PDO::PARAM_STR);
		$stmt->bindParam(3,$email,PDO::PARAM_STR);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			$ciudad =  $row['NombreCiudad'];
		}
		$stmt = null;
		$con = null;
		return $ciudad;
	}//fin metodo

	public function devolverCiudadUsuarioPorId(int $id) :string{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$ciudad='';
		$sql = "SELECT DISTINCT NombreCiudad FROM Ciudades WHERE Ciudades.IdCiudad = ?;";
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$id,PDO::PARAM_INT);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			$ciudad =  $row['NombreCiudad'];
		}
		$stmt = null;
		$con = null;
		return $ciudad;
	}//fin metodo

	public function devolverIdCiudadUsuario(string $email) :int{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$id = 0;
		$sql = "SELECT DISTINCT Ciudades.IdCiudad as ID_CIUDAD FROM Ciudades
			JOIN Usuario ON Usuario.IdCiudad = Ciudades.IdCiudad
			JOIN administradorTienda ON administradorTienda.IdCiudad = Ciudades.IdCiudad
			JOIN SuperAdministrador ON SuperAdministrador.IdCiudad = Ciudades.IdCiudad
			WHERE Usuario.Email = ? OR administradorTienda.Email = ? OR SuperAdministrador.Email = ?;";
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$email,PDO::PARAM_STR);
		$stmt->bindParam(2,$email,PDO::PARAM_STR);
		$stmt->bindParam(3,$email,PDO::PARAM_STR);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			$id =  $row['ID_CIUDAD'];
		}
		$stmt = null;
		$con = null;
		return $id;
	}//fin metodo

	public function devolverIdProvinciaUsuario(string $email) :int{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$id = 0;
		$sql = "SELECT DISTINCT Provincias.IdProvincia as ID_PROVINCIA FROM Provincias
				JOIN Ciudades ON Ciudades.IdProvincia = Provincias.IdProvincia
				JOIN Usuario ON Usuario.IdCiudad = Ciudades.IdCiudad
				JOIN administradorTienda ON administradorTienda.IdCiudad = Ciudades.IdCiudad
				JOIN SuperAdministrador ON SuperAdministrador.IdCiudad = Ciudades.IdCiudad
				WHERE Usuario.Email = ? OR administradorTienda.Email = ?
				OR SuperAdministrador.Email = ?;";
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$email,PDO::PARAM_STR);
		$stmt->bindParam(2,$email,PDO::PARAM_STR);
		$stmt->bindParam(3,$email,PDO::PARAM_STR);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			$id =  $row['ID_PROVINCIA'];
		}
		$stmt = null;
		$con = null;
		return $id;
	}//fin metodo

	public function devolverProvinciaUsuario(string $email) :string{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$provincia='';
		$sql = "SELECT DISTINCT NombreProvincia  FROM Provincias
			JOIN Ciudades ON Ciudades.IdProvincia = Provincias.IdProvincia
			JOIN Usuario ON Usuario.IdCiudad = Ciudades.IdCiudad
			JOIN administradorTienda ON administradorTienda.IdCiudad = Ciudades.IdCiudad
			JOIN SuperAdministrador ON SuperAdministrador.IdCiudad = Ciudades.IdCiudad
			WHERE Usuario.Email = ? OR administradorTienda.Email = ?
			OR SuperAdministrador.Email = ?;";
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$email,PDO::PARAM_STR);
		$stmt->bindParam(2,$email,PDO::PARAM_STR);
		$stmt->bindParam(3,$email,PDO::PARAM_STR);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			$provincia =  $row['NombreProvincia'];
		}
		$stmt = null;
		$con = null;
		return $provincia;
	}//fin metodo/

	public function devolverTiendaAdministrador(int $idTienda) :string{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$tienda='';
		$sql = "SELECT Nombre FROM Tiendas WHERE Tiendas.IdTienda = ?; ";
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$idTienda,PDO::PARAM_INT);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			$tienda =  $row['Nombre'];
		}
		$stmt = null;
		$con = null;
		return $tienda;
	}//fin metodo

	public function cambiarEstadoUsuario(string $email,bool $estado) :bool{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$estadoCambiado = '';
		if($estado){
			$estadoCambiado = '0';
		}else{
			$estadoCambiado = '1';
		}
		$sql ="UPDATE usuario SET Activo = ? WHERE Email = ?";
		$con = (new ConexionBaseDatos)->getConexion();
		$bool = false;
		try{
			$con->beginTransaction();
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$estadoCambiado,PDO::PARAM_STR);
			$stmt->bindParam(2,$email,PDO::PARAM_STR);
			if($stmt->execute()){
				$bool = true;
			}
			$con->commit();
			return $bool;
		}catch(PDOException $ex){
			throw $ex;
			$con->rollBack();
		}finally{
			$stmt = null;
			$con = null;
		}
	}//fin metodo

	public function cambiarEstadoAdministradorTienda(string $email,bool $estado) :bool{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$estadoCambiado = '';
		if($estado){
			$estadoCambiado = '0';
		}else{
			$estadoCambiado = '1';
		}
		$sql ="UPDATE AdministradorTienda SET Activo = ? WHERE Email = ?";
		$con = (new ConexionBaseDatos)->getConexion();
		$bool = false;
		try{
			$con->beginTransaction();
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$estadoCambiado,PDO::PARAM_STR);
			$stmt->bindParam(2,$email,PDO::PARAM_STR);
			if($stmt->execute()){
				$bool = true;
			}
			$con->commit();
			return $bool;
		}catch(PDOException $ex){
			throw $ex;
			$con->rollBack();
		}finally{
			$stmt = null;
			$con = null;
		}
	}//fin metodo

	public function cambiarEstadoSuperAdministrador(string $email,bool $estado) :bool{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$estadoCambiado = '';
		if($estado){
			$estadoCambiado = '0';
		}else{
			$estadoCambiado = '1';
		}
		$sql ="UPDATE SuperAdministrador SET Activo = ? WHERE Email = ?";
		$con = (new ConexionBaseDatos)->getConexion();
		$bool = false;
		try{
			$con->beginTransaction();
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$estadoCambiado,PDO::PARAM_STR);
			$stmt->bindParam(2,$email,PDO::PARAM_STR);
			if($stmt->execute()){
				$bool = true;
			}
			$con->commit();
			return $bool;
		}catch(PDOException $ex){
			throw $ex;
			$con->rollBack();
		}finally{
			$stmt = null;
			$con = null;
		}
	}//fin metodo

	//funcion para modificar usuario
	public function modificarUsuario(string $nickUsuario,string $nombreUsuario,string $apellidos1,string $apellidos2,string $direccionUsuario
		,int $IdCiudadUsuario,string $tlfnoUsuario,string $nifUsuario,string $eCorreoUsuario,string $faxUsuario,string $emailAntiguo
		,string $contraseniaUsuarioNUEVA,string $contraseniaUsuarioVIEJA) :bool{
        $respuesta = true;//$emailAntiguo
		$sql ="UPDATE Usuario SET
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

	//funcion para modificar super administrador
	public function modificarSuperAdministrador(string $nickUsuario,string $nombreUsuario,string $apellidos1,string $apellidos2,string $direccionUsuario
		,int $IdCiudadUsuario,string $tlfnoUsuario,string $nifUsuario,string $eCorreoUsuario,string $faxUsuario,string $emailAntiguo
		,string $contraseniaUsuarioNUEVA,string $contraseniaUsuarioVIEJA) :bool{
        $respuesta = true;//$emailAntiguo
		$sql ="UPDATE SuperAdministrador SET
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

	public function modificarAdministradorTienda(string $nickUsuario,string $nombreUsuario,string $apellidos1,string $apellidos2,string $direccionUsuario
		,int $IdCiudadUsuario,string $tlfnoUsuario,string $nifUsuario,string $eCorreoUsuario,string $faxUsuario,string $emailAntiguo
		,string $contraseniaUsuarioNUEVA,string $contraseniaUsuarioVIEJA,int $idTienda) :bool{
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
			IdCiudad = ?,
			IdTienda = ? WHERE Email = ?";
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
			$stmt->bindParam(12,$idTienda,PDO::PARAM_INT);
			$stmt->bindParam(13,$emailAntiguo,PDO::PARAM_STR);
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

	public function enviarDatosIntroduccionSuperAdministrador(string $nickUsuario,string $contraseniaUsuarioNUEVA,int $tipoUsuario,string $nombreUsuario
		,string $apellidos1,string $apellidos2,int $IdCiudadUsuario,string $tlfnoUsuario,string $direccionUsuario,string $nifUsuario
		,string $faxUsuario,string $email,bool $activo){
		$respuesta = true;
		$contraseniaCodificada = password_hash($contraseniaUsuarioNUEVA, PASSWORD_DEFAULT);//codificarContrasenia, es un string lo que da
		$sql ="INSERT INTO SuperAdministrador(Usuario,Contrasenia,IdGrupoUsuario,Nombre,PrimerApellido,SegundoApellido,IdCiudad,Telefono,Direccion,Nif,Fax,Email,Activo)
			VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?)";
        include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
        try{
            $con = (new ConexionBaseDatos)->getConexion();
            $con->beginTransaction();
            $stmt = $con->prepare($sql);
            $stmt->bindParam(1,$nickUsuario,PDO::PARAM_STR);
            $stmt->bindParam(2,$contraseniaCodificada,PDO::PARAM_STR);
            $stmt->bindParam(3,$tipoUsuario,PDO::PARAM_INT);
            $stmt->bindParam(4,$nombreUsuario,PDO::PARAM_STR);
            $stmt->bindParam(5,$apellidos1,PDO::PARAM_STR);
            $stmt->bindParam(6,$apellidos2,PDO::PARAM_STR);
            $stmt->bindParam(7,$IdCiudadUsuario,PDO::PARAM_INT);
            $stmt->bindParam(8,$tlfnoUsuario,PDO::PARAM_STR);
            $stmt->bindParam(9,$direccionUsuario,PDO::PARAM_STR);
            $stmt->bindParam(10,$nifUsuario,PDO::PARAM_STR);
            $stmt->bindParam(11,$faxUsuario,PDO::PARAM_STR);
            $stmt->bindParam(12,$email,PDO::PARAM_STR);
            $stmt->bindParam(13,$activo,PDO::PARAM_STR);
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


    public function enviarDatosIntroduccionUsuario(string $nickUsuario,string $contraseniaUsuarioNUEVA,int $tipoUsuario,string $nombreUsuario
		,string $apellidos1,string $apellidos2,int $IdCiudadUsuario,string $tlfnoUsuario,string $direccionUsuario,string $nifUsuario
		,string $faxUsuario,string $email,bool $activo){
		$respuesta = true;
		$contraseniaCodificada = password_hash($contraseniaUsuarioNUEVA, PASSWORD_DEFAULT);//codificarContrasenia, es un string lo que da
		$sql ="INSERT INTO Usuario(Usuario,Contrasenia,IdGrupoUsuario,Nombre,PrimerApellido,SegundoApellido,IdCiudad,Telefono,Direccion,Nif,Fax,Email,Activo)
			VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?)";
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		try{
			$con = (new ConexionBaseDatos)->getConexion();
			$con->beginTransaction();
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$nickUsuario,PDO::PARAM_STR);
			$stmt->bindParam(2,$contraseniaCodificada,PDO::PARAM_STR);
			$stmt->bindParam(3,$tipoUsuario,PDO::PARAM_INT);
			$stmt->bindParam(4,$nombreUsuario,PDO::PARAM_STR);
			$stmt->bindParam(5,$apellidos1,PDO::PARAM_STR);
			$stmt->bindParam(6,$apellidos2,PDO::PARAM_STR);
			$stmt->bindParam(7,$IdCiudadUsuario,PDO::PARAM_INT);
			$stmt->bindParam(8,$tlfnoUsuario,PDO::PARAM_STR);
			$stmt->bindParam(9,$direccionUsuario,PDO::PARAM_STR);
			$stmt->bindParam(10,$nifUsuario,PDO::PARAM_STR);
			$stmt->bindParam(11,$faxUsuario,PDO::PARAM_STR);
			$stmt->bindParam(12,$email,PDO::PARAM_STR);
			$stmt->bindParam(13,$activo,PDO::PARAM_STR);
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

	public function enviarDatosIntroduccionAdministradorTienda(string $nickUsuario,string $contraseniaUsuarioNUEVA,int $tipoUsuario,string $nombreUsuario
		,string $apellidos1,string $apellidos2,int $IdCiudadUsuario,string $tlfnoUsuario,string $direccionUsuario,string $nifUsuario
		,string $faxUsuario,string $email,bool $activo,int $idTienda){
		$respuesta = true;
		$contraseniaCodificada = password_hash($contraseniaUsuarioNUEVA, PASSWORD_DEFAULT);//codificarContrasenia, es un string lo que da
		$sql ="INSERT INTO AdministradorTienda(Usuario,Contrasenia,IdGrupoUsuario,Nombre,PrimerApellido,SegundoApellido,IdCiudad,Telefono,Direccion,Nif,
			Fax,Email,IdTienda,Activo) VALUES(?,?,?,?,?,?,?,?,?,?,?,?,?,?)";
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		try{
			$con = (new ConexionBaseDatos)->getConexion();
			$con->beginTransaction();
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$nickUsuario,PDO::PARAM_STR);
			$stmt->bindParam(2,$contraseniaCodificada,PDO::PARAM_STR);
			$stmt->bindParam(3,$tipoUsuario,PDO::PARAM_INT);
			$stmt->bindParam(4,$nombreUsuario,PDO::PARAM_STR);
			$stmt->bindParam(5,$apellidos1,PDO::PARAM_STR);
			$stmt->bindParam(6,$apellidos2,PDO::PARAM_STR);
			$stmt->bindParam(7,$IdCiudadUsuario,PDO::PARAM_INT);
			$stmt->bindParam(8,$tlfnoUsuario,PDO::PARAM_STR);
			$stmt->bindParam(9,$direccionUsuario,PDO::PARAM_STR);
			$stmt->bindParam(10,$nifUsuario,PDO::PARAM_STR);
			$stmt->bindParam(11,$faxUsuario,PDO::PARAM_STR);
			$stmt->bindParam(12,$email,PDO::PARAM_STR);
			$stmt->bindParam(13,$idTienda,PDO::PARAM_INT);
			$stmt->bindParam(14,$activo,PDO::PARAM_STR);
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

	public function devolverEmailSuperAdministrador(string $nick) :string{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$email = true;
		$sql = "SELECT email   FROM SuperAdministrador WHERE usuario  = ?";
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$nick,PDO::PARAM_STR);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
				$email = $row['email'];
		}
		$stmt = null;
		$con = null;
		return $email;
	}//fin metodo

	public function cambiarCorreoUsuario(string $eCorreoUsuario,string $emailAntiguo) :bool{
		$respuesta = true;
		$sql ="UPDATE Usuario SET Email = ? WHERE Email = ?";
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		try{
			$con = (new ConexionBaseDatos)->getConexion();
			$con->beginTransaction();
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$eCorreoUsuario,PDO::PARAM_STR);
			$stmt->bindParam(2,$emailAntiguo,PDO::PARAM_STR);
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

	public function comprobarEmailExisteAdministradorTienda(string $email) :bool{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$comprobarUsuario = false;$sql = "SELECT AdministradorTienda.Email FROM AdministradorTienda WHERE AdministradorTienda.Email = ?;";
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


	public function comprobarUsuarioExisteAdministradorTienda(string $usuario) :bool{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$comprobarUsuario = false;
		$sql = "SELECT AdministradorTienda.usuario AS USER_NICK  FROM AdministradorTienda WHERE AdministradorTienda.usuario = ?;";
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

	public function comprobarDniRepetidoAdministradorTienda(string $dni) :bool{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$ComprobarDniRepetido = true;
		$sql = "SELECT COUNT(AdministradorTienda.Nif) AS CONTADOR FROM AdministradorTienda WHERE AdministradorTienda.Nif = ?";
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

	public function comprobarEmailExisteSuperAdministrador(string $email) :bool{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$comprobarUsuario = false;$sql = "SELECT SuperAdministrador.Email FROM SuperAdministrador WHERE SuperAdministrador.Email = ?;";
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


	public function comprobarUsuarioExisteSuperAdministrador(string $usuario) :bool{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$comprobarUsuario = false;
		$sql = "SELECT SuperAdministrador.usuario AS USER_NICK  FROM SuperAdministrador WHERE SuperAdministrador.usuario = ?;";
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

	public function comprobarDniRepetidoSuperAdministrador(string $dni) :bool{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$ComprobarDniRepetido = true;
		$sql = "SELECT COUNT(SuperAdministrador.Nif) AS CONTADOR FROM SuperAdministrador WHERE SuperAdministrador.Nif = ?";
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

	public function devolverArrayDNIsinMio(string $email) :array{
				$usuarioDni = [];
				include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
				///PONGO LOS DE USUARIO
				$con1 = (new ConexionBaseDatos)->getConexion();
				$sql1 = "SELECT Nif FROM Usuario WHERE Email != ?;";
				$stmt1 = $con1->prepare($sql1);
				$stmt1->bindParam(1,$email,PDO::PARAM_STR);
				$stmt1->execute();
				while($row1 = $stmt1->fetch(PDO::FETCH_ASSOC)){
					$usuarioDni[] = $row1['Nif'];
				}
				$con1 = null;
				$stmt1 = null;
				///PONGO LOS DE ADMINISTRADOR TIENDA
				$con2 = (new ConexionBaseDatos)->getConexion();
				$sql2 = "SELECT Nif FROM AdministradorTienda WHERE Email != ?;";
				$stmt2 = $con2->prepare($sql2);
				$stmt2->bindParam(1,$email,PDO::PARAM_STR);
				$stmt2->execute();
				while($row2 = $stmt2->fetch(PDO::FETCH_ASSOC)){
					$usuarioDni[] = $row2['Nif'];
				}
				$con2 = null;
				$stmt2 = null;
				///PONGO LOS DE SUPERADMINISTRADOR
				$con3 = (new ConexionBaseDatos)->getConexion();
				$sql3 = "SELECT Nif FROM SuperAdministrador WHERE Email != ?;";
				$stmt3 = $con3->prepare($sql3);
				$stmt3->bindParam(1,$email,PDO::PARAM_STR);
				$stmt3->execute();
				while($row3 = $stmt3->fetch(PDO::FETCH_ASSOC)){
					$usuarioDni[] = $row3['Nif'];
				}
				$con3 = null;
				$stmt3 = null;

				return $usuarioDni;
	}//fin metodo

	public function devolverArrayNicksinMio(string $email) :array{
				$usuarioNick = [];
				include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
				///PONGO LOS DE USUARIO
				$con1 = (new ConexionBaseDatos)->getConexion();
				$sql1 = "SELECT Usuario FROM Usuario WHERE Email != ?;";
				$stmt1 = $con1->prepare($sql1);
				$stmt1->bindParam(1,$email,PDO::PARAM_STR);
				$stmt1->execute();
				while($row1 = $stmt1->fetch(PDO::FETCH_ASSOC)){
					$usuarioNick[] = $row1['Usuario'];
				}
				$con1 = null;
				$stmt1 = null;
				///PONGO LOS DE ADMINISTRADOR TIENDA
				$con2 = (new ConexionBaseDatos)->getConexion();
				$sql2 = "SELECT Usuario FROM AdministradorTienda WHERE Email != ?;";
				$stmt2 = $con2->prepare($sql2);
				$stmt2->bindParam(1,$email,PDO::PARAM_STR);
				$stmt2->execute();
				while($row2 = $stmt2->fetch(PDO::FETCH_ASSOC)){
					$usuarioNick[] = $row2['Usuario'];
				}
				$con2 = null;
				$stmt2 = null;
				///PONGO LOS DE SUPERADMINISTRADOR
				$con3 = (new ConexionBaseDatos)->getConexion();
				$sql3 = "SELECT Usuario FROM SuperAdministrador WHERE Email != ?;";
				$stmt3 = $con3->prepare($sql3);
				$stmt3->bindParam(1,$email,PDO::PARAM_STR);
				$stmt3->execute();
				while($row3 = $stmt3->fetch(PDO::FETCH_ASSOC)){
					$usuarioNick[] = $row3['Usuario'];
				}
				$con3 = null;
				$stmt3 = null;

				return $usuarioNick;
	}//fin metodo

	public function devolverArrayEmailsinMio(string $email) :array{
				$usuarioEmail = [];
				include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
				///PONGO LOS DE USUARIO
				$con1 = (new ConexionBaseDatos)->getConexion();
				$sql1 = "SELECT Email FROM Usuario WHERE Email != ?;";
				$stmt1 = $con1->prepare($sql1);
				$stmt1->bindParam(1,$email,PDO::PARAM_STR);
				$stmt1->execute();
				while($row1 = $stmt1->fetch(PDO::FETCH_ASSOC)){
					$usuarioEmail[] = $row1['Email'];
				}
				$con1 = null;
				$stmt1 = null;
				///PONGO LOS DE ADMINISTRADOR TIENDA
				$con2 = (new ConexionBaseDatos)->getConexion();
				$sql2 = "SELECT Email FROM AdministradorTienda WHERE Email != ?;";
				$stmt2 = $con2->prepare($sql2);
				$stmt2->bindParam(1,$email,PDO::PARAM_STR);
				$stmt2->execute();
				while($row2 = $stmt2->fetch(PDO::FETCH_ASSOC)){
					$usuarioEmail[] = $row2['Email'];
				}
				$con2 = null;
				$stmt2 = null;
				///PONGO LOS DE SUPERADMINISTRADOR
				$con3 = (new ConexionBaseDatos)->getConexion();
				$sql3 = "SELECT Email FROM SuperAdministrador WHERE Email != ?;";
				$stmt3 = $con3->prepare($sql3);
				$stmt3->bindParam(1,$email,PDO::PARAM_STR);
				$stmt3->execute();
				while($row3 = $stmt3->fetch(PDO::FETCH_ASSOC)){
					$usuarioEmail[] = $row3['Email'];
				}
				$con3 = null;
				$stmt3 = null;

				return $usuarioEmail;
	}//fin metodo


	public function comprobarDniRepetidoModificacion(array $arrayDNIsinElMio, string $dni) :bool{
		$ComprobarDniRepetido = true;
		foreach ($arrayDNIsinElMio as $key => $value) {
				$dni = strtoupper($dni);//pasamos a mayuscula para la comprobacion
				$value = strtoupper($value);//pasamos a mayuscula para la comprobacion
				if($value == $dni){
					$ComprobarDniRepetido = false;
				}
		}
		return $ComprobarDniRepetido;
	}//fin metodo

	public function comprobarUsuarioExisteModificacion(array $arrayNicksinElMio,string $usuario) :bool{
		$comprobarUsuario = true;
		foreach ($arrayNicksinElMio as $key => $value) {
				$usuario = strtoupper($usuario);//pasamos a mayuscula para la comprobacion
				$value = strtoupper($value);//pasamos a mayuscula para la comprobacion
				if($value == $usuario){
					$comprobarUsuario = false;
				}
		}
		return $comprobarUsuario;
	}//fin metodo


	public function comprobarEmailExisteUsuarioModificacion(array $arrayEmailsinElMio, string $email) :bool{
			$comprobarUsuario = true;
			foreach ($arrayEmailsinElMio as $key => $value) {
					$email = strtoupper($email);//pasamos a mayuscula para la comprobacion
					$value = strtoupper($value);//pasamos a mayuscula para la comprobacion
					if($value == $email){
						$comprobarUsuario = false;
					}
			}
			return $comprobarUsuario;
	}//fin metodo


}//FIN CLASE
?>
