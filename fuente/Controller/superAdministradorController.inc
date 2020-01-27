<?php
include_once __DIR__ . "/../Repositorio/superAdministradorRepositorio.inc";
include_once __DIR__ . "/../Repositorio/usuarioRepositorio.inc";
include_once __DIR__ . "/../Repositorio/tiendasRepositorio.inc";
include_once __DIR__ . "/../Repositorio/detallesVentaRepositorio.inc";
include_once __DIR__ . "/../Repositorio/reservaRepositorio.inc";
class SuperAdministradorController
{
	//esta funcion es pra el inicio
	public function inicioAdministrador(){
		include_once __DIR__ . '/../../app/plantillas/administrador/inicioAdministrador.php';
	}//fin metodo


	public function administrarUsuarios(){
		$listaUsuarios = (new SuperAdministradorRepositorio())->devolverTodosUsuarios();
		include_once __DIR__ . '/../../app/plantillas/administrador/administrarUsuarios.php';
	}//fin metodo

	public function administrarUsuariosRegistrados(){
		$listaUsuarios = (new SuperAdministradorRepositorio())->devolverUsuarios();
		include_once __DIR__ . '/../../app/plantillas/administrador/administrarUsuariosRegistrados.php';
	}//fin metodo

	public function administrarAdministradoresTiendas(){
		$listaUsuarios = (new SuperAdministradorRepositorio())->devolverAdministradoresTiendas();
		include_once __DIR__ . '/../../app/plantillas/administrador/administrarAdministradoresTiendas.php';
	}//fin metodo

	public function administrarSuperAdministradores(){
		$listaUsuarios = (new SuperAdministradorRepositorio())->devolverSuperAdministradores();
		include_once __DIR__ . '/../../app/plantillas/administrador/administrarSuperAdministradores.php';
	}//fin metodo

	public function borrarUsuarios(){
		//primero comprobamos que el usuario no tenga compras asignadas
		$booleanComprobarComprasUsuarios = (new DetallesVentaRepositorio)->comprobarUsuarioTieneCompras($_GET['email']);
		if(!$booleanComprobarComprasUsuarios){
				$boolean = (new SuperAdministradorRepositorio())->borrarUsuarios($_GET['email']);
				$error =  'El usuario ha sido borrado';
		}else{
				$error =  'El usuario tiene compras asignadas y no puede ser borrado';
		}

		if($_GET['redireccion'] == 'listaCompleta'){
			$listaUsuarios = (new SuperAdministradorRepositorio())->devolverTodosUsuarios();
		include_once __DIR__ . '/../../app/plantillas/administrador/administrarUsuarios.php';
		}elseif($_GET['redireccion'] == 'listaIndividual'){
			$listaUsuarios = (new SuperAdministradorRepositorio())->devolverUsuarios();
			include_once __DIR__ . '/../../app/plantillas/administrador/administrarUsuariosRegistrados.php';
		}
	}//fin metodo

	public function borrarSuperadministrador(){
		$boolean = (new SuperAdministradorRepositorio())->borrarSuperadministrador($_GET['email']);
		$error =  'El superadministrador ha sido borrado';
		if($_GET['redireccion'] == 'listaCompleta'){
			$listaUsuarios = (new SuperAdministradorRepositorio())->devolverTodosUsuarios();
			include_once __DIR__ . '/../../app/plantillas/administrador/administrarUsuarios.php';
		}elseif($_GET['redireccion'] == 'listaIndividual'){
			$listaUsuarios = (new SuperAdministradorRepositorio())->devolverSuperAdministradores();
			include_once __DIR__ . '/../../app/plantillas/administrador/administrarSuperAdministradores.php';
		}
	}//fin metodo

	public function borrarAdministrador(){
		//primero miramos si la tienda administrada tenia mas administradores y si no la desactivamos
		$sacarIdTiendaAdm =  (new TiendasRepositorio())->sacarIdTiendaAdm($_GET['email']);
		$numAdministradoresTienda =  (new TiendasRepositorio())->devolverNumeroAdministradoresTienda($sacarIdTiendaAdm);
		if($numAdministradoresTienda < 2){
				$desactivarTienda =  (new TiendasRepositorio())->desactivarTiendaAsignada( $sacarIdTiendaAdm);
		}
		//ahora borramos
		$boolean = (new SuperAdministradorRepositorio())->borrarAdministrador($_GET['email']);
		$error =  'El administrador de tienda ha sido borrado';
		if($_GET['redireccion'] == 'listaCompleta'){
			$listaUsuarios = (new SuperAdministradorRepositorio())->devolverTodosUsuarios();
			include_once __DIR__ . '/../../app/plantillas/administrador/administrarUsuarios.php';
		}elseif($_GET['redireccion'] == 'listaIndividual'){
			$listaUsuarios = (new SuperAdministradorRepositorio())->devolverAdministradoresTiendas();
			include_once __DIR__ . '/../../app/plantillas/administrador/administrarAdministradoresTiendas.php';
		}
	}//fin metodo

	public function cambiarEstadoUsuario(){
		$boolean = (new SuperAdministradorRepositorio())->cambiarEstadoUsuario($_GET['email'],$_GET['estado']);
		if($_GET['redireccion'] == 'listaCompleta'){
			$listaUsuarios = (new SuperAdministradorRepositorio())->devolverTodosUsuarios();
			include_once __DIR__ . '/../../app/plantillas/administrador/administrarUsuarios.php';
		}elseif($_GET['redireccion'] == 'listaIndividual'){
			$listaUsuarios = (new SuperAdministradorRepositorio())->devolverUsuarios();
			include_once __DIR__ . '/../../app/plantillas/administrador/administrarUsuariosRegistrados.php';
		}
	}//fin metodo

	public function cambiarEstadoAdministradorTienda(){
		$boolean = (new SuperAdministradorRepositorio())->cambiarEstadoAdministradorTienda($_GET['email'],$_GET['estado']);
		if($_GET['redireccion'] == 'listaCompleta'){
			$listaUsuarios = (new SuperAdministradorRepositorio())->devolverTodosUsuarios();
			include_once __DIR__ . '/../../app/plantillas/administrador/administrarUsuarios.php';
		}elseif($_GET['redireccion'] == 'listaIndividual'){
			$listaUsuarios = (new SuperAdministradorRepositorio())->devolverAdministradoresTiendas();
			include_once __DIR__ . '/../../app/plantillas/administrador/administrarAdministradoresTiendas.php';
		}
	}//fin metodo

