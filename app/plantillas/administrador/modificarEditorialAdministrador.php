<?php ob_start();
include './app/config/nl2br2.php'; ?>
<script type="text/javascript" src="web/jsSelected/jsSelectProvincias.js"></script>
<?php foreach ($editoriales as $key => $value) {  ?>
<form name="enviarDatos" class="enviarDatos" action="index.php?ctl=enviarDatosModificacionAdministradorEditorial" method="POST" style="text-align:left;">
        <h2>Datos de la editorial a modificar</h2>
        <h4>Los campos con asterisco rojo son obligatorios</h4>
        <div class="col-sm-12 col-md-6 col-lg-6">
            <label for="nombre">Nombre <span class="rojo">*</span></label>
            <input type="text"  maxlength="100" value="<?php echo $value->getNombre(); ?>" name="nombre" id="nombre"  class="form-control"><br><br>
        </div>
        <div class="col-sm-12 col-md-6 col-lg-6">
            <label for="direccion">Dirección <span class="rojo">*</span></label>
            <input type="text"  maxlength="100" value="<?php echo $value->getDireccion(); ?>" name="direccion" id="direccion"  class="form-control"><br><br>
        </div>
        <div class="col-sm-12 col-md-6 col-lg-6">
            <label for="provincia">Provincia </label>
                <select id="provincia" name="provincia" class="form-control" required>
          				        <option>Selecciona una provincia</option>
          			</select><br><br>
        </div>
        <div class="col-sm-12 col-md-6 col-lg-6">
              <label for="municipio">Ciudad <span class="rojo">*</span></label>
                <select id="municipio" name="municipio" class="form-control" required>
                      <option value="">Selecciona una ciudad</option>
        			  </select><br><br>
        </div>
        <div class="col-sm-12 col-md-6 col-lg-6">
              <label for="telefono">Telefono <span class="rojo">*</span></label>
              <input type="text"  maxlength="9" value="<?php echo $value->getTelefono(); ?>" name="telefono" id="telefono" class="form-control"><br><br>
        </div>
        <div class="col-sm-12 col-md-6 col-lg-6">
              <label for="fax">Fax </label>
              <input type="text"  maxlength="9" value="<?php echo $value->getFax(); ?>" name="fax" id="fax" class="form-control"><br><br>
        </div>
        <div class="col-sm-12 col-md-6 col-lg-6">
              <label for="email">Email <span class="rojo">*</span></label>
              <input type="email"  maxlength="100" value="<?php echo $value->getEmail(); ?>" name="email" id="email" class="form-control"><br><br>
        </div>
        <input type="hidden" value="<?php echo $value->getIdEditorial(); ?>" name="IdEditorial" id="IdEditorial" class="form-control"><br><br>
        <input type="submit" value="Enviar datos modificados" name="boton" ><br><br>
  </form>
  <?php } ?>

<?php $contenido = ob_get_clean() ?>
<?php include 'baseAdministrador.php' ?>
