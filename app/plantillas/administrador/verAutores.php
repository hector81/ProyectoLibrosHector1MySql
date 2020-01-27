<?php ob_start(); include './app/config/nl2br2.php'; ?>

<h2><strong>Autores</strong></h2>
<?php
  echo '<table class="table table-condensed">';
  foreach ($autores as $key => $value) {

    echo '<thead>';
      echo '<tr>';
        echo '<th style="text-align_left;">NOMBRE</th>';
        echo '<th style="text-align_left;">NACIONALIDAD</th>';
        echo '<th style="text-align_left;">ACCIONES</th>';
      echo '</tr>';
    echo '</thead>';
    echo '<tbody>';
      echo '<thead>';
        echo '<tr>';
          echo '<td style="word-break: break-all;text-align_left;">'.$value->getNombre().'</td>';
          echo '<td style="word-break: break-all;text-align_left;">'.$value->getNacionalidad().'</td>';//'.$value['Email'].'
          echo '<td style="word-break: break-all;text-align_left;">
          <form id="modificarAutor" name="modificarAutor" action="index.php?ctl=modificarAutorAdministrador" method="POST">
          <button type="submit"><span class="glyphicon glyphicon-pencil"></span></button>
          <input type="hidden" value="'.$value->getIdAutor().'" name="idAutor" id="idAutor">
          </form>
          <form id="borrarAutor" name="borrarAutor" action="index.php?ctl=borrarAutorAdministrador" method="POST">
          <button type="submit"><span class="glyphicon glyphicon-remove"></span></button>
          <input type="hidden" value="'.$value->getIdAutor().'" name="idAutor" id="idAutor">
          </form>
          </td>';
        echo '</tr>';
      echo '</thead>';
    echo '</tbody>';

 }
    echo '</table>';
 ?>

<?php $contenido = ob_get_clean() ?>
<?php include 'baseAdministrador.php' ?>
