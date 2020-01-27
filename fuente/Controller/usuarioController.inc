<?php
include_once __DIR__ . "/../Repositorio/usuarioRepositorio.inc";
include_once __DIR__ . "/../Repositorio/superAdministradorRepositorio.inc";
include_once __DIR__ . "/../Repositorio/librosRepositorio.inc";
include_once __DIR__ . "/../Repositorio/administradorTiendaRepositorio.inc";
include_once __DIR__ . "/../Repositorio/provinciasRepositorio.inc";
include_once __DIR__ . "/../Repositorio/ciudadesRepositorio.inc";
class UsuarioController
{
    //este metodo te dirige a la pagina inicio
    public function inicio(){
        include_once __DIR__ . '/../../app/plantillas/visitante/inicio.php';
    }//fin metodo

    public function inicioUsuario(){
        include_once __DIR__ . '/../../app/plantillas/usuario/inicioUsuario.php';
    }//fin metodo



    public function inicioUsuarioComprobar(){
		$librosPaginaPrincipal = (new LibrosRepositorio)->mostrarlibrosPaginaPrincipal();//es un multarray de 2
		$comprobarContraseniaUsuario = true;
		if($_SERVER['REQUEST_METHOD']=='POST'){
      $usuarioActual = $_POST['usuarioActual'];
			if(empty($_POST['email']) && isset($_POST['email'])){
    				$error = 'Falta el campo usuario email';
            if($usuarioActual == 'usuario'){
                include_once __DIR__ . '/../../app/plantillas/usuario/inicioUsuario.php';
            }
            if($usuarioActual == 'administradorTienda'){
                include_once __DIR__ . '/../../app/plantillas/administradorTienda/inicioAdministradorTienda.php';
            }
            if($usuarioActual == 'superAdministrador'){
                include_once __DIR__ . '/../../app/plantillas/administrador/inicioAdministrador.php';
            }
            if($usuarioActual == 'visitante'){
                include_once __DIR__ . "/../../app/plantillas/visitante/inicio.php";
            }
    			}elseif(empty($_POST['password']) && isset($_POST['password'])){
    				$error =  'Falta el campo contraseña';
            if($usuarioActual == 'usuario'){
                include_once __DIR__ . '/../../app/plantillas/usuario/inicioUsuario.php';
            }
            if($usuarioActual == 'administradorTienda'){
                include_once __DIR__ . '/../../app/plantillas/administradorTienda/inicioAdministradorTienda.php';
            }
            if($usuarioActual == 'superAdministrador'){
                include_once __DIR__ . '/../../app/plantillas/administrador/inicioAdministrador.php';
            }
            if($usuarioActual == 'visitante'){
                include_once __DIR__ . "/../../app/plantillas/visitante/inicio.php";
            }
			}else{
                $usuarioActual = $_POST['usuarioActual'];
                $tipo =(new UsuarioRepositorio())->devolverTipo($_POST['email'],$_POST['password']);
                if($tipo == 1 || $tipo == 2 || $tipo ==3){
                      if($tipo == 3){
                          $usuario = (new UsuarioRepositorio)->devolverUsuarioLogueado($_POST['email']);
                          if($usuario[0]->getActivo()){//comprobamos que no este dado de baja
                              $_SESSION['userNombre'] = $usuario[0]->getUsuario();
                              $_SESSION['grupoUser'] = 'usuario';
                              $error = 'Bienvenido USUARIO';
                              include_once __DIR__ . '/../../app/plantillas/usuario/inicioUsuario.php';
                          }else{
                              $error = 'La contraseña y email son correctos pero el usuario está dado de baja';
                              if($usuarioActual == 'usuario'){
                                  include_once __DIR__ . '/../../app/plantillas/usuario/inicioUsuario.php';
                              }
                              if($usuarioActual == 'administradorTienda'){
                                  include_once __DIR__ . '/../../app/plantillas/administradorTienda/inicioAdministradorTienda.php';
                              }
                              if($usuarioActual == 'superAdministrador'){
                                  include_once __DIR__ . '/../../app/plantillas/administrador/inicioAdministrador.php';
                              }
                              if($usuarioActual == 'visitante'){
                                  include_once __DIR__ . "/../../app/plantillas/visitante/inicio.php";
                              }
                          }

                      }
                      if($tipo == 2){
                          $_SESSION['userNombre'] = $_POST['email'];
                          $_SESSION['grupoUser'] = 'administradorTienda';
                          $administradorTienda = (new AdministradorTiendaRepositorio)->devolverAdministradoresTiendasPorEmail($_SESSION['userNombre'] );
                          if($administradorTienda[0]->getActivo()){//comprobamos que no este dado de baja
                                $_SESSION['idTienda'] = $administradorTienda[0]->getIdTienda();
                                include_once __DIR__ . "/../Repositorio/tiendasRepositorio.inc";
                                $miTienda = (new TiendasRepositorio())->devolverTiendaIndividual($_SESSION['idTienda']);
                                $nombreTienda = $miTienda[0]->getNombre();
                                $_SESSION['nombreTienda'] = $nombreTienda;
                                $error = 'Bienvenido ADMINISTRADOR DE TIENDA';
                                include_once __DIR__ . '/../../app/plantillas/administradorTienda/inicioAdministradorTienda.php';
                          }else{
                                $error = 'La contraseña y email son correctos pero el usuario está dado de baja';
                                if($usuarioActual == 'usuario'){
                                    include_once __DIR__ . '/../../app/plantillas/usuario/inicioUsuario.php';
                                }
                                if($usuarioActual == 'administradorTienda'){
                                    include_once __DIR__ . '/../../app/plantillas/administradorTienda/inicioAdministradorTienda.php';
                                }
                                if($usuarioActual == 'superAdministrador'){
                                    include_once __DIR__ . '/../../app/plantillas/administrador/inicioAdministrador.php';
                                }
                                if($usuarioActual == 'visitante'){
                                    include_once __DIR__ . "/../../app/plantillas/visitante/inicio.php";
                                }
                          }
                      }
                      if($tipo == 1){
                          $superAdministrador = (new UsuarioRepositorio)->devolverSuperAdministradorLogueado($_POST['email']);
                          if($superAdministrador[0]->getActivo()){//comprobamos que no este dado de baja
                              $_SESSION['userNombre'] = $superAdministrador[0]->getUsuario();
                              $_SESSION['grupoUser'] = 'superAdministrador';
                              $error = 'Bienvenido SUPERADMINISTRADOR ';
                              include_once __DIR__ . '/../../app/plantillas/administrador/inicioAdministrador.php';
                          }else{
                                $error = 'La contraseña y email son correctos pero el usuario está dado de baja';
                                if($usuarioActual == 'usuario'){
                                    include_once __DIR__ . '/../../app/plantillas/usuario/inicioUsuario.php';
                                }
                                if($usuarioActual == 'administradorTienda'){
                                    include_once __DIR__ . '/../../app/plantillas/administradorTienda/inicioAdministradorTienda.php';
                                }
                                if($usuarioActual == 'superAdministrador'){
                                    include_once __DIR__ . '/../../app/plantillas/administrador/inicioAdministrador.php';
                                }
                                if($usuarioActual == 'visitante'){
                                    include_once __DIR__ . "/../../app/plantillas/visitante/inicio.php";
                                }
                          }
                      }
                  }else{ //si la contraseña no es correcta
                          $error = 'El email o la contraseña son incorrectos';
                          if($usuarioActual == 'usuario'){
                              include_once __DIR__ . '/../../app/plantillas/usuario/inicioUsuario.php';
                          }
                          if($usuarioActual == 'administradorTienda'){
                              include_once __DIR__ . '/../../app/plantillas/administradorTienda/inicioAdministradorTienda.php';
                          }
                          if($usuarioActual == 'superAdministrador'){
                              include_once __DIR__ . '/../../app/plantillas/administrador/inicioAdministrador.php';
                          }
                          if($usuarioActual == 'visitante'){
                              include_once __DIR__ . "/../../app/plantillas/visitante/inicio.php";
                          }
                  }
            }
         }
    } //fin metodo

