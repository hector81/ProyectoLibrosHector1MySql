<?php ob_start(); include './app/config/nl2br2.php'; ?>


<?php
$librosBuscar = $libros;
if($librosBuscar != null){
  echo '<h1>Hay '.count($librosBuscar).' Resultados para  '.$palabra.'</h1>';
  foreach ($librosBuscar as $key => $libroIndividual) {
    echo '<div class="slag" style="width: 33.333333333333333333%;float: left;display:block;height:641px;margin-bottom:2em;margin-top:3em;">';
        echo '<div class="thumbnail">';
           echo '<a href="index.php?ctl=verLibrosIndividual&idLibro='.$libroIndividual['LIBROS_IDLIBRO'].'&nombreCategoria='.$libroIndividual['NOMBRE_CATEGORIA'].'">
           <img src="'.$libroIndividual['EJEMPLARES_PORTADA'].'" alt="'.$libroIndividual['LIBRO_TITULO'].'"></a>';
           echo '<div class="caption">';
              echo '<h4><a href="index.php?ctl=verLibrosIndividual&idLibro='.$libroIndividual['LIBROS_IDLIBRO'].'&nombreCategoria='.$libroIndividual['NOMBRE_CATEGORIA'].'">
              '.$libroIndividual['LIBRO_TITULO'].'</a>';
              echo '</h4>';
              echo '<p  style="text-align:left">'.substr($libroIndividual['LIBRO_DESCRIPCION'],0,120).'...</p>';
              echo '<p><strong>Precio : '.round($libroIndividual['EJEMPLARES_PVP'],2).' €</strong></p>';
           echo '</div>';
           echo '<div class="ratings">';
              echo '<form class="formBusqueda" name="formBusquedaLibro" method="POST" action="index.php?ctl=verLibrosIndividual">';
                  echo '<button type="submit" class="btn btn-default" name="verLibrosIndividualUsuario">Ver Libro</button>';
                  echo '<input type="hidden" name="idLibro" value="'.$libroIndividual['LIBROS_IDLIBRO'].'">';
                  echo '<input type="hidden" name="nombreCategoria" value="'.$libroIndividual['NOMBRE_CATEGORIA'].'">';
              echo '</form>';
           echo '</div>';
        echo '</div>';
     echo '</div>';
  }//fin del foreach
}else{
    echo '<h1>NO HAY RESULTADOS DE LA BUSQUEDA</h1>';
}


?>



<?php $contenido = ob_get_clean() ?>
<?php include 'baseInicio.php' ?>
