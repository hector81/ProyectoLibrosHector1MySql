<?php ob_start(); include './app/config/nl2br2.php'; ?>

<script type="text/javascript" src="web/jsSelected/jsSelectProvincias.js"></script>
<h2>Formulario de inscripción</h2>
<h4>Los campos con asterisco rojo son obligatorios</h4>
<form class="formBusqueda" name="formBusquedaLibro" method="POST" action="index.php?ctl=inscribirUsuarioNuevo">
      <div class="col-sm-12 col-md-6 col-lg-6">
        <label for="nickUsuario">Nombre o nick de usuario <span class="rojo">*</span></label>
        <input type="text" class="form-control" id="nickUsuario" name="nickUsuario" maxlength="100"
               placeholder="Introduce tu nick de usuario" required>
      </div>

      <div class="col-sm-12 col-md-6 col-lg-6">
        <label for="contrasenia">Contraseña <span class="rojo">*</span></label>
        <input type="password" class="form-control" id="contrasenia"  name="contrasenia" maxlength="150"
               placeholder="Contraseña" required>
      </div>

      <div class="col-sm-12 col-md-6 col-lg-6">
        <label for="nombre">Nombre <span class="rojo">*</span></label>
        <input type="text" class="form-control" id="nombre" name="nombre" maxlength="30"
               placeholder="Introduce tu nombre" required>
      </div>

      <div class="col-sm-12 col-md-6 col-lg-6">
        <label for="primerApellido">Primer apellido <span class="rojo">*</span></label>
        <input type="text" class="form-control" id="primerApellido" name="primerApellido" maxlength="30"
               placeholder="Introduce tu primer apellido" required>
      </div>

      <div class="col-sm-12 col-md-6 col-lg-6">
        <label for="segundoApellido">Segundo apellido <span class="rojo">*</span></label>
        <input type="text" class="form-control" id="segundoApellido" name="segundoApellido" maxlength="30"
               placeholder="Introduce tu segundo" required>
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
              <option>Selecciona un municipio</option>
			  </select>
      </div>

      <div class="col-sm-12 col-md-6 col-lg-6">
        <label for="telefono">Teléfono <span class="rojo">*</span></label>
        <input type="text" class="form-control" id="telefono" name="telefono"  maxlength="9"
               placeholder="Introduce tu telefono" required>
      </div>

      <div class="col-sm-12 col-md-6 col-lg-6">
        <label for="direccionUsuario">Dirección <span class="rojo">*</span></label>
        <input type="text" class="form-control" id="direccionUsuario" name="direccionUsuario" maxlength="100"
               placeholder="Introduce tu direccion" required>
      </div>

      <div class="col-sm-12 col-md-6 col-lg-6">
        <label for="nifUsuario">DNI <span class="rojo">*</span></label>
        <input type="text" class="form-control" id="nifUsuario" name="nifUsuario" maxlength="9"
               placeholder="Introduce tu nif">
      </div>

      <div class="col-sm-12 col-md-6 col-lg-6" required>
        <label for="fax">Fax </label>
        <input type="text" class="form-control" id="fax" name="fax" maxlength="9"
               placeholder="Introduce tu fax">
      </div>

      <div class="col-sm-12 col-md-6 col-lg-6">
        <label for="emailUsuario">Email <span class="rojo">*</span></label>
        <input type="email" class="form-control" id="emailUsuario" name="emailUsuario" maxlength="100"
               placeholder="Introduce tu email" required>
      </div>

      <input type="hidden" name="idGrupoUsuario" value="3">
      <input type="hidden" name="grupoUsuario" value="usuario">
      <button type="submit" class="btn btn-default">Enviar</button>

</form>

<?php $contenido = ob_get_clean() ?>
<?php include 'baseInicio.php' ?>