	public function cambiarEstadoSuperAdministrador(){
		$boolean = (new SuperAdministradorRepositorio())->cambiarEstadoSuperAdministrador($_GET['email'],$_GET['estado']);
		if($_GET['redireccion'] == 'listaCompleta'){
			$listaUsuarios = (new SuperAdministradorRepositorio())->devolverTodosUsuarios();
			include_once __DIR__ . '/../../app/plantillas/administrador/administrarUsuarios.php';
		}elseif($_GET['redireccion'] == 'listaIndividual'){
			$listaUsuarios = (new SuperAdministradorRepositorio())->devolverSuperAdministradores();
			include_once __DIR__ . '/../../app/plantillas/administrador/administrarSuperAdministradores.php';
		}
	}//fin metodo

	public function verUsuarioIndividual(){
		$usuario = (new SuperAdministradorRepositorio())->devolverUsuario($_GET['email']);
		$ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($usuario[0]->getIdCiudad());
		include_once __DIR__ . '/../../app/plantillas/administrador/verUsuarioIndividual.php';
	}//fin metodo

	public function verAdministradorTiendaIndividual(){
		$usuario = (new SuperAdministradorRepositorio())->devolverAdministradorTiendaIndividual($_GET['email']);
		$ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($usuario[0]->getIdCiudad());
		$usuarioSacado = $usuario[0];
		$tiendaAdministrador = (new SuperAdministradorRepositorio())->devolverTiendaAdministrador($usuarioSacado->getIdTienda());
		include_once __DIR__ . '/../../app/plantillas/administrador/verAdministradorTiendaIndividual.php';
	}//fin metodo

	public function verSuperAdministrador(){
		$usuario = (new SuperAdministradorRepositorio())->devolverAdministradorSuper($_GET['email']);
		$ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($usuario[0]->getIdCiudad());
		include_once __DIR__ . '/../../app/plantillas/administrador/verSuperAdministrador.php';
	}//fin metodo

	public function modificarSuperAdministrador(){
		$superAdministrador = (new SuperAdministradorRepositorio())->devolverAdministradorSuper($_GET['email']);
		$ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($superAdministrador[0]->getIdCiudad());
		include_once __DIR__ . '/../../app/plantillas/administrador/modificarSuperAdministrador.php';
	}//fin metodo

	public function modificarMiPerfilSuperAdministrador(){
		$email = (new SuperAdministradorRepositorio())->devolverEmailSuperAdministrador($_SESSION['userNombre']);
		$superAdministrador = (new SuperAdministradorRepositorio())->devolverAdministradorSuper($email);
		$ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($superAdministrador[0]->getIdCiudad());
		include_once __DIR__ . '/../../app/plantillas/administrador/modificarMiPerfilSuperAdministrador.php';
	}//fin metodo

