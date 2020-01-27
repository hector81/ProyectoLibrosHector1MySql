<?php
ob_start();
include './app/config/nl2br2.php';
?>
<?php
foreach ($autor as $key => $value) {
?>
<form name="formularioUsuario" class="formularioUsuario" action="index.php?ctl=enviarDatosModificacionAutor" method="POST" style="text-align:left;">
        <h2>Datos del autor a modificar</h2><br><br>
		<h4>Los datos con * rojo son obligatorios</h4>
		<div class="col-sm-12 col-md-12 col-lg-12">
			<label for="nombreAutor">Nombre Autor<span class="rojo">*</span></label>
			<input type="text"  maxlength="100" value="<?php echo $value->getNombre(); ?>" name="nombreAutor" id="nombreAutor" class="form-control">
		</div>
		<div class="col-sm-12 col-md-6 col-lg-6">
			<label for="idPais">Pais<span class="rojo">*</span></label><br><br>
			<select id="idPais" name="idPais" class="form-control">
				<option value="<?php echo $value->getIdPais() ?>"><?php echo $value->getNacionalidad() ?></option>
				<?php
					foreach ($paises as $key1 => $pais) {
					  echo '<option value="'.$pais->getIdPais().'">'.$pais->getNombrePais().'</option>';
					}

				  ?>
			</select>
		</div>
        <input type="hidden" value="<?php echo $value->getIdAutor(); ?>" name="idAutor" id="idAutor"><br><br>

        <input type="submit" value="Enviar datos modificados" name="boton" ><br><br>
  </form>
  <?php
}
?>
<?php
$contenido = ob_get_clean()?>
<?php
include 'baseAdministrador.php';
?>
