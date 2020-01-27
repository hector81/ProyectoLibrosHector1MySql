<?php
ob_start();
include './app/config/nl2br2.php';
?>
<script type="text/javascript" src="web/jsSelected/jsSelectCategorias.js"></script>
<form name="formularioAdministrarAlmacen" class="formularioAdministrarAlmacen" action="index.php?ctl=enviarDatosAlmacen"
  method="POST" style="text-align:left;">
        <h2>Selecciona los datos para buscar los libros donde modificar o comprobar stock</h2><br><br>

        <div class="col-sm-12 col-md-12 col-lg-12">
            <label for="tienda">Tienda</label>
            <select id="tienda" name="tienda" class="form-control">
              <option value="">Selecciona una tienda</option>
              <?php
                  foreach ($tiendaTotal as $key1 => $value1) {
                      echo '<option value="'.$value1->getIdTienda().'">'.$value1->getNombre().'</option>';
                  }
              ?>

    			  </select>
        </div>
        <div class="col-sm-12 col-md-6 col-lg-6">
            <label for="categoria">Categorias</label>
            <select id="categoria" name="categoria" class="form-control">
                  <option value="">Selecciona una categoria</option>
            </select>
        </div>
        <div class="col-sm-12 col-md-6 col-lg-6">
            <label for="subcategoria">Subcategorias</label>
            <select id="subcategoria" name="subcategoria" class="form-control">
                    <option value="">Selecciona una subcategoria -</option>
            </select>
        </div>

        <button class="btn btn-default" type="submit"  name="boton" >Enviar datos filtrados</button><br><br>
  </form>




<?php
$contenido = ob_get_clean()?>
<?php
include 'baseAdministrador.php';
?>
