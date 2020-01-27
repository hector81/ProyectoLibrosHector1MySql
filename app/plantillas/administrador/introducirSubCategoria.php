<?php ob_start(); include './app/config/nl2br2.php'; ?>


<form name="enviarDatosInsercionSubCategoria" class="enviarDatosInsercionSubCategoria" action="index.php?ctl=enviarDatosInsercionSubCategoria"
  method="POST" style="text-align:left;">
        <h2>Datos de la subCategoria a introducir</h2><br><br>
        <h4><strong>Advertencia: </strong>Las categorias y subcategorias no constaran en el menú
          visual hasta que por lo menos contengan un libro</h4>
        <div class="col-sm-12 col-md-6 col-lg-6">
            <label for="idCategoria">Selecciona la categoria de la que depende<span class="rojo">*</span></label>
            <select id="idCategoria" name="idCategoria" class="form-control">
                <option value="">Selecciona una categoria<span class="rojo">*</span></option>
                <?php
                    foreach ($categorias as $key => $value) {
                      echo '<option value="'.$value->getIdCategoria().'">'.$value->getNombreCategoria().'</option>';
                    }

                  ?>
            </select>
        </div>

        <div class="col-sm-12 col-md-6 col-lg-6">
            <label for="nombreSubCategoria">Nombre subCategoria<span class="rojo">*</span></label>
            <input type="text"  maxlength="100" value="" name="nombreSubCategoria" id="nombreSubCategoria" size="40" class="form-control"><br><br>
        </div>

        <div class="col-sm-12 col-md-6 col-lg-6">
            <label for="nombreAlias">Introducir el nombre de la carpeta donde almacenar imagenes<span class="rojo">*</span></label>
            <input type="text"  maxlength="100" value="" name="nombreAlias" id="nombreAlias" size="40" class="form-control"><br><br>
        </div>

        <div class="col-sm-12 col-md-12 col-lg-12">
          <label for="descripcion">Descripción de la subCategoria<span class="rojo">*</span></label>
          <textarea class="form-control"  maxlength="200" rows="5" cols="60" name="descripcion" id="descripcion" placeholder="Escribir descripción" class="form-control"></textarea>
        </div>

        <div class="col-sm-12 col-md-6 col-lg-6">
            <br><input type="submit" value="Enviar" name="boton" ><br><br>
        </div>
  </form>

<?php $contenido = ob_get_clean() ?>
<?php include 'baseAdministrador.php' ?>