    public function verUltimosVeinteLibrosInicios(){
        $libros20 = (new LibroRepositorio())->vistaUltimosVeinteLibros();
        include_once __DIR__ . '/../../app/plantillas/visitante/inicio.php';
    }//fin metodo

    public function formularioInscripcion(){
        $provincias = (new provinciasRepositorio())->devolverProvincias();
        include_once __DIR__ . '/../../app/plantillas/visitante/formularioInscripcion.php';
    }//fin metodo

    public function inscribirUsuarioNuevo(){
        if($_SERVER['REQUEST_METHOD']=='POST'){
			if(empty($_POST['nickUsuario']) && isset($_POST['nickUsuario'])){
				$error = 'Falta un nick de Usuario';
			}elseif(empty($_POST['contrasenia']) && isset($_POST['contrasenia'])){
				$error =  'Falta una contraseña';
			}elseif(empty($_POST['nombre']) && isset($_POST['nombre'])){
				$error =  'Falta un nombre';
			}elseif(empty($_POST['primerApellido']) && isset($_POST['primerApellido'])){
				$error =  'Falta el primer apellido del usuario';
			}elseif(empty($_POST['segundoApellido']) && isset($_POST['segundoApellido'])){
				$error =  'Falta el segundo apellido del usuario';
			}elseif(empty($_POST['municipio']) && isset($_POST['municipio'])){
				$error =  'Falta la ciudad';
			}elseif(empty($_POST['provincia']) && isset($_POST['provincia'])){
				$error =  'Falta la provincia';
			}elseif(empty($_POST['telefono']) && isset($_POST['telefono'])){
				$error =  'Falta un teléfono de usuario';
			}elseif(empty($_POST['direccionUsuario']) && isset($_POST['direccionUsuario'])){
				$error =  'Falta la direccion de Usuario';
			}elseif(empty($_POST['nifUsuario']) && isset($_POST['nifUsuario'])){
				$error =  'Falta el nif de Usuario';
			}elseif(empty($_POST['emailUsuario']) && isset($_POST['emailUsuario'])){
				$error =  'Falta un correo o email de usuario';
			}else{
				$fax =(string)$_POST['fax'];
				//comprobamos que el telefono Y el mail esten correctos y el usuario y el mail no esten duplicados
				$booleanTelefono =(new UsuarioRepositorio())->comprobarTelefono($_POST['telefono']);//devolvera false si no es correcto
				$booleanEmail =(new UsuarioRepositorio())->validarEmail($_POST['emailUsuario']);//devolvera false si no es correcto
				$booleanEmailExiste =(new UsuarioRepositorio())->comprobarEmailExisteUsuario($_POST['emailUsuario']);//devolvera true si existe
				$booleanUsuarioExiste =(new UsuarioRepositorio())->comprobarUsuarioExiste($_POST['nickUsuario']);//devolvera true si existe
				//comprobamos que el dni este correcto y  no este duplicado
				$booleanDniFormato =(new UsuarioRepositorio())->comprobarFormatoDni($_POST['nifUsuario']);///comprobar dni valido
				$booleanDniValido =(new UsuarioRepositorio())->validarDni($_POST['nifUsuario']);///comprobar dni valido
				$booleanDniDuplicado =(new UsuarioRepositorio())->comprobarDniRepetido($_POST['nifUsuario']);///comprobar dni no duplicado
				if(!$booleanTelefono){
					$error = "El campo teléfono debe tener nueve número y no contener letras";
				}elseif(!$booleanEmail){
					$error = "El email debe ser correcto, con @";
				}elseif($booleanEmailExiste){
					$error = "El email ya está siendo usado por otro usuario";
				}elseif($booleanUsuarioExiste){
					$error = "El nick de usuario ya está siendo usado por otro usuario";
				}elseif(!$booleanDniFormato){
					$error = "El formato del nif del usuario no es valido";
				}elseif(!$booleanDniValido){
					$error = "El nif del usuario no es valido";
				}elseif(!$booleanDniDuplicado){
					$error = "Hay otro usuario que tiene el mismo nif";
				}else{
					$nickUsuario = $_POST['nickUsuario'];//es un string
					$contrasenia = $_POST['contrasenia'];//es un string
					$nombre = $_POST['nombre'];//es un string
					$primerApellido = $_POST['primerApellido'];//es un string
					$segundoApellido = $_POST['segundoApellido'];//es un string
					$municipio = (int)$_POST['municipio'];//es un string
					$provincia = $_POST['provincia'];//es un string
					$telefono = $_POST['telefono'];//es un string
					$direccionUsuario = $_POST['direccionUsuario'];//es un string
					$nifUsuario = $_POST['nifUsuario'];//es un string
					$emailUsuario = $_POST['emailUsuario'];//es un string
					$fax = $_POST['fax'];//es un string
					$idGrupoUsuario = (int)$_POST['idGrupoUsuario'];//es un string
					$grupoUsuario = $_POST['grupoUsuario'];//es un string
					$boolActivo = true;
					if($emailUsuario == $emailUsuario){
						$cambiarCorreo = (new SuperAdministradorRepositorio())->cambiarCorreoUsuario($emailUsuario,$emailUsuario);
					}
					//Introducimos el usuario
					$booleanIntroducirUsuario = (new SuperAdministradorRepositorio)->enviarDatosIntroduccionUsuario($nickUsuario,$contrasenia,
					$idGrupoUsuario,$nombre,$primerApellido,$segundoApellido,$municipio,$telefono,$direccionUsuario,$nifUsuario
					,$fax,$emailUsuario,$boolActivo);
					if(!$booleanIntroducirUsuario){
						$error = ' <h2>TUS DATOS INTRODUCIDOS</h2><br>'.
							"nickUsuario ".$nickUsuario.'<br>'.
							"contrasenia ".$contrasenia.'<br>'.
							"nombre ".$nombre.'<br>'.
							"primerApellido ".$primerApellido.'<br>'.
							"segundoApellido ".$segundoApellido.'<br>'.
							"municipio ".$municipio.'<br>'.///int idciudad
							"provincia ".$provincia.'<br>'.//string provincia
							"telefono ".$telefono.'<br>'.
							"direccionUsuario ".$direccionUsuario.'<br>'.
							" nifUsuario  ".$nifUsuario.'<br>'.
							"emailUsuario".$emailUsuario.'<br>'.
							" fax".$fax.'<br>'.
							"idGrupoUsuario ".$idGrupoUsuario;
							include_once __DIR__ . '/../../app/plantillas/visitante/inscripcionCorrecta.php';
					}else{
						$error = 'El usuario no ha podido ser introducido por algún error.';
					}
				}
			}
        }else{
            $error = 'El usuario no ha podido ser introducido.';
        }
        include_once __DIR__ . '/../../app/plantillas/visitante/formularioInscripcion.php';
    }//fin metodo