	public function enviarDatosModificacionSuperAdministrador(){
		$boolUser = false;
		if($_SERVER['REQUEST_METHOD']=='POST'){
			if(empty($_POST['nickUsuario']) && isset($_POST['nickUsuario'])){
				$error = 'Falta un nick de Usuario';
			}elseif(empty($_POST['nombreUsuario']) && isset($_POST['nombreUsuario'])){
				$error =  'Falta un nombre de Usuario';
			}elseif(empty($_POST['apellidos1']) && isset($_POST['apellidos1'])){
				$error =  'Falta el primer apellido de Usuario';
			}elseif(empty($_POST['apellidos2']) && isset($_POST['apellidos2'])){
				$error =  'Falta el segundo apellido de Usuario';
			}elseif(empty($_POST['direccionUsuario']) && isset($_POST['direccionUsuario'])){
				$error =  'Falta la direccion de Usuario';
			}elseif(empty($_POST['municipio']) && isset($_POST['municipio'])){
				$error =  'Falta un ciudad de Usuario';
			}elseif(empty($_POST['tlfnoUsuario']) && isset($_POST['tlfnoUsuario'])){
				$error =  'Falta un teléfono de usuario';
			}elseif(empty($_POST['nifUsuario']) && isset($_POST['nifUsuario'])){
				$error =  'Falta el nif de Usuario';
			}elseif(empty($_POST['eCorreoUsuario']) && isset($_POST['eCorreoUsuario'])){
				$error =  'Falta un correo o email de usuario';
			}elseif(empty($_POST['faxUsuario']) && isset($_POST['faxUsuario'])){
				$error =  'Falta un fax de usuario';
			}elseif(empty($_POST['faxUsuario']) && isset($_POST['faxUsuario'])){
				$error =  'Falta un fax de usuario';
			}else{
				$booleanDniFormato =(new UsuarioRepositorio())->comprobarFormatoDni($_POST['nifUsuario']);///comprobar dni valido
				$booleanDniValido =(new UsuarioRepositorio())->validarDni($_POST['nifUsuario']);///comprobar dni valido
				$booleanTelefono =(new UsuarioRepositorio())->comprobarTelefono($_POST['tlfnoUsuario']);//devolvera false si no es correcto
				$booleanEmail =(new UsuarioRepositorio())->validarEmail($_POST['eCorreoUsuario']);//devolvera false si no es correcto

				$arrayDNIsinElMio = (new SuperAdministradorRepositorio())->devolverArrayDNIsinMio($_POST['emailAntiguo']);
				$arrayNicksinElMio = (new SuperAdministradorRepositorio())->devolverArrayNicksinMio($_POST['emailAntiguo']);
				$arrayEmailsinElMio = (new SuperAdministradorRepositorio())->devolverArrayEmailsinMio($_POST['emailAntiguo']);

				$booleanDniDuplicado =(new SuperAdministradorRepositorio())->comprobarDniRepetidoModificacion($arrayDNIsinElMio,$_POST['nifUsuario']);///comprobar dni no duplicado
				$booleanNickDuplicado =(new SuperAdministradorRepositorio())->comprobarDniRepetidoModificacion($arrayNicksinElMio,$_POST['nickUsuario']);///comprobar dni no duplicado
				$booleanEmailDuplicado =(new SuperAdministradorRepositorio())->comprobarDniRepetidoModificacion($arrayEmailsinElMio,$_POST['eCorreoUsuario']);///comprobar dni no duplicado



				if(!$booleanDniFormato){
					$error = "El formato del nif del usuario no es valido";
				}elseif(!$booleanDniValido){
					$error = "El nif del usuario no es valido";
				}elseif(!$booleanTelefono){
						$error = "El campo teléfono debe tener nueve número y no contener letras";
				}elseif(!$booleanEmail){
						$error = "El email debe ser correcto, con @ y acabado en .es o .com";
				}
				elseif(!$booleanDniDuplicado){
						$error = "El dni está duplicado ya que lo usa otro usuario";
				}
				elseif(!$booleanNickDuplicado){
						$error = "El nick de usuario está duplicado ya que lo usa otro usuario";
				}
				elseif(!$booleanEmailDuplicado){
						$error = "El email de usuario está duplicado ya que lo usa otro usuario";
				}
				else{
							////los datos son correctos
							$nickUsuario = $_POST['nickUsuario'];
							$nombreUsuario = $_POST['nombreUsuario'];
							$apellidos1 = $_POST['apellidos1'];
							$apellidos2 = $_POST['apellidos2'];
							$direccionUsuario = $_POST['direccionUsuario'];
							$IdCiudadUsuario = (int)$_POST['municipio'];
							$tlfnoUsuario = $_POST['tlfnoUsuario'];
							$nifUsuario = $_POST['nifUsuario'];
							$eCorreoUsuario = $_POST['eCorreoUsuario'];
							$faxUsuario = $_POST['faxUsuario'];
							$emailAntiguo = $_POST['emailAntiguo'];//el mail que tenia antes
							$contraseniaUsuarioNUEVA = $_POST['contraseniaUsuarioNUEVA'];
							$contraseniaUsuarioVIEJA =$_POST['contraseniaUsuarioVIEJA'];
							//comprobamos que los datos de correo y telefono sean correctos
							if(!(new UsuarioRepositorio)->comprobarTelefono($tlfnoUsuario)){
								$error = "El campo teléfono debe tener nueve número y no contener letras";$superAdministrador = (new SuperAdministradorRepositorio())->devolverAdministradorSuper($_POST['correoUsuario']);
							}elseif(!(new UsuarioRepositorio)->validarEmail($eCorreoUsuario)){
								$error = "El email debe ser correcto";$superAdministrador = (new SuperAdministradorRepositorio())->devolverAdministradorSuper($_POST['correoUsuario']);
							}else{
								//hay que insertar primero el correo si este ha sido modificado por las restricciones en el grupo usuarioRepositorio
								if($emailAntiguo != $eCorreoUsuario){
									$cambiarCorreo = (new SuperAdministradorRepositorio())->cambiarCorreoUsuario($eCorreoUsuario,$emailAntiguo);
								}
								$insercion = (new SuperAdministradorRepositorio)->modificarSuperAdministrador($nickUsuario,$nombreUsuario,$apellidos1,$apellidos2,$direccionUsuario
													 ,$IdCiudadUsuario,$tlfnoUsuario,$nifUsuario,$eCorreoUsuario,$faxUsuario,$emailAntiguo,$contraseniaUsuarioNUEVA,$contraseniaUsuarioVIEJA);
								if(!$insercion){
									$error =  "El Super administrador acaba de ser modificado";
									$superAdministrador = (new SuperAdministradorRepositorio())->devolverAdministradorSuper($_POST['eCorreoUsuario']);
									$ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($superAdministrador[0]->getIdCiudad());
									$boolUser = true;
								}else{
									$error =  "El Super administrador no ha podido ser modificado";
									$superAdministrador = (new SuperAdministradorRepositorio())->devolverAdministradorSuper($_POST['emailAntiguo']);
									$ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($superAdministrador[0]->getIdCiudad());
									$boolUser = false;
								}
							}
				}

			}
			if($boolUser){
					$superAdministrador = (new SuperAdministradorRepositorio())->devolverAdministradorSuper($_POST['eCorreoUsuario']);
			}else{
					$superAdministrador = (new SuperAdministradorRepositorio())->devolverAdministradorSuper($_POST['emailAntiguo']);
			}

			$ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($superAdministrador[0]->getIdCiudad());
			$IdCiudadUsuario = $superAdministrador[0]->getIdCiudad();
		}
		$redireccion = $_POST['redireccion'];
		include_once __DIR__ . "/../../app/plantillas/administrador/modificarSuperAdministrador.php";
	}//fin metodo

	public function modificarUsuario(){
		$usuario = (new SuperAdministradorRepositorio())->devolverUsuario($_GET['email']);
		$ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($usuario[0]->getIdCiudad());
		include_once __DIR__ . '/../../app/plantillas/administrador/modificarUsuario.php';
	}//fin metodo

