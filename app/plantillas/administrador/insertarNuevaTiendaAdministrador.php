<?php ob_start(); include './app/config/nl2br2.php'; ?>
<script type="text/javascript" src="web/jsSelected/jsSelectProvincias.js"></script>
<script type="text/javascript" src="web/jsSelected/jsSelectedImagenesTienda.js"></script>

<form name="formularioInsercionTienda" class="formularioInsercionTienda" action="index.php?ctl=enviarDatosInsercionTienda"
  method="POST" style="text-align:left;"  enctype="multipart/form-data">
        <h2>Datos de la tienda a introducir</h2><br><br>
		<h4>Los datos con * rojo son obligatorios</h4>
        <div class="col-sm-12 col-md-6 col-lg-6">
            <label for="nombreTienda">Nombre<span class="rojo">*</span></label>
            <input type="text" maxlength="50" value="" name="nombreTienda" id="nombreTienda" size="40" class="form-control"><br>
        </div>
        <div class="col-sm-12 col-md-6 col-lg-6">
            <label for="provincia">Provincia<span class="rojo">*</span></label>
              <select id="provincia" name="provincia" class="form-control" required>
  				            <option value="">Selecciona una provincia</option>
              </select>
        </div>
        <div class="col-sm-12 col-md-6 col-lg-6">
            <label for="municipio">Ciudad<span class="rojo">*</span></label>
              <select id="municipio" name="municipio" class="form-control" required>
                  <option value="">Selecciona un municipio</option>
			             </select>
        </div>
        <div class="col-sm-12 col-md-6 col-lg-6">
            <label for="telefonoTienda">Telefono<span class="rojo">*</span></label>
            <input type="text"  maxlength="9" value="" name="telefonoTienda" id="telefonoTienda" size="40" class="form-control"><br><br>
        </div>
        <div class="col-sm-12 col-md-6 col-lg-6">
            <label for="direccionTienda">Dirección<span class="rojo">*</span></label>
            <input type="text"  maxlength="200" value="" name="direccionTienda" id="direccionTienda" size="40" class="form-control"><br><br>
        </div>
        <div class="col-sm-12 col-md-6 col-lg-6">
              <label for="imagenTienda">Subir imagen: </label>
              <input type="file" value="Seleccionar foto" accept="imagenTienda/*" name="imagenTienda" id="imagenTienda"  class="form-control"><br>
              <input type="hidden" value="" name="imagenOriginal" id="imagenOriginal"><br><br>
        </div>
        <div class="col-sm-12 col-md-6 col-lg-6">
            <br><input type="submit" value="Enviar datos tienda" name="boton" ><br><br>
        </div>
  </form>

<?php $contenido = ob_get_clean() ?>
<?php include 'baseAdministrador.php' ?>
