<?php ob_start(); include './app/config/nl2br2.php'; ?>


<?php
$contador = 0;
  echo '<table class="table table-condensed">';
  foreach ($editoriales as $key => $value) {
    echo '<thead>';
      echo '<tr>';
        echo '<th style="text-align_left;">NOMBRE</th>';
        echo '<th style="text-align_left;">DIRECCIÓN</th>';
        echo '<th style="text-align_left;">CIUDAD</th>';
        echo '<th style="text-align_left;">TELÉFONO</th>';
        echo '<th style="text-align_left;">FAX</th>';
        echo '<th style="text-align_left;">EMAIL</th>';
        echo '<th style="text-align_left;">VER LIBROS</th>';
      echo '</tr>';
    echo '</thead>';
    echo '<tbody>';
      echo '<thead>';
        echo '<tr>';
          echo '<td style="word-break: break-all;text-align_left;">'.$value->getNombre().'</td>';
          echo '<td style="word-break: break-all;text-align_left;">'.$value->getDireccion().'</td>';
          echo '<td style="word-break: break-all;text-align_left;">'.$ciudades[$contador].'</td>';
          echo '<td style="word-break: break-all;text-align_left;">'.$value->getTelefono().'</td>';
          echo '<td style="word-break: break-all;text-align_left;">'.$value->getFax().'</td>';
          echo '<td style="word-break: break-all;text-align_left;">'.$value->getEmail().'</td>';


          echo '<td style="word-break: break-all;text-align_left;">
          <form id="verLibrosEditorialesVisitantes" name="verLibrosEditorialesVisitantes" action="index.php?ctl=verLibrosEditorialesVisitantes" method="POST">
          <button type="submit"><span class="glyphicon glyphicon-zoom-out"></span></button>
          <input type="hidden" value="'.$value->getIdEditorial().'" name="idEditorial" id="idEditorial">
          <input type="hidden" value="'.$value->getNombre().'" name="nombreEditorial" id="nombreEditorial">
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
<?php include 'baseInicio.php' ?>
