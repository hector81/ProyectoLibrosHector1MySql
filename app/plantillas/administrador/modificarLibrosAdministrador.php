<?php ob_start();
include './app/config/nl2br2.php';
?>
<script type="text/javascript" src="web/jsSelected/jsSelectedImagenesTienda.js"></script>
<form name="formularioModificaLibro" class="formularioModificaLibro" action="index.php?ctl=enviarDatosModificacionLibro"
  method="POST" style="text-align:left;"  enctype="multipart/form-data">
        <h4>Datos del libro que puedes modificar</h4><br><br>
		<h4>Los datos con * rojo son obligatorios</h4>
        <div class="col-sm-12 col-md-6 col-lg-6">
              <label for="PVP">Precio del libro<span class="rojo">*</span></label>
              <input type="text" value="<?php echo round($libroIndividual['PVP'],2); ?>" name="PVP" id="PVP" size="40"  class="form-control"><br>
        </div>
        <div class="col-sm-12 col-md-6 col-lg-6">
            <label for="portada">Subir imagen: </label>
            <input type="file" value="Seleccionar foto" accept="imagenTienda/*" name="portada" id="portada"  class="form-control"><br>
            <input type="hidden" value="<?php $libroIndividual['Portada']; ?>" name="imagenOriginal" id="imagenOriginal"><br><br>
        </div>
        <div class="col-sm-12 col-md-12 col-lg-12">
              <label for="descripcion">Descripción: <span class="rojo">*</span></label><br><br>
              <textarea type="text"  maxlength="500" value="<?php echo $libroIndividual['Descripcion']; ?>" name="descripcion" id="descripcion" size="40"  class="form-control">
              </textarea>
        </div>
        <div class="col-sm-12 col-md-12 col-lg-12">
            <input type="hidden" value="<?php echo $libroIndividual['IdEjemplar']; ?>" name="idEjemplar" id="idEjemplar" size="40"><br><br>
            <input type="hidden" value="<?php echo $libroIndividual['IdLibro']; ?>" name="idLibro" id="idLibro" size="40"><br><br>
            <input type="hidden" value="<?php echo $libroIndividual['IdCategoria']; ?>" name="idCategoria" id="idCategoria" size="40"><br><br>
            <input type="hidden" value="<?php echo $libroIndividual['IdSubCategoria']; ?>" name="idSubCategoria" id="idSubCategoria" size="40"><br><br>
            <input type="submit" value="Enviar datos modificados" name="boton" ><br><br>
        </div>
  </form>

<?php $contenido = ob_get_clean() ?>
<?php include 'baseAdministrador.php' ?>
