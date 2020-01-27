<?php ob_start();
include './app/config/nl2br2.php'; ?>
<script type="text/javascript" src="web/jsSelected/jsSelectProvincias.js"></script>
<form name="formularioUsuario" class="formularioUsuario" action="index.php?ctl=enviarDatosIntroduccionUsuario" method="POST" style="text-align:left;">
        <h2>Datos del usuario a introducir</h2><br><br><br>
        <h4>Los datos con * rojo son obligatorios</h4>
            <div class="col-sm-12 col-md-6 col-lg-6">
                <label for="nickUsuario">Nick usuario<span class="rojo">*</span></label>
                <input type="text"  maxlength="100" value="" name="nickUsuario" id="nickUsuario" class="form-control" >
            </div>
            <div class="col-sm-12 col-md-6 col-lg-6">
                <label for="nombreUsuario">Nombre del usuario<span class="rojo">*</span></label>
                <input type="text"  maxlength="30" value="" name="nombreUsuario" id="nombreUsuario" class="form-control" >
            </div>
            <div class="col-sm-12 col-md-6 col-lg-6">
                <label for="apellidos1">Primer apellido del usuario<span class="rojo">*</span></label>
                <input type="text"  maxlength="30" value="" name="apellidos1" id="apellidos1" class="form-control" >
            </div>
            <div class="col-sm-12 col-md-6 col-lg-6">
                <label for="apellidos2">Segundo apellido del usuario<span class="rojo">*</span></label>
                <input type="text"  maxlength="30" value="" name="apellidos2" id="apellidos2" class="form-control" >
            </div>
            <div class="col-sm-12 col-md-6 col-lg-6">
                <label for="direccionUsuario">Dirección del usuario<span class="rojo">*</span></label>
                <input type="text"  maxlength="100" value="" name="direccionUsuario" id="direccionUsuario" class="form-control" >
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
                        <option value=""></option>
          			  </select>
            </div>
            <div class="col-sm-12 col-md-6 col-lg-6">
                <label for="tlfnoUsuario">Teléfono del usuario<span class="rojo">*</span></label>
                <input type="text"  maxlength="9" value="" name="tlfnoUsuario" id="tlfnoUsuario" class="form-control" >
            </div>
            <div class="col-sm-12 col-md-6 col-lg-6">
                <label for="nifUsuario">Nif del usuario<span class="rojo">*</span></label>
                <input type="text"  maxlength="9" value="" name="nifUsuario" id="nifUsuario" class="form-control" >
            </div>
            <div class="col-sm-12 col-md-6 col-lg-6">
                <label for="eCorreoUsuario">Email del usuario<span class="rojo">*</span></label>
                <input type="text"  maxlength="100" value="" name="eCorreoUsuario" id="eCorreoUsuario" class="form-control" >
            </div>
            <div class="col-sm-12 col-md-6 col-lg-6">
                <label for="faxUsuario">Fax del usuario</label>
                <input type="text" value="" name="faxUsuario" id="faxUsuario" class="form-control" >
            </div>
            <div class="col-sm-12 col-md-6 col-lg-6">
                <label for="contraseniaUsuarioNUEVA">Contraseña<span class="rojo">*</span></label>
                <input type="password"  maxlength="150" value="" name="contraseniaUsuarioNUEVA" id="contraseniaUsuarioNUEVA" class="form-control" >
            </div>

        <input type="hidden" value="<?php echo $tipoUsuario; ?>" name="tipoUsuario" id="tipoUsuario"><br><br>
        <input type="submit" value="Enviar datos usuario" name="boton" ><br><br>
</form>

<?php $contenido = ob_get_clean() ?>
<?php include 'baseAdministrador.php' ?>