    public function contacto(){
		    include_once __DIR__ . '/../../app/plantillas/visitante/contacto.php';
    }//fin metodo

    public function contactoUsuario(){
        include_once __DIR__ . '/../../app/plantillas/usuario/contactoUsuario.php';
    }

    public function enviarMensajeContacto(){
        if($_SERVER['REQUEST_METHOD']=='POST'){
            if(empty($_POST['nombre']) && isset($_POST['nombre'])){
              $error = 'Falta un nombre';
            }elseif(empty($_POST['email']) && isset($_POST['email'])){
              $error = 'Falta un email';
            }elseif(empty($_POST['mensaje']) && isset($_POST['mensaje'])){
              $error = 'Falta un mensaje';
            }else{
                $error = 'Tu mensaje ha sido enviado';
            }

        }
        include_once __DIR__ . '/../../app/plantillas/usuario/contactoUsuario.php';
    }//fin metodo

    public function enviarMensajeContactoVisitante(){
        if($_SERVER['REQUEST_METHOD']=='POST'){
            if(empty($_POST['nombre']) && isset($_POST['nombre'])){
              $error = 'Falta un nombre';
            }elseif(empty($_POST['email']) && isset($_POST['email'])){
              $error = 'Falta un email';
            }elseif(empty($_POST['mensaje']) && isset($_POST['mensaje'])){
              $error = 'Falta un mensaje';
            }else{
                $error = 'Tu mensaje ha sido enviado';
            }

        }
        include_once __DIR__ . '/../../app/plantillas/visitante/contacto.php';
    }//fin metodo

