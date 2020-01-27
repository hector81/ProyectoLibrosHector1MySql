<?php ob_start();
include './app/config/nl2br2.php'; ?>
<script type="text/javascript" src="web/jsSelected/jsSelectCategorias.js"></script>
<script type="text/javascript" src="web/jsSelected/jsSelectedImagenesTienda.js"></script>
<form name="formularioUsuario" class="formularioUsuario" action="index.php?ctl=enviarDatosIntroduccionIntroducciónLibros" method="POST"
 style="text-align:left;" enctype="multipart/form-data">
      <h2>Datos de libro nuevo a introducir</h2><br><br>
	     <h4>Los datos con * rojo son obligatorios</h4>
      <div class="col-sm-12 col-md-12 col-lg-6" required>
        <label for="titulo">Título<span class="rojo">*</span></label><br>
        <input type="text"  maxlength="200" value="" name="titulo" id="titulo" class="form-control">
      </div>


      <div class="col-sm-12 col-md-6 col-lg-6">
        <label for="categoria">Categorias<span class="rojo">*</span></label>
          <select id="categoria" name="categoria" class="form-control">
            <option>Cargando...</option>
          </select>
      </div>
      <div class="col-sm-12 col-md-6 col-lg-6">
        <label for="subcategoria">Subcategorias<span class="rojo">*</span></label>
        <select id="subcategoria" name="subcategoria" class="form-control">
          <option value="">- selecciona una subcategoria -</option>
        </select><br><br>
      </div>
      <div class="col-sm-12 col-md-6 col-lg-6">
        <label for="nombreAutor">Pon un nombre de autor<span class="rojo">*</span></label>
        <select id="nombreAutor" name="nombreAutor" class="form-control">
            <?php
                foreach ($autores as $key => $value) {
                  echo '<option value="'.$value->getIdAutor().'">'.$value->getNombre().'</option>';
                }

              ?>
        </select><br><br>
      </div>



      <div class="col-sm-12 col-md-6 col-lg-6">
        <label for="tipoEncuadernacion">Pon el tipo de encuadernación<span class="rojo">*</span></label>
        <select id="tipoEncuadernacion" name="tipoEncuadernacion" class="form-control">
              <option value="Tapa dura">Tapa dura</option>
              <option value="Tapa blanda">Tapa blanda</option>
        </select><br><br>
      </div>

      <div class="col-sm-12 col-md-6 col-lg-6">
        <label for="numeroEdicion">Pon el número de edición<span class="rojo">*</span></label>
        <input type="number" value="" name="numeroEdicion" id="numeroEdicion" class="form-control"><br><br>
      </div>

      <div class="col-sm-12 col-md-6 col-lg-6">
        <label for="yearPublicacion">Año de publicación<span class="rojo">*</span></label>
        <input type="text" maxlength="4" value="" name="yearPublicacion" id="yearPublicacion" class="form-control"><br><br>
      </div>

      <div class="col-sm-12 col-md-6 col-lg-6">
        <label for="formato">Formato<span class="rojo">*</span></label>
        <input type="text"  maxlength="50" value="" name="formato" id="formato" class="form-control"><br><br>
      </div>

      <div class="col-sm-12 col-md-6 col-lg-6">
        <label for="idEditorial">Pon una editorial<span class="rojo">*</span> </label>
        <select id="idEditorial" name="idEditorial" class="form-control">
            <?php
                foreach ($editoriales as $key => $value) {
                  echo '<option value="'.$value->getIdEditorial().'">'.$value->getNombre().'</option>';
                }

              ?>
        </select><br><br>
      </div>

      <div class="col-sm-12 col-md-6 col-lg-6">
        <label for="idioma">Pon el idioma<span class="rojo">*</span></label>
        <select id="idioma" name="idioma" class="form-control">
              <option value="Español">Español</option>
              <option value="Ingles">Ingles</option>
              <option value="Frances">Frances</option>
              <option value="Aleman">Aleman</option>
              <option value="Otros">Otros</option>
        </select><br><br>
      </div>

      <div class="col-sm-12 col-md-6 col-lg-6">
        <label for="isbn">ISBN<span class="rojo">*</span></label>
        <input type="text"  maxlength="40" value="" name="isbn" id="isbn" class="form-control"><br><br>
      </div>

      <div class="col-sm-12 col-md-6 col-lg-6">
        <label for="paginas">Páginas<span class="rojo">*</span></label>
        <input type="number" value="" name="paginas" id="paginas" class="form-control"><br><br>
      </div>


      <div class="col-sm-12 col-md-6 col-lg-6">
        <label for="PVP">Pon el precio del libro<span class="rojo">*</span></label>
        <input type="text" value="" name="PVP" id="PVP" class="form-control"><br><br>
      </div>

      <div class="col-sm-12 col-md-6 col-lg-6">
          <label for="portada">Subir portada del libro<span class="rojo">*</span></label>
          <input type="file" value="Seleccionar foto" accept="imagenTienda/*" name="portada" id="portada" class="form-control"><br><br><br><br>
      </div>

      <div class="col-sm-12 col-md-12 col-lg-12">
        <label for="descripcion">Descripción del libro<span class="rojo">*</span></label>
        <textarea class="form-control"  maxlength="500" rows="5" cols="60" name="descripcion" id="descripcion" placeholder="Escribir descripción" class="form-control"></textarea>
      </div>


      <input type="hidden" value="<?php echo date("Y-m-d H:i:s"); ?>" name="fechaDisponibilidad" id="fechaDisponibilidad"><br><br>
      <input type="submit" value="Enviar datos libro" name="boton" ><br><br>
</form>

<?php $contenido = ob_get_clean() ?>
<?php include 'baseAdministrador.php' ?>
