<?php ob_start(); include './app/config/nl2br2.php'; ?>


<?php
$librosBuscar = $libros;
if($librosBuscar != null){
  echo '<h1>Hay '.count($librosBuscar).' Resultados para  '.$palabra.'</h1>';
  foreach ($librosBuscar as $key => $libroIndividual) {
    echo '<div class="slag" style="width: 33.333333333333333333%;float: left;display:block;height:641px;margin-bottom:2em;margin-top:3em;">';
        echo '<div class="thumbnail">';
           echo '<a href="index.php?ctl=verLibrosIndividualAdministrador&idLibro='.$libroIndividual['LIBROS_IDLIBRO'].'&nombreCategoria='.$libroIndividual['NOMBRE_CATEGORIA'].'">
           <img src="'.$libroIndividual['EJEMPLARES_PORTADA'].'" alt="'.$libroIndividual['LIBRO_TITULO'].'"></a>';
           echo '<h4><a href="index.php?ctl=verLibrosIndividualAdministrador&idLibro='.$libroIndividual['LIBROS_IDLIBRO'].'&nombreCategoria='.$libroIndividual['NOMBRE_CATEGORIA'].'">
           '.$libroIndividual['LIBRO_TITULO'].'</a>';
           echo '</h4>';
           echo '<div class="caption">';
           echo '<p  style="text-align:left">'.substr($libroIndividual['LIBRO_DESCRIPCION'],0,120).'...</p>';
           echo '<p><strong>Precio : '.round($libroIndividual['EJEMPLARES_PVP'],2).' €</strong></p>';
           echo '</div>';
              echo '<form class="formBusqueda" name="formBusquedaLibro" method="POST" action="index.php?ctl=verLibrosIndividualAdministrador">';
                  echo '<button type="submit" class="btn btn-default" name="verLibrosIndividualUsuario">Ver Libro</button>';
                  echo '<input type="hidden" name="idLibro" value="'.$libroIndividual['LIBROS_IDLIBRO'].'">';
                  echo '<input type="hidden" name="nombreCategoria" value="'.$libroIndividual['NOMBRE_CATEGORIA'].'">';
              echo '</form>';
              echo '<div class="caption">';
                 echo '<a href="index.php?ctl=modificarLibrosAdministrador&idLibro='.$libroIndividual['LIBROS_IDLIBRO'].'">';
                 echo '<span class="glyphicon glyphicon-pencil"></span>';
                 echo '</a>&nbsp;&nbsp;&nbsp;';
                 echo '<a href="index.php?ctl=verLibrosIndividualAdministrador&idLibro='.$libroIndividual['LIBROS_IDLIBRO'].'&nombreCategoria='.$libroIndividual['NOMBRE_CATEGORIA'].'">';
                 echo '<span class="glyphicon glyphicon-eye-open"></span>';
                 echo '</a>&nbsp;&nbsp;&nbsp;';
                 echo '<a href="index.php?ctl=borrarLibroAdministrador&idLibro='.$libroIndividual['LIBROS_IDLIBRO'].'&nombreCategoria='.$libroIndividual['NOMBRE_CATEGORIA'].'
                 &idSubCategoria='.$libroIndividual['ID_SUBCATEGORIA'].'">';
                 echo '<span class="glyphicon glyphicon-remove"></span>';
              echo '</div>';
        echo '</div>';
     echo '</div>';
  }//fin del foreach
}else{
    echo '<h1>NO HAY RESULTADOS DE LA BUSQUEDA</h1>';
}


?>



<?php $contenido = ob_get_clean() ?>
<?php include 'baseAdministrador.php' ?>
