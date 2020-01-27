<?php ob_start(); include './app/config/nl2br2.php'; ?>


<?php
  $contador = 0;
  echo '<table class="table table-condensed">';
  foreach ($tiendaTotal as $key => $value) {

    echo '<thead>';
      echo '<tr>';
        echo '<th style="text-align_left;">NOMBRE</th>';
        echo '<th style="text-align_left;">CIUDAD</th>';
        echo '<th style="text-align_left;">PROVINCIA</th>';
        echo '<th style="text-align_left;">TELEFONO</th>';
        echo '<th style="text-align_left;">DIRECCIÓN</th>';
        echo '<th style="text-align_left;">VER VENTAS</th>';
      echo '</tr>';
    echo '</thead>';
    echo '<tbody>';
      echo '<thead>';
        echo '<tr>';
          echo '<td style="word-break: break-all;text-align_left;">'.$value->getNombre().'</td>';
          echo '<td style="word-break: break-all;text-align_left;">'.$arrayCiudadProvincias[$contador]['NombreCiudad'].'</td>';
          echo '<td style="word-break: break-all;text-align_left;">'.$arrayCiudadProvincias[$contador]['NombreProvincia'].'</td>';
          echo '<td style="word-break: break-all;text-align_left;">'.$value->getTelefono().'</td>';
          echo '<td style="word-break: break-all;text-align_left;">'.$value->getDireccion().'</td>';
          echo '<td style="word-break: break-all;text-align_left;">
          <form id="verVentasTiendaSuperAdministrador" name="verVentasTiendaSuperAdministrador" action="index.php?ctl=verVentasTiendaSuperAdministrador" method="POST">
          <button type="submit"><span class="glyphicon glyphicon-zoom-out"></span></button>
          <input type="hidden" value="'.$value->getIdTienda().'" name="idTienda" id="idTienda">
          <input type="hidden" value="'.$value->getNombre().'" name="nombreTienda" id="nombreTienda">
          </form>
          </td>';
        echo '</tr>';
      echo '</thead>';
    echo '</tbody>';
    $contador++;
 }
    echo '</table>';
 ?>

<?php $contenido = ob_get_clean() ?>
<?php include 'baseAdministrador.php' ?>
