<?php
include_once __DIR__ . "/../Repositorio/administradorTiendaRepositorio.inc";
include_once __DIR__ . "/../Repositorio/superAdministradorRepositorio.inc";
include_once __DIR__ . "/../Repositorio/usuarioRepositorio.inc";
include_once __DIR__ . "/../Repositorio/tiendasRepositorio.inc";
class AdministradorTiendaController
{
	public function inicioAdministradorTienda(){
		$administradorTienda = (new AdministradorTiendaRepositorio)->devolverAdministradoresTiendasPorEmail($_SESSION['userNombre'] );
		include_once __DIR__ . '/../../app/plantillas/administradorTienda/inicioAdministradorTienda.php';
	}//fin metodo

	public function verMiTienda(){
		$idTienda = ($_SESSION['idTienda']);
		$_SESSION['idTienda'] = $idTienda;
		$miTienda = (new TiendasRepositorio())->devolverTiendaIndividual($idTienda);
		include_once __DIR__ .'/../../app/plantillas/administradorTienda/verMiTienda.php';
	}//fin metodo

	public function administrarAlmacenAdministradorTienda(){
		$idTienda = ($_SESSION['idTienda']);
		$_SESSION['idTienda'] = $idTienda;
		include_once __DIR__ .'/../../app/plantillas/administradorTienda/administrarAlmacenAdministradorTienda.php';
	}//fin metodo

	public function modificarMiPerfilAdministradorTienda(){
		$user = $_SESSION['userNombre'];
		$idTienda = ($_SESSION['idTienda']);
		$administradorTienda = (new AdministradorTiendaRepositorio)->devolverAdministradoresTiendasPorEmail($_SESSION['userNombre'] );
		$ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($administradorTienda[0]->getIdCiudad());
		include_once __DIR__ .'/../../app/plantillas/administradorTienda/modificarMiPerfilAdministradorTienda.php';
	}//fin metodo

	public function modificarMiPerfilAdministradorTiendaAdministrador(){
		$boolUSER = false;
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
						$idTienda = (int)$_POST['idTienda'];
						//comprobamos que los datos de correo y telefono sean correctos
						if(!(new UsuarioRepositorio)->comprobarTelefono($tlfnoUsuario)){
							$error = "El campo teléfono debe tener nueve número y no contener letras";
						}elseif(!(new UsuarioRepositorio)->validarEmail($eCorreoUsuario)){
							$error = "El email debe ser correcto";
						}else{
							//hay que insertar primero el correo si este ha sido modificado por las restricciones en el grupo usuarioRepositorio
							if($emailAntiguo != $eCorreoUsuario){
								$cambiarCorreo = (new SuperAdministradorRepositorio())->cambiarCorreoUsuario($eCorreoUsuario,$emailAntiguo);
							}
							$insercion = (new AdministradorTiendaRepositorio)->modificarAdministradorTienda($nickUsuario,$nombreUsuario,$apellidos1,$apellidos2,$direccionUsuario
								,$IdCiudadUsuario,$tlfnoUsuario,$nifUsuario,$eCorreoUsuario,$faxUsuario,$emailAntiguo,$contraseniaUsuarioNUEVA,$contraseniaUsuarioVIEJA
								);
							if(!$insercion){
								$administradorTienda = (new SuperAdministradorRepositorio())->devolverAdministradorTiendaIndividual($_POST['eCorreoUsuario']);
								$ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($administradorTienda[0]->getIdCiudad());
								$tiendaAdministrador = (new SuperAdministradorRepositorio())->devolverTiendaAdministrador($administradorTienda[0]->getIdTienda());
								$error =  "El administrador de tienda acaba de ser modificado";
								$boolUSER = true;
							}else{
								$administradorTienda = (new SuperAdministradorRepositorio())->devolverAdministradorTiendaIndividual($_POST['emailAntiguo']);
								$ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($administradorTienda[0]->getIdCiudad());
								$tiendaAdministrador = (new SuperAdministradorRepositorio())->devolverTiendaAdministrador($administradorTienda[0]->getIdTienda());
								$error =  "El administrador de tienda no ha podido ser modificado";
								$boolUSER = false;
							}
						}
				}

			}
			if($boolUSER){
						$administradorTienda = (new SuperAdministradorRepositorio())->devolverAdministradorTiendaIndividual($_POST['eCorreoUsuario']);
						$ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($administradorTienda[0]->getIdCiudad());
			}else{
						$administradorTienda = (new SuperAdministradorRepositorio())->devolverAdministradorTiendaIndividual($_POST['emailAntiguo']);
						$ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($administradorTienda[0]->getIdCiudad());
			}
			$tiendaTotal = (new TiendasRepositorio())->devolverTiendasTotales();


		}
		include_once __DIR__ . "/../../app/plantillas/administradorTienda/modificarMiPerfilAdministradorTienda.php";
}//fin metodo

}//fin clase
?>
