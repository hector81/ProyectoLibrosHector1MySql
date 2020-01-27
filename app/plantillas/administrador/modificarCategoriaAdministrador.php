<?php
ob_start();
include './app/config/nl2br2.php';
?>
<?php
foreach ($categoria as $key => $value) {
?>
<form name="enviarDatosModificacionCategoria" class="enviarDatosModificacionCategoria" action="index.php?ctl=enviarDatosModificacionCategoria" method="POST" style="text-align:left;">
        <h2>Datos de la categoria a modificar</h2><br><br>
		<h4>Los datos con * rojo son obligatorios</h4>
        <div class="col-sm-12 col-md-6 col-lg-6">
              <label for="nombreCategoria">Nombre Categoria<span class="rojo">*</span></label>
              <input type="text"  maxlength="100" value="<?php echo $value->getNombreCategoria(); ?>" name="nombreCategoria" id="nombreCategoria" class="form-control"><br><br>
        </div>
        <div class="col-sm-12 col-md-12 col-lg-12">
            <label for="descripcion">Descripción de la categoria<span class="rojo">*</span></label><br><br>
            <textarea class="form-control"  maxlength="200" rows="5" value="<?php echo $value->getDescripcion(); ?>" name="descripcion" id="descripcion"  class="form-control"></textarea>
        </div>
        <div class="col-sm-12 col-md-6 col-lg-6">
            <input type="hidden" value="<?php echo $value->getIdCategoria(); ?>" name="idCategoria" id="idCategoria"><br><br>
            <input type="submit" value="Enviar datos modificados" name="boton" ><br><br>
        </div>
  </form>

  <?php
}
?>
<?php
$contenido = ob_get_clean()?>
<?php
include 'baseAdministrador.php';
?>
