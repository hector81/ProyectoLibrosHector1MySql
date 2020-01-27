<?php ob_start();
include './app/config/nl2br2.php'; ?>
<script type="text/javascript" src="web/jsSelected/jsSelectProvincias.js"></script>
<?php
if($_SERVER['REQUEST_METHOD']=='GET'){
    if($_GET['redireccion'] == 'listaCompleta'){
        echo '<a href="index.php?ctl=administrarUsuarios"><button>Volver</button></a>';
    }elseif($_GET['redireccion'] == 'listaIndividual'){
        echo '<a href="index.php?ctl=administrarSuperAdministradores"><button>Volver</button></a>';
    }
    $redireccion = $_GET['redireccion'];
}
if($_SERVER['REQUEST_METHOD']=='POST'){
    if($_POST['redireccion'] == 'listaCompleta'){
        echo '<a href="index.php?ctl=administrarUsuarios"><button>Volver</button></a>';
    }elseif($_POST['redireccion'] == 'listaIndividual'){
        echo '<a href="index.php?ctl=administrarSuperAdministradores"><button>Volver</button></a>';
    }
    $redireccion = $_POST['redireccion'];
}

 ?>
<?php foreach ($superAdministrador as $key => $value) {  ?>
<form name="formularioUsuario" class="formularioUsuario" action="index.php?ctl=enviarDatosModificacionSuperAdministrador" method="POST" style="text-align:left;">
        <h2>Datos del super administrador a modificar</h2><br><br><br>

            <div class="col-sm-12 col-md-6 col-lg-6">
                <label for="nickUsuario">Nick usuario<span class="rojo">*</span></label>
                <input type="text"  maxlength="100" value="<?php echo $value->getUsuario(); ?>" name="nickUsuario" id="nickUsuario" class="form-control">
            </div>
            <div class="col-sm-12 col-md-6 col-lg-6">
                <label for="nombreUsuario">Nombre del usuario<span class="rojo">*</span></label>
                <input type="text"  maxlength="30" value="<?php echo $value->getNombre(); ?>" name="nombreUsuario" id="nombreUsuario" class="form-control">
            </div>
            <div class="col-sm-12 col-md-6 col-lg-6">
                <label for="apellidos1">Primer apellido del usuario<span class="rojo">*</span></label>
                <input type="text"  maxlength="30" value="<?php echo $value->getPrimerApellido(); ?>" name="apellidos1" id="apellidos1" class="form-control">
            </div>
            <div class="col-sm-12 col-md-6 col-lg-6">
                <label for="apellidos2">Segundo apellido del usuario<span class="rojo">*</span></label>
                <input type="text"  maxlength="30" value="<?php echo $value->getSegundoApellido(); ?>" name="apellidos2" id="apellidos2" class="form-control">
            </div>
            <div class="col-sm-12 col-md-6 col-lg-6">
                <label for="direccionUsuario">Dirección del usuario<span class="rojo">*</span></label>
                <input type="text"  maxlength="100" value="<?php echo $value->getDireccion(); ?>" name="direccionUsuario" id="direccionUsuario" class="form-control">
            </div>
            <div class="col-sm-12 col-md-6 col-lg-6">
            <label for="provincia">Provincia <span class="rojo">*</span></label>
                  <select id="provincia" name="provincia" class="form-control" required>
            				        <option>Selecciona una provincia</option>
            			</select>
            </div>
            <div class="col-sm-12 col-md-6 col-lg-6">
              <label for="municipio">Ciudad <span class="rojo">*</span></label>
                  <select id="municipio" name="municipio" class="form-control" required>
                        <option value="<?php  echo $value->getIdCiudad(); ?>"><?php echo $ciudadUsuario; ?></option>
          			  </select>
            </div>
            <div class="col-sm-12 col-md-6 col-lg-6">
                <label for="tlfnoUsuario">Teléfono del usuario<span class="rojo">*</span></label>
                <input type="text"  maxlength="9" value="<?php echo $value->getTelefono(); ?>" name="tlfnoUsuario" id="tlfnoUsuario" class="form-control">
            </div>
            <div class="col-sm-12 col-md-6 col-lg-6">
                <label for="nifUsuario">Nif del usuario</label>
                <input type="text"  maxlength="9" value="<?php echo $value->getNif(); ?>" name="nifUsuario" id="nifUsuario" class="form-control">
            </div>
            <div class="col-sm-12 col-md-6 col-lg-6">
                <label for="eCorreoUsuario">Email del usuario<span class="rojo">*</span></label>
                <input type="text"  maxlength="100" value="<?php echo $value->getEmail(); ?>" name="eCorreoUsuario" id="eCorreoUsuario" class="form-control">
            </div>
            <div class="col-sm-12 col-md-6 col-lg-6">
                <label for="faxUsuario">Fax del usuario<span class="rojo">*</span></label>
                <input type="text"  maxlength="9" value="<?php echo $value->getFax(); ?>" name="faxUsuario" id="faxUsuario"  class="form-control">
            </div>
            <div class="col-sm-12 col-md-6 col-lg-6">
                <label for="contraseniaUsuarioNUEVA">Contraseña del usuario en caso de querer modificarla<span class="rojo">*</span></label>
                <input type="password"  maxlength="150" value="" name="contraseniaUsuarioNUEVA" id="contraseniaUsuarioNUEVA" class="form-control">
            </div>

        <input type="hidden" value="<?php echo $redireccion; ?>" name="redireccion" id="redireccion"><br><br>
        <input type="hidden" value="<?php echo $value->getEmail(); ?>" name="emailAntiguo" id="emailAntiguo"><br><br>
        <input type="hidden" value="<?php echo $value->getContrasenia(); ?>" name="contraseniaUsuarioVIEJA" id="contraseniaUsuarioVIEJA"><br><br>
        <input type="submit" value="Enviar datos modificados" name="boton" ><br><br>
  </form>
  <?php } ?>

<?php $contenido = ob_get_clean() ?>
<?php include 'baseAdministrador.php' ?>
