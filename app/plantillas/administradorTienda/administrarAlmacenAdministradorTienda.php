<?php
ob_start();
include './app/config/nl2br2.php';
?>
<script type="text/javascript" src="web/jsSelected/jsSelectCategorias.js"></script>

<form name="formularioAdministrarAlmacen" class="formularioAdministrarAlmacen" action="index.php?ctl=enviarDatosAlmacenAdministradorTienda" method="POST" style="text-align:left;">
	<h2>Datos de de busqueda</h2><br><br>
	<select id="categoria" name="categoria" class="form-control">
		  <option value="">Selecciona una categoria</option>
	</select>
	<label for="subcategoria">Subcategorias</label>
	<select id="subcategoria" name="subcategoria" class="form-control">
			<option value="">Selecciona una subcategoria -</option>
	</select>

	<input type="submit" value="Enviar datos modificados" name="boton" ><br><br>
</form>




<?php
$contenido = ob_get_clean()?>
<?php
include 'baseAdministradorTienda.php';
?>
