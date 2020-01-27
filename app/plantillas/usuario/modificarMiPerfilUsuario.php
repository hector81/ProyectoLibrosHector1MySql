<?php ob_start(); include './app/config/nl2br2.php'; ?>


<script type="text/javascript" src="web/jsSelected/jsSelectProvincias.js"></script>
<h2>Formulario de modificación de datos</h2>
<h4>Los campos con asterisco rojo son obligatorios. No los dejes en blanco.</h4>
<?php foreach ($usuario as $key => $value): ?>

<form class="modificarUsuario" name="modificarUsuario" method="POST" action="index.php?ctl=modificarUsuarioUsuario">
  <div class="col-sm-12 col-md-12 col-lg-6">
      <label for="nickUsuario">Nick usuario<span class="rojo">*</span></label><br>
      <input type="text" maxlength="100" value="<?php echo $value->getUsuario(); ?>" name="nickUsuario" id="nickUsuario"  class="form-control">
  </div>
  <div class="col-sm-12 col-md-6 col-lg-6">
      <label for="nombreUsuario">Nombre del usuario<span class="rojo">*</span></label><br>
      <input type="text" maxlength="30" value="<?php echo $value->getNombre(); ?>" name="nombreUsuario" id="nombreUsuario"  class="form-control">
  </div><br><br>
  <div class="col-sm-12 col-md-6 col-lg-6">
      <label for="apellidos1">Primer apellido del usuario<span class="rojo">*</span></label><br>
      <input type="text" maxlength="30" value="<?php echo $value->getPrimerApellido(); ?>" name="apellidos1" id="apellidos1"  class="form-control">
  </div>
  <div class="col-sm-12 col-md-6 col-lg-6">
      <label for="apellidos2">Segundo apellido del usuario<span class="rojo">*</span></label><br>
      <input type="text" maxlength="30" value="<?php echo $value->getSegundoApellido(); ?>" name="apellidos2" id="apellidos2"  class="form-control">
  </div>
  <div class="col-sm-12 col-md-6 col-lg-6">
      <label for="direccionUsuario">Dirección del usuario<span class="rojo">*</span></label><br>
      <input type="text" maxlength="100" value="<?php echo $value->getDireccion(); ?>" name="direccionUsuario" id="direccionUsuario" class="form-control">
  </div><br><br>

  <div class="col-sm-12 col-md-6 col-lg-6">
  <label for="provincia">Provincia <span class="rojo">*</span></label><br>
        <select id="provincia" name="provincia" class="form-control" required>
                  <option>Selecciona una provincia</option>
        </select>
  </div>
  <div class="col-sm-12 col-md-6 col-lg-6">
    <label for="municipio">Ciudad <span class="rojo">*</span></label><br>
        <select id="municipio" name="municipio" class="form-control" required>
              <option value="<?php  echo $value->getIdCiudad(); ?>"><?php echo $ciudadUsuario; ?></option>
        </select>
  </div><br><br>

  <div class="col-sm-12 col-md-6 col-lg-6">
      <label for="tlfnoUsuario">Teléfono del usuario<span class="rojo">*</span></label><br>
      <input type="text" maxlength="9" value="<?php echo $value->getTelefono(); ?>" name="tlfnoUsuario" id="tlfnoUsuario" class="form-control">
  </div>
  <div class="col-sm-12 col-md-6 col-lg-6">
      <label for="nifUsuario">Nif del usuario<span class="rojo">*</span></label><br>
      <input type="text" maxlength="9" value="<?php echo $value->getNif(); ?>" name="nifUsuario" id="nifUsuario" class="form-control">
  </div><br><br>
  <div class="col-sm-12 col-md-6 col-lg-6">
      <label for="eCorreoUsuario">Email del usuario<span class="rojo">*</span></label><br>
      <input type="text" maxlength="100" value="<?php echo $value->getEmail(); ?>" name="eCorreoUsuario" id="eCorreoUsuario" class="form-control">
  </div>
  <div class="col-sm-12 col-md-6 col-lg-6">
      <label for="faxUsuario">Fax del usuario</label><br>
      <input type="text"  maxlength="9" value="<?php echo $value->getFax(); ?>" name="faxUsuario" id="faxUsuario" class="form-control">
  </div><br><br>
  <div class="col-sm-12 col-md-6 col-lg-6">
      <label for="contraseniaUsuarioNUEVA">Contraseña del usuario en caso de querer modificarla</label><br>
      <input type="password" maxlength="150" value="" name="contraseniaUsuarioNUEVA" id="contraseniaUsuarioNUEVA" class="form-control">
  </div><br><br>

  <input type="hidden" value="<?php echo $value->getEmail(); ?>" name="emailAntiguo" id="emailAntiguo"><br><br>
  <input type="hidden" value="<?php echo $value->getContrasenia(); ?>" name="contraseniaUsuarioVIEJA" id="contraseniaUsuarioVIEJA"><br><br>
  <input type="submit" value="Enviar datos modificados" name="boton" ><br><br>

</form>
<?php endforeach; ?>
<?php $contenido = ob_get_clean() ?>
<?php include 'baseUsuario.php' ?>