	public function enviarDatosModificacionUsuario(){
		$boolUser = false;
		if($_SERVER['REQUEST_METHOD']=='POST'){
			if(empty($_POST['nickUsuario']) && isset($_POST['nickUsuario'])){
				$error = 'Falta un nick de Usuario';
			}elseif(empty($_POST['nombreUsuario']) && isset($_POST['nombreUsuario'])){
				$error =  'Falta un nombre de Usuario';
			}elseif(empty($_POST['apellidos1']) && isset($_POST['apellidos1'])){
				$error =  'Falta el primer apellido de Usuario';
			}elseif(empty($_POST['apellidos2']) && isset($_POST['apellidos2'])){
				$error =  'Falta el segundo apellido de Usuario';
			}elseif(empty($_POST['direccionUsuario']) && isset($_POST['direccionUsuario'])){
				$error =  'Falta la direccion de Usuario';
			}elseif(empty($_POST['municipio']) && isset($_POST['municipio'])){
				$error =  'Falta un ciudad de Usuario';
			}elseif(empty($_POST['tlfnoUsuario']) && isset($_POST['tlfnoUsuario'])){
				$error =  'Falta un teléfono de usuario';
			}elseif(empty($_POST['nifUsuario']) && isset($_POST['nifUsuario'])){
				$error =  'Falta el nif de Usuario';
			}elseif(empty($_POST['eCorreoUsuario']) && isset($_POST['eCorreoUsuario'])){
				$error =  'Falta un correo o email de usuario';
			}else{
				$booleanDniFormato =(new UsuarioRepositorio())->comprobarFormatoDni($_POST['nifUsuario']);///comprobar dni valido
				$booleanDniValido =(new UsuarioRepositorio())->validarDni($_POST['nifUsuario']);///comprobar dni valido
				$booleanTelefono =(new UsuarioRepositorio())->comprobarTelefono($_POST['tlfnoUsuario']);//devolvera false si no es correcto
				$booleanEmail =(new UsuarioRepositorio())->validarEmail($_POST['eCorreoUsuario']);//devolvera false si no es correcto

				$arrayDNIsinElMio = (new SuperAdministradorRepositorio())->devolverArrayDNIsinMio($_POST['emailAntiguo']);
				$arrayNicksinElMio = (new SuperAdministradorRepositorio())->devolverArrayNicksinMio($_POST['emailAntiguo']);
				$arrayEmailsinElMio = (new SuperAdministradorRepositorio())->devolverArrayEmailsinMio($_POST['emailAntiguo']);

				$booleanDniDuplicado =(new SuperAdministradorRepositorio())->comprobarDniRepetidoModificacion($arrayDNIsinElMio,$_POST['nifUsuario']);///comprobar dni no duplicado
				$booleanNickDuplicado =(new SuperAdministradorRepositorio())->comprobarDniRepetidoModificacion($arrayNicksinElMio,$_POST['nickUsuario']);///comprobar dni no duplicado
				$booleanEmailDuplicado =(new SuperAdministradorRepositorio())->comprobarDniRepetidoModificacion($arrayEmailsinElMio,$_POST['eCorreoUsuario']);///comprobar dni no duplicado


				if(!$booleanDniFormato){
					$error = "El formato del nif del usuario no es valido";
				}elseif(!$booleanDniValido){
					$error = "El nif del usuario no es valido";
				}elseif(!$booleanTelefono){
						$error = "El campo teléfono debe tener nueve número y no contener letras";
				}elseif(!$booleanEmail){
						$error = "El email debe ser correcto, con @ y acabado en .es o .com";
				}
				elseif(!$booleanDniDuplicado){
				 		$error = "El dni está duplicado ya que lo usa otro usuario";
				}
				elseif(!$booleanNickDuplicado){
				 		$error = "El nick de usuario está duplicado ya que lo usa otro usuario";
				}
				elseif(!$booleanEmailDuplicado){
				 		$error = "El email de usuario está duplicado ya que lo usa otro usuario";
				}
				else{
							////los datos son correctos
							$nickUsuario = $_POST['nickUsuario'];
							$nombreUsuario = $_POST['nombreUsuario'];
							$apellidos1 = $_POST['apellidos1'];
							$apellidos2 = $_POST['apellidos2'];
							$direccionUsuario = $_POST['direccionUsuario'];
							$IdCiudadUsuario = (int)$_POST['municipio'];
							$tlfnoUsuario = $_POST['tlfnoUsuario'];
							$nifUsuario = $_POST['nifUsuario'];
							$eCorreoUsuario = $_POST['eCorreoUsuario'];
							$faxUsuario = $_POST['faxUsuario'];
							$emailAntiguo = $_POST['emailAntiguo'];//el mail que tenia antes
							$contraseniaUsuarioNUEVA = $_POST['contraseniaUsuarioNUEVA'];
							$contraseniaUsuarioVIEJA =$_POST['contraseniaUsuarioVIEJA'];
							//comprobamos que los datos de correo y telefono sean correctos
							if(!(new UsuarioRepositorio)->comprobarTelefono($tlfnoUsuario)){
								$error = "El campo teléfono debe tener nueve número y no contener letras";
							}elseif(!(new UsuarioRepositorio)->validarEmail($eCorreoUsuario)){
								$error = "El email debe ser correcto";
							}
							// elseif(!(new SuperAdministradorRepositorio)->comprobarDniRepetidoModificacion($nifUsuario)){
							// 	$error = "El dni lo tiene otro usuario";
							// }
							else{
								//hay que insertar primero el correo si este ha sido modificado por las restricciones en el grupo usuarioRepositorio
								if($emailAntiguo != $eCorreoUsuario){
									$cambiarCorreo = (new SuperAdministradorRepositorio())->cambiarCorreoUsuario($eCorreoUsuario,$emailAntiguo);
								}
								//antes de la inserción tienes que modificar el usuario de reserva así que guardamos el antiguo nick
								$usuario = (new SuperAdministradorRepositorio())->devolverUsuario($_POST['emailAntiguo']);
								$antiguoUsuario = $usuario[0]->getUsuario();
								$boolModificarUsuarioReserva = (new ReservaRepositorio())->modificarUsuarioReserva($antiguoUsuario,$nickUsuario);
								if($boolModificarUsuarioReserva){
											$insercion = (new SuperAdministradorRepositorio)->modificarUsuario($nickUsuario,$nombreUsuario,$apellidos1,$apellidos2,$direccionUsuario
												,$IdCiudadUsuario,$tlfnoUsuario,$nifUsuario,$eCorreoUsuario,$faxUsuario,$emailAntiguo,$contraseniaUsuarioNUEVA,$contraseniaUsuarioVIEJA);
											if(!$insercion){
												$usuario = (new SuperAdministradorRepositorio())->devolverUsuario($_POST['eCorreoUsuario']);
												$ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($usuario[0]->getIdCiudad());
												$error =  "El usuario acaba de ser modificado";
												$boolUser = true;
											}else{
												$usuario = (new SuperAdministradorRepositorio())->devolverUsuario($_POST['emailAntiguo']);
												$ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($usuario[0]->getIdCiudad());
												$error =  "El usuario no ha podido ser modificado";
												$boolUser = false;
											}
								}else{
										$usuario = (new SuperAdministradorRepositorio())->devolverUsuario($_POST['emailAntiguo']);
										$ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($usuario[0]->getIdCiudad());
										$error =  "El usuario no ha podido ser modificado";
										$boolUser = false;
								}

							}
				}

			}
			if($boolUser){
					$usuario = (new SuperAdministradorRepositorio())->devolverUsuario($_POST['eCorreoUsuario']);
			}else{
					$usuario = (new SuperAdministradorRepositorio())->devolverUsuario($_POST['emailAntiguo']);
			}
			$ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($usuario[0]->getIdCiudad());
		}
		include_once __DIR__ . "/../../app/plantillas/administrador/modificarUsuario.php";
	}//fin metodo

