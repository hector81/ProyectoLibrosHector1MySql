<?php ob_start(); include './app/config/nl2br2.php'; ?>


<form name="enviarDatosInsercionCategoria" class="enviarDatosInsercionCategoria" action="index.php?ctl=enviarDatosInsercionCategoria"
  method="POST" style="text-align:left;">
        <h2>Datos de la categoria a introducir</h2><br><br>
        <h4><strong>Advertencia: </strong>Las categorias y subcategorias no constaran en
           el menú visual hasta que por lo menos contengan un libro</h4>
        <div class="col-sm-12 col-md-6 col-lg-6">
            <label for="nombreCategoria">Nombre Categoria<span class="rojo">*</span></label>
            <input type="text"  maxlength="100" value="" name="nombreCategoria" id="nombreCategoria" size="40" class="form-control"><br>
        </div>

        <div class="col-sm-12 col-md-6 col-lg-6">
            <label for="nombreAlias">Introducir el nombre de la carpeta donde almacenar imagenes<span class="rojo">*</span></label>
            <input type="text"  maxlength="100" value="" name="nombreAlias" id="nombreAlias" size="40" class="form-control"><br>
        </div>

        <div class="col-sm-12 col-md-12 col-lg-12">
          <label for="descripcion">Descripción de la categoria<span class="rojo">*</span></label>
          <textarea class="form-control"  maxlength="200" rows="5" cols="60" name="descripcion" id="descripcion" placeholder="Escribir descripción"></textarea>
        </div>

        <div class="col-sm-12 col-md-6 col-lg-6">
            <br><input type="submit" value="Enviar" name="boton" ><br><br>
        </div>
  </form>

<?php $contenido = ob_get_clean() ?>
<?php include 'baseAdministrador.php' ?>
