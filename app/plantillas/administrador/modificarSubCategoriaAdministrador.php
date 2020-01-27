<?php ob_start();
include './app/config/nl2br2.php';
?>
<?php foreach ($subCategorias as $key => $value) {  ?>
<form name="enviarDatosModificacionSubCategoria" class="enviarDatosModificacionSubCategoria" action="index.php?ctl=enviarDatosModificacionSubCategoria" method="POST" style="text-align:left;">
    <h2>Datos de la subcategoria a modificar</h2><br><br><br>
	<h4>Los datos con * rojo son obligatorios</h4>
    <div class="col-sm-12 col-md-6 col-lg-6">
        <label for="nombreSubCategoria">Nombre SubCategoria<span class="rojo">*</span></label>
        <input type="text"  maxlength="100" value="<?php echo $value->getNombreSubCategoria(); ?>" name="nombreSubCategoria" id="nombreSubCategoria" class="form-control"><br><br>
    </div>
    <div class="col-sm-12 col-md-12 col-lg-12">
        <label for="descripcion">Descripción de la categoria<span class="rojo">*</span></label><br><br>
        <textarea class="form-control"  maxlength="200" rows="5" value="<?php echo $value->getDescripcion(); ?>" name="descripcion" id="descripcion" class="form-control"></textarea>
    </div>
    <div class="col-sm-12 col-md-6 col-lg-6">
        <input type="hidden" value="<?php echo $value->getIdSubCategoria(); ?>" name="idSubCategoria" id="idSubCategoria"><br><br>
        <input type="submit" value="Enviar datos modificados" name="boton" ><br><br>
    </div>
</form>
  <?php } ?>
<?php $contenido = ob_get_clean() ?>
<?php include 'baseAdministrador.php' ?>