	public function modificarAdministradorTienda(){
		$administradorTienda = (new SuperAdministradorRepositorio())->devolverAdministradorTiendaIndividual($_GET['email']);
		$ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($administradorTienda[0]->getIdCiudad());
		$tiendaAdministrador = (new SuperAdministradorRepositorio())->devolverTiendaAdministrador($administradorTienda[0]->getIdTienda());
		$tiendaTotal = (new TiendasRepositorio())->devolverTiendasTotales();
		include_once __DIR__ . '/../../app/plantillas/administrador/modificarAdministradorTienda.php';
	}//fin metodo

	public function enviarDatosModificacionAdministradorTienda(){
		$boolUser = false;
		if($_SERVER['REQUEST_METHOD']=='POST'){
			if(empty($_POST['nickUsuario']) && isset($_POST['nickUsuario'])){
				$error = 'Falta un nick de Usuario';
			}elseif(empty($_POST['nombreUsuario']) && isset($_POST['nombreUsuario'])){
				$error =  'Falta un nombre de Usuario';
			}elseif(empty($_POST['apellidos1']) && isset($_POST['apellidos1'])){
				$error =  'Falta el primer apellido de Usuario';
			}elseif(empty($_POST['apellidos2']) && isset($_POST['apellidos2'])){
				$error =  'Falta el segundo apellido de Usuario';
			}elseif(empty($_POST['direccionUsuario']) && isset($_POST['direccionUsuario'])){
				$error =  'Falta la direccion de Usuario';
			}elseif(empty($_POST['municipio']) && isset($_POST['municipio'])){
				$error =  'Falta un ciudad de Usuario';
			}elseif(empty($_POST['tlfnoUsuario']) && isset($_POST['tlfnoUsuario'])){
				$error =  'Falta un teléfono de usuario';
			}elseif(empty($_POST['nifUsuario']) && isset($_POST['nifUsuario'])){
				$error =  'Falta el nif de Usuario';
			}elseif(empty($_POST['eCorreoUsuario']) && isset($_POST['eCorreoUsuario'])){
				$error =  'Falta un correo o email de usuario';
			}elseif(empty($_POST['idTienda']) && isset($_POST['idTienda'])){
				$error =  'Falta la tienda asignada';
			}else{
				////los datos son correctos
				$nickUsuario = $_POST['nickUsuario'];
				$nombreUsuario = $_POST['nombreUsuario'];
				$apellidos1 = $_POST['apellidos1'];
				$apellidos2 = $_POST['apellidos2'];
				$direccionUsuario = $_POST['direccionUsuario'];
				$IdCiudadUsuario = (int)$_POST['municipio'];
				$tlfnoUsuario = $_POST['tlfnoUsuario'];
				$nifUsuario = $_POST['nifUsuario'];
				$eCorreoUsuario = $_POST['eCorreoUsuario'];
				$faxUsuario = $_POST['faxUsuario'];
				$emailAntiguo = $_POST['emailAntiguo'];//el mail que tenia antes
				$contraseniaUsuarioNUEVA = $_POST['contraseniaUsuarioNUEVA'];
				$contraseniaUsuarioVIEJA =$_POST['contraseniaUsuarioVIEJA'];
				$idTienda = (int)$_POST['idTienda'];
				//comprobamos que los datos de correo y telefono sean correctos
				if(!(new UsuarioRepositorio)->comprobarTelefono($tlfnoUsuario)){
					$error = "El campo teléfono debe tener nueve número y no contener letras";
				}elseif(!(new UsuarioRepositorio)->validarEmail($eCorreoUsuario)){
					$error = "El email debe ser correcto";
				}else{
							$booleanDniFormato =(new UsuarioRepositorio())->comprobarFormatoDni($_POST['nifUsuario']);///comprobar dni valido
							$booleanDniValido =(new UsuarioRepositorio())->validarDni($_POST['nifUsuario']);///comprobar dni valido
							$booleanTelefono =(new UsuarioRepositorio())->comprobarTelefono($_POST['tlfnoUsuario']);//devolvera false si no es correcto
							$booleanEmail =(new UsuarioRepositorio())->validarEmail($_POST['eCorreoUsuario']);//devolvera false si no es correcto

							$arrayDNIsinElMio = (new SuperAdministradorRepositorio())->devolverArrayDNIsinMio($_POST['emailAntiguo']);
							$arrayNicksinElMio = (new SuperAdministradorRepositorio())->devolverArrayNicksinMio($_POST['emailAntiguo']);
							$arrayEmailsinElMio = (new SuperAdministradorRepositorio())->devolverArrayEmailsinMio($_POST['emailAntiguo']);

							$booleanDniDuplicado =(new SuperAdministradorRepositorio())->comprobarDniRepetidoModificacion($arrayDNIsinElMio,$_POST['nifUsuario']);///comprobar dni no duplicado
							$booleanNickDuplicado =(new SuperAdministradorRepositorio())->comprobarDniRepetidoModificacion($arrayNicksinElMio,$_POST['nickUsuario']);///comprobar dni no duplicado
							$booleanEmailDuplicado =(new SuperAdministradorRepositorio())->comprobarDniRepetidoModificacion($arrayEmailsinElMio,$_POST['eCorreoUsuario']);///comprobar dni no duplicado

							if(!$booleanDniFormato){
								$error = "El formato del nif del usuario no es valido";
							}elseif(!$booleanDniValido){
								$error = "El nif del usuario no es valido";
							}elseif(!$booleanTelefono){
									$error = "El campo teléfono debe tener nueve número y no contener letras";
							}elseif(!$booleanEmail){
									$error = "El email debe ser correcto, con @ y acabado en .es o .com";
							}
							elseif(!$booleanDniDuplicado){
									$error = "El dni está duplicado ya que lo usa otro usuario";
							}
							elseif(!$booleanNickDuplicado){
									$error = "El nick de usuario está duplicado ya que lo usa otro usuario";
							}
							elseif(!$booleanEmailDuplicado){
									$error = "El email de usuario está duplicado ya que lo usa otro usuario";
							}
							else{

									//comprobamos que la nueva tienda sea la misma que la anterior
									$sacarIdTiendaAdm =  (new TiendasRepositorio())->sacarIdTiendaAdm($_POST['emailAntiguo']);
									if($sacarIdTiendaAdm != $idTienda){//si es distinta
											//primero miramos si la tienda administrada tenia mas administradores y si no la desactivamos
											$numAdministradoresTienda =  (new TiendasRepositorio())->devolverNumeroAdministradoresTienda($sacarIdTiendaAdm);
											if($numAdministradoresTienda < 2){//si solo tiene 1 o ninguno desactvamos
													$desactivarTienda =  (new TiendasRepositorio())->desactivarTiendaAsignada( $sacarIdTiendaAdm);
											}
									}
									//hay que insertar primero el correo si este ha sido modificado por las restricciones en el grupo usuarioRepositorio
									if($emailAntiguo != $eCorreoUsuario){
										$cambiarCorreo = (new SuperAdministradorRepositorio())->cambiarCorreoUsuario($eCorreoUsuario,$emailAntiguo);
									}
									//Luego modificamos
									$insercion = (new SuperAdministradorRepositorio)->modificarAdministradorTienda($nickUsuario,$nombreUsuario,$apellidos1,$apellidos2,$direccionUsuario
										,$IdCiudadUsuario,$tlfnoUsuario,$nifUsuario,$eCorreoUsuario,$faxUsuario,$emailAntiguo,$contraseniaUsuarioNUEVA,$contraseniaUsuarioVIEJA
										,$idTienda);
									if(!$insercion){
										$administradorTienda = (new SuperAdministradorRepositorio())->devolverAdministradorTiendaIndividual($_POST['eCorreoUsuario']);
										$ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($administradorTienda[0]->getIdCiudad());
										$tiendaAdministrador = (new SuperAdministradorRepositorio())->devolverTiendaAdministrador($administradorTienda[0]->getIdTienda());
										$error =  "El usuario acaba de ser modificado";
										$boolUser = true;
									}else{
										$administradorTienda = (new SuperAdministradorRepositorio())->devolverAdministradorTiendaIndividual($_POST['emailAntiguo']);
										$ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($administradorTienda[0]->getIdCiudad());
										$tiendaAdministrador = (new SuperAdministradorRepositorio())->devolverTiendaAdministrador($administradorTienda[0]->getIdTienda());
										$error =  "El usuario no ha podido ser modificado";
										$boolUser = false;
									}

							}
					}
			}
			$tiendaTotal = (new TiendasRepositorio())->devolverTiendasTotales();

			if($boolUser){
					$administradorTienda = (new SuperAdministradorRepositorio())->devolverAdministradorTiendaIndividual($_POST['eCorreoUsuario']);
			}else{
					$administradorTienda = (new SuperAdministradorRepositorio())->devolverAdministradorTiendaIndividual($_POST['emailAntiguo']);
			}
			$ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($administradorTienda[0]->getIdCiudad());
		}
		include_once __DIR__ . "/../../app/plantillas/administrador/modificarAdministradorTienda.php";
	}//fin metodo

