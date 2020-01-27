<?php ob_start(); include './app/config/nl2br2.php'; ?>

<h2><strong>Editoriales</strong></h2>
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
        echo '<th style="text-align_left;">ACCIONES</th>';
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
          <form id="modificarEditorial" name="modificarEditorial" action="index.php?ctl=modificarEditorialAdministrador" method="POST">
                <button type="submit"><span class="glyphicon glyphicon-pencil"></span></button>
                <input type="hidden" value="'.$value->getIdEditorial().'" name="IdEditorial" id="IdEditorial">
          </form>
          <form id="borrarEditorialAdministrador" name="borrarEditorialAdministrador" action="index.php?ctl=borrarEditorialAdministrador" method="POST">
                <button type="submit"><span class="glyphicon glyphicon-remove"></span></button>
                <input type="hidden" value="'.$value->getIdEditorial().'" name="IdEditorial" id="IdEditorial">
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
