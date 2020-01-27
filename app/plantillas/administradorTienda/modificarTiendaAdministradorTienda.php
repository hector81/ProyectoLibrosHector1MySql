<?php ob_start();
include './app/config/nl2br2.php';
?>
<?php foreach ($tienda as $key => $value) {  ?>
	<form name="formularioModificaTienda" class="formularioModificaTienda" action="index.php?ctl=enviarDatosModificacionTiendaAdministrador"
		method="POST" style="text-align:left;"  enctype="multipart/form-data">
		<h2>Datos de tu tienda a modificar</h2><br><br>
		<h4>Los datos con * rojo son obligatorios</h4>
		<div class="col-sm-12 col-md-6 col-lg-6">
			<label for="nombreTienda">Nombre<span class="rojo">*</span></label>
			<input type="text"  maxlength="50" value="<?php echo $value->getNombre(); ?>" name="nombreTienda" id="nombreTienda" size="40" class="form-control">
		</div>
		<div class="col-sm-12 col-md-6 col-lg-6">
			<label for="telefonoTienda">Telefono<span class="rojo">*</span></label>
			<input type="text"  maxlength="9" value="<?php echo $value->getTelefono(); ?>" name="telefonoTienda" id="telefonoTienda" size="40" class="form-control">
		</div>
		<div class="col-sm-12 col-md-6 col-lg-6">
			<label for="direccionTienda">Dirección<span class="rojo">*</span></label>
			<input type="text" maxlength="200" value="<?php echo $value->getDireccion(); ?>" name="direccionTienda" id="direccionTienda" size="40" class="form-control">
		</div>
		<div class="col-sm-12 col-md-6 col-lg-6">
			<label for="imagenTienda">Subir imagen: </label>
			<input type="file" value="Seleccionar foto" accept="imagenTienda/*" name="imagenTienda" id="imagenTienda" class="form-control"><br>
			<input type="hidden" value="<?php $value->getImagenTienda(); ?>" name="imagenOriginal" id="imagenOriginal"><br><br>
		</div>


			<input type="submit" value="Enviar datos modificados" name="boton" ><br><br>
	</form>
 <?php } ?>

<?php $contenido = ob_get_clean() ?>
<?php include 'baseAdministradorTienda.php' ?>