	public function inscribirUsuariosNuevos(){
		if($_SERVER['REQUEST_METHOD']=='POST'){
			if(empty($_POST['tipoUsuario']) && isset($_POST['tipoUsuario'])){
				$error = 'Falta un tipo de Usuario';
			}else{
				$tipoUsuario = (int)$_POST['tipoUsuario'];
				if($tipoUsuario == 3){
					include_once __DIR__ . "/../../app/plantillas/administrador/introducirUsuario.php";
				}
				if($tipoUsuario == 2){
					$tiendaTotal = (new TiendasRepositorio())->devolverTiendasTotales();
					include_once __DIR__ . "/../../app/plantillas/administrador/introducirAdministradorTienda.php";
				}
				if($tipoUsuario == 1){
					include_once __DIR__ . "/../../app/plantillas/administrador/introducirSuperAdministrador.php";
				}
			}
		}
	}//fin metodo

	public function enviarDatosIntroduccionSuperAdministrador(){
		if($_SERVER['REQUEST_METHOD']=='POST'){
			if(empty($_POST['nickUsuario']) && isset($_POST['nickUsuario'])){
				$error = 'Falta un nick de Usuario';
			}elseif(empty($_POST['nombreUsuario']) && isset($_POST['nombreUsuario'])){
				$error =  'Falta un nombre de Usuario';
			}elseif(empty($_POST['apellidos1']) && isset($_POST['apellidos1'])){
				$error =  'Falta el primer apellido de Usuario';
			}elseif(empty($_POST['apellidos2']) && isset($_POST['apellidos2'])){
				$error =  'Falta el segundo apellido de Usuario';
			}elseif(empty($_POST['direccionUsuario']) && isset($_POST['direccionUsuario'])){
				$error =  'Falta la direccion de Usuario';
			}elseif(empty($_POST['municipio']) && isset($_POST['municipio'])){
				$error =  'Falta un ciudad de Usuario';
			}elseif(empty($_POST['tlfnoUsuario']) && isset($_POST['tlfnoUsuario'])){
				$error =  'Falta un teléfono de usuario';
			}elseif(empty($_POST['nifUsuario']) && isset($_POST['nifUsuario'])){
				$error =  'Falta el nif de Usuario';
			}elseif(empty($_POST['eCorreoUsuario']) && isset($_POST['eCorreoUsuario'])){
				$error =  'Falta un correo o email de usuario';
			}else{
				////los datos son correctos
				$nickUsuario = $_POST['nickUsuario'];
				$nombreUsuario = $_POST['nombreUsuario'];
				$apellidos1 = $_POST['apellidos1'];
				$apellidos2 = $_POST['apellidos2'];
				$direccionUsuario = $_POST['direccionUsuario'];
				$IdCiudadUsuario = (int)$_POST['municipio'];
				$tlfnoUsuario = $_POST['tlfnoUsuario'];
				$nifUsuario = $_POST['nifUsuario'];
				$eCorreoUsuario = $_POST['eCorreoUsuario'];
				$faxUsuario = $_POST['faxUsuario'];
				$contraseniaUsuarioNUEVA = $_POST['contraseniaUsuarioNUEVA'];
				$tipoUsuario = (int)$_POST['tipoUsuario'];
				$activo = true;
				//comprobamos que los datos de correo y telefono sean correctos
				if(!(new UsuarioRepositorio)->comprobarTelefono($tlfnoUsuario)){
					$error = "El campo teléfono debe tener nueve número y no contener letras";
				}elseif(!(new UsuarioRepositorio)->validarEmail($eCorreoUsuario)){
					$error = "El email debe ser correcto";
				}elseif(!(new UsuarioRepositorio)->validarDni($nifUsuario)){
					$error = "El dni debe ser correcto";
				}elseif(!(new UsuarioRepositorio)->comprobarFormatoDni($nifUsuario)){
					$error = "El dni debe ser correcto";
				}elseif((new SuperAdministradorRepositorio)->comprobarUsuarioExisteSuperAdministrador($nickUsuario)){
					$error = "El nick lo usa otro usuario";
				}elseif(!(new SuperAdministradorRepositorio)->comprobarDniRepetidoSuperAdministrador($nifUsuario)){
					$error = "El dni lo usa otro usuario";
				}elseif((new SuperAdministradorRepositorio)->comprobarEmailExisteSuperAdministrador($eCorreoUsuario)){
					$error = "El email lo usa otro usuario";
				}else{//primero hay que introducir el grupo y luego el usuario
					$insercionUser = (new SuperAdministradorRepositorio)->enviarDatosIntroduccionSuperAdministrador($nickUsuario,$contraseniaUsuarioNUEVA,
					$tipoUsuario,$nombreUsuario,$apellidos1,$apellidos2,$IdCiudadUsuario,$tlfnoUsuario,$direccionUsuario,$nifUsuario
					,$faxUsuario,$eCorreoUsuario,$activo);
					if(!$insercionUser){
						$error =  "El super administrador acaba de ser introducido";
					}else{
						$error =  "El super administrador no ha podido ser introducido";
					}
				}
			}
		}
		$listaUsuarios = (new SuperAdministradorRepositorio())->devolverTodosUsuarios();
		include_once __DIR__ . '/../../app/plantillas/administrador/administrarUsuarios.php';
	}//fin metodo