    public function cerrarSesion(){
    		$_SESSION = array();
    		unset($_SESSION);//se carga todo los datos de la sesion
    		session_destroy();
    		header('Location: index.php');
    }//fin metodo

    public function modificarMiPerfilUsuario(){
        $user = $_SESSION['userNombre'];
        $usuario = (new UsuarioRepositorio)->devolverUsuarioPorNick($user);
        $ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($usuario[0]->getIdCiudad());
        include_once __DIR__ . '/../../app/plantillas/usuario/modificarMiPerfilUsuario.php';
    }//fin metodo

    public function modificarUsuarioUsuario(){
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
                  //antes de la inserción tienes que modificar el usuario de reserva así que guardamos el antiguo nick
                  $usuario = (new SuperAdministradorRepositorio())->devolverUsuario($_POST['emailAntiguo']);
                  $antiguoUsuario = $usuario[0]->getUsuario();
        					$insercion = (new SuperAdministradorRepositorio)->modificarUsuario($nickUsuario,$nombreUsuario,$apellidos1,$apellidos2,$direccionUsuario
        						,$IdCiudadUsuario,$tlfnoUsuario,$nifUsuario,$eCorreoUsuario,$faxUsuario,$emailAntiguo,$contraseniaUsuarioNUEVA,$contraseniaUsuarioVIEJA);
        					if(!$insercion){
                    include_once __DIR__ . "/../Repositorio/reservaRepositorio.inc";
                    $boolModificarUsuarioReserva = (new ReservaRepositorio())->modificarUsuarioReserva($antiguoUsuario,$nickUsuario);
        						$usuario = (new SuperAdministradorRepositorio())->devolverUsuario($_POST['eCorreoUsuario']);
        						$ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($usuario[0]->getIdCiudad());
        						$error =  "El usuario acaba de ser modificado";
                    //REENVIAMOS LA SESION
                    $_SESSION['userNombre'] = $usuario[0]->getUsuario();
                    $boolUSER = true;
        					}else{
        						$usuario = (new SuperAdministradorRepositorio())->devolverUsuario($_POST['emailAntiguo']);
        						$ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($usuario[0]->getIdCiudad());
        						$error =  "El usuario no ha podido ser modificado";
                    $boolUSER = false;
        					}
        				}

            }//FIN ELSE COMPROBACIONES
  			}
        if($boolUSER){
            $usuario = (new SuperAdministradorRepositorio())->devolverUsuario($_POST['eCorreoUsuario']);
            $ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($usuario[0]->getIdCiudad());
        }else{
            $usuario = (new SuperAdministradorRepositorio())->devolverUsuario($_POST['emailAntiguo']);
            $ciudadUsuario = (new SuperAdministradorRepositorio())->devolverCiudadUsuarioPorId($usuario[0]->getIdCiudad());
        }
  		}
  		include_once __DIR__ . "/../../app/plantillas/usuario/modificarMiPerfilUsuario.php";
  	}//fin metodo

}//fin clase
?>
