<?php ob_start(); include './app/config/nl2br2.php'; ?>


<?php
  echo '<table class="table table-condensed">';
  foreach ($autores as $key => $value) {

    echo '<thead>';
      echo '<tr>';
        echo '<th style="text-align_left;">NOMBRE</th>';
        echo '<th style="text-align_left;">NACIONALIDAD</th>';
        echo '<th style="text-align_left;">VER LIBROS</th>';
      echo '</tr>';
    echo '</thead>';
    echo '<tbody>';
      echo '<thead>';
        echo '<tr>';
          echo '<td style="word-break: break-all;text-align_left;">'.$value->getNombre().'</td>';
          echo '<td style="word-break: break-all;text-align_left;">'.$value->getNacionalidad().'</td>';//'.$value['Email'].'
          echo '<td style="word-break: break-all;text-align_left;">
          <form id="verLibrosAutorUsuario" name="verLibrosAutorUsuario" action="index.php?ctl=verLibrosAutorUsuario" method="POST">
              <button type="submit"><span class="glyphicon glyphicon-zoom-out"></span></button>
              <input type="hidden" value="'.$value->getNombre().'" name="nombreAutor" id="nombreAutor">
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
<?php include 'baseUsuario.php' ?>