	public function enviarDatosIntroduccionUsuario(){
		if($_SERVER['REQUEST_METHOD']=='POST'){
			if(empty($_POST['nickUsuario']) && isset($_POST['nickUsuario'])){
				$error = 'Falta un nick de Usuario';
			}elseif(empty($_POST['nombreUsuario']) && isset($_POST['nombreUsuario'])){
				$error =  'Falta un nombre de Usuario';
			}elseif(empty($_POST['apellidos1']) && isset($_POST['apellidos1'])){
				$error =  'Falta el primer apellido de Usuario';
			}elseif(empty($_POST['apellidos2']) && isset($_POST['apellidos2'])){
				$error =  'Falta el segundo apellido de Usuario';
			}elseif(empty($_POST['direccionUsuario']) && isset($_POST['direccionUsuario'])){
				$error =  'Falta la direccion de Usuario';
			}elseif(empty($_POST['municipio']) && isset($_POST['municipio'])){
				$error =  'Falta un ciudad de Usuario';
			}elseif(empty($_POST['tlfnoUsuario']) && isset($_POST['tlfnoUsuario'])){
				$error =  'Falta un teléfono de usuario';
			}elseif(empty($_POST['nifUsuario']) && isset($_POST['nifUsuario'])){
				$error =  'Falta el nif de Usuario';
			}elseif(empty($_POST['eCorreoUsuario']) && isset($_POST['eCorreoUsuario'])){
				$error =  'Falta un correo o email de usuario';
			}else{
				////los datos son correctos
				$nickUsuario = $_POST['nickUsuario'];
				$nombreUsuario = $_POST['nombreUsuario'];
				$apellidos1 = $_POST['apellidos1'];
				$apellidos2 = $_POST['apellidos2'];
				$direccionUsuario = $_POST['direccionUsuario'];
				$IdCiudadUsuario = (int)$_POST['municipio'];
				$tlfnoUsuario = $_POST['tlfnoUsuario'];
				$nifUsuario = $_POST['nifUsuario'];
				$eCorreoUsuario = $_POST['eCorreoUsuario'];
				$faxUsuario = $_POST['faxUsuario'];
				$contraseniaUsuarioNUEVA = $_POST['contraseniaUsuarioNUEVA'];
				$tipoUsuario = (int)$_POST['tipoUsuario'];
				$activo = true;
				//comprobamos que los datos de correo y telefono sean correctos
				if(!(new UsuarioRepositorio)->comprobarTelefono($tlfnoUsuario)){
					$error = "El campo teléfono debe tener nueve número y no contener letras";
				}elseif(!(new UsuarioRepositorio)->validarEmail($eCorreoUsuario)){
					$error = "El email debe ser correcto";
				}elseif(!(new UsuarioRepositorio)->comprobarFormatoDni($nifUsuario)){
					$error = "El dni debe ser correcto";
				}elseif(!(new UsuarioRepositorio)->validarDni($nifUsuario)){
					$error = "El dni debe ser correcto";
				}elseif((new UsuarioRepositorio)->comprobarEmailExisteUsuario($eCorreoUsuario)){
					$error = "El mail lo tiene otro usuario";
				}elseif((new UsuarioRepositorio)->comprobarUsuarioExiste($nickUsuario)){
					$error = "El nick lo tiene otro usuario";
				}else{//primero hay que introducir el grupo y luego el usuario
							if((new UsuarioRepositorio())->comprobarDniRepetido($_POST['nifUsuario'])){
							$insercionUser = (new SuperAdministradorRepositorio)->enviarDatosIntroduccionUsuario($nickUsuario,$contraseniaUsuarioNUEVA,
							$tipoUsuario,$nombreUsuario,$apellidos1,$apellidos2,$IdCiudadUsuario,$tlfnoUsuario,$direccionUsuario,$nifUsuario
							,$faxUsuario,$eCorreoUsuario,$activo);
									if(!$insercionUser  ){
										$error =  "El usuario acaba de ser introducido";
									}else{
										$error =  "El usuario no ha podido ser introducido";
									}
							}else{
									$error =  "El usuario ha introducido un nif repetido";
							}
				}
			}
		}
		$listaUsuarios = (new SuperAdministradorRepositorio())->devolverTodosUsuarios();
		include_once __DIR__ . '/../../app/plantillas/administrador/administrarUsuarios.php';
	}//fin metodo

