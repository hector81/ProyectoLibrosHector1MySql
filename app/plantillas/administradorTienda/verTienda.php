<?php
ob_start();
include './app/config/nl2br2.php';
?>
<h2>Localizador de librerías</h2>
   <div class="col-xs-12 col-md-12 col-lg-12 content_home">
      <!-- MAPA -->
      <div class="row">
         <div class="col-xs-12 col-md-12 col-lg-12">
             <?php
             $contador = 0;
             foreach ($tiendaInicial as $key => $value) {
               echo '<h2>'.$value->getNombre().'</h2>';
               echo '<iframe src="'.$value->getImagenTienda().'" width="100%" height="450" frameborder="0" style="border:0" allowfullscreen></iframe>';
               echo '<p><strong>Teléfono</strong> :'.$value->getTelefono().'</p>';
               echo '<p><strong>Dirección</strong> :'.$value->getDireccion().'</p>';
               echo '<p><strong>Ciudad</strong> :'.$arrayCiudadProvincias[$contador]['NombreCiudad'].'</p>';
               echo '<p><strong>Provincia</strong> :'.$arrayCiudadProvincias[$contador]['NombreProvincia'].'</p>';
               $contador++;
             }
             ?>
         </div>
      </div>
      <!-- FIN MAPA -->
      <hr>
   </div>
<?php
$contenido = ob_get_clean()?>
<?php
include 'baseAdministradorTienda.php';
?>
