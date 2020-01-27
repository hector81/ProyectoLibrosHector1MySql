<?php ob_start();
include './app/config/nl2br2.php'; ?>

<form name="formularioUsuario" class="formularioUsuario" action="index.php?ctl=enviarDatosIntroduccionAutores" method="POST" style="text-align:left;">
      <h2>Datos del autor a introducir</h2>
	  <h4>Los datos con * rojo son obligatorios</h4>
	  <div class="col-sm-12 col-md-6 col-lg-6">
        <label for="nombreAutor">Pon un nombre de autor<span class="rojo">*</span></label>
        <input type="text"  maxlength="100" value="" name="nombreAutor" id="nombreAutor" class="form-control">
      </div>
      <div class="col-sm-12 col-md-6 col-lg-6">
        <label for="idPais">Pon el pais del autor<span class="rojo">*</span></label>
        <select id="idPais" name="idPais" class="form-control">
            <?php
                foreach ($paises as $key => $value) {
                  echo '<option value="'.$value->getIdPais().'">'.$value->getNombrePais().'</option>';
                }

              ?>
        </select>
      </div><br><br><br><br>
      <input type="submit" value="Enviar datos autor" name="boton" ><br><br>
</form>



<?php $contenido = ob_get_clean() ?>
<?php include 'baseAdministrador.php' ?>