	public function enviarDatosIntroduccionAdministradorTienda(){
        if($_SERVER['REQUEST_METHOD']=='POST'){
			if(empty($_POST['nickUsuario']) && isset($_POST['nickUsuario'])){
				$error = 'Falta un nick de Usuario';
			}elseif(empty($_POST['nombreUsuario']) && isset($_POST['nombreUsuario'])){
				$error =  'Falta un nombre de Usuario';
			}elseif(empty($_POST['apellidos1']) && isset($_POST['apellidos1'])){
				$error =  'Falta el primer apellido de Usuario';
			}elseif(empty($_POST['apellidos2']) && isset($_POST['apellidos2'])){
				$error =  'Falta el segundo apellido de Usuario';
			}elseif(empty($_POST['direccionUsuario']) && isset($_POST['direccionUsuario'])){
				$error =  'Falta la direccion de Usuario';
			}elseif(empty($_POST['municipio']) && isset($_POST['municipio'])){
				$error =  'Falta un ciudad de Usuario';
			}elseif(empty($_POST['tlfnoUsuario']) && isset($_POST['tlfnoUsuario'])){
				$error =  'Falta un teléfono de usuario';
			}elseif(empty($_POST['nifUsuario']) && isset($_POST['nifUsuario'])){
				$error =  'Falta el nif de Usuario';
			}elseif(empty($_POST['eCorreoUsuario']) && isset($_POST['eCorreoUsuario'])){
				$error =  'Falta un correo o email de usuario';
			}elseif(empty($_POST['idTienda']) && isset($_POST['idTienda'])){
				$error =  'No has elegiddo tienda';
			}else{
				////los datos son correctos
				$nickUsuario = $_POST['nickUsuario'];
				$nombreUsuario = $_POST['nombreUsuario'];
				$apellidos1 = $_POST['apellidos1'];
				$apellidos2 = $_POST['apellidos2'];
				$direccionUsuario = $_POST['direccionUsuario'];
				$IdCiudadUsuario = (int)$_POST['municipio'];
				$tlfnoUsuario = $_POST['tlfnoUsuario'];
				$nifUsuario = $_POST['nifUsuario'];
				$eCorreoUsuario = $_POST['eCorreoUsuario'];
				$faxUsuario = $_POST['faxUsuario'];
				$contraseniaUsuarioNUEVA = $_POST['contraseniaUsuarioNUEVA'];
				$tipoUsuario = (int)$_POST['tipoUsuario'];
				$idTienda = (int)$_POST['idTienda'];
				$activo = true;
         //comprobamos que los datos de correo y telefono sean correctos
				 if(!(new UsuarioRepositorio)->comprobarTelefono($tlfnoUsuario)){
 					$error = "El campo teléfono debe tener nueve número y no contener letras";
 				}elseif(!(new UsuarioRepositorio)->validarEmail($eCorreoUsuario)){
 					$error = "El email debe ser correcto";
 				}elseif(!(new UsuarioRepositorio)->validarDni($nifUsuario)){
 					$error = "El dni debe ser correcto";
 				}elseif(!(new UsuarioRepositorio)->comprobarFormatoDni($nifUsuario)){
 					$error = "El dni debe ser correcto";
 				}elseif((new SuperAdministradorRepositorio)->comprobarUsuarioExisteAdministradorTienda($nickUsuario)){
 					$error = "El nick lo usa otro usuario";
 				}elseif(!(new SuperAdministradorRepositorio)->comprobarDniRepetidoAdministradorTienda($nifUsuario)){
 					$error = "El dni lo usa otro usuario";
 				}elseif((new SuperAdministradorRepositorio)->comprobarEmailExisteAdministradorTienda($eCorreoUsuario)){
 					$error = "El email lo usa otro usuario";
 				}else{//primero hay que introducir el grupo y luego el usuario
								if((new UsuarioRepositorio())->comprobarDniRepetido($_POST['nifUsuario'])){
										$insercionUser = (new SuperAdministradorRepositorio)->enviarDatosIntroduccionAdministradorTienda($nickUsuario,$contraseniaUsuarioNUEVA,
										$tipoUsuario,$nombreUsuario,$apellidos1,$apellidos2,$IdCiudadUsuario,$tlfnoUsuario,$direccionUsuario,$nifUsuario
										,$faxUsuario,$eCorreoUsuario,$activo,$idTienda);
										if(!$insercionUser){
												$ponerTrueTiendaAsignada = (new TiendasRepositorio())->activarTiendaAsignada($idTienda);
												$error =  "El usuario acaba de ser introducido";
										}else{
												$error =  "El usuario no ha podido ser introducido";
										}
								}else{
										$error = "Hay otro usuario que tiene el mismo nif";
								}

            }
			}
		}
		$listaUsuarios = (new SuperAdministradorRepositorio())->devolverTodosUsuarios();
		include_once __DIR__ . '/../../app/plantillas/administrador/administrarUsuarios.php';
	}//fin metodo


	public function opcionesBorrarLibro(){
			if($_SERVER['REQUEST_METHOD']=='GET'){
					$idLibro = $_GET['idLibro'];
					$idEjemplar = $_GET['idEjemplar'];
					$tiendaTotal = (new TiendasRepositorio())->devolverTiendasTotales();
			}
			include_once __DIR__ . '/../../app/plantillas/administrador/opcionesBorrarLibro.php';
	}//fin metodo

}//fin clase
?>
