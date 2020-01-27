<?php ob_start(); include './app/config/nl2br2.php'; ?>


<?php
echo '<h1>Libros de la subcategoria '.$nombreSubCategoria.'</h1>';
foreach ($libros as $key => $libroIndividual) {
  echo '<div class="slag" style="width: 33.333333333333333333%;float: left;display:block;height:641px;margin-bottom:2em;margin-top:3em;">';
      echo '<div class="thumbnail">';
         echo '<a href="index.php?ctl=verLibrosIndividual&idLibro='.$libroIndividual['IdLibro'].'&nombreCategoria='.$libroIndividual['NombreCategoria'].'">
         <img src="'.$libroIndividual['Portada'].'" alt="'.$libroIndividual['Titulo'].'"></a>';
         echo '<div class="caption">';
            echo '<h4><a href="index.php?ctl=verLibrosIndividual&idLibro='.$libroIndividual['IdLibro'].'&nombreCategoria='.$libroIndividual['NombreCategoria'].'">
            '.$libroIndividual['Titulo'].'</a>';
            echo '</h4>';
            echo '<h4>Precio '.round($libroIndividual['PVP'] ,2)  .' €</h4>';
            echo '<p class="parrafoIzquierda">Sed lectus quam, imperdiet vitae nunc ut, tincidunt suscipit sapien. Donec sed turpis non dolor porta ullamcorper.</p>';
         echo '</div>';
            echo '<form class="formBusqueda" name="formBusquedaLibro" method="POST" action="index.php?ctl=verLibrosIndividual">';
                echo '<button type="submit" class="btn btn-default" name="verLibrosIndividual">Ver Libro</button>';
                echo '<input type="hidden" name="idLibro" value="'.$libroIndividual['IdLibro'].'">';
                echo '<input type="hidden" name="nombreCategoria" value="'.$libroIndividual['NombreCategoria'].'">';
            echo '</form>';
      echo '</div>';
   echo '</div>';
}//fin del foreach

?>



<?php $contenido = ob_get_clean() ?>
<?php include 'baseInicio.php' ?>
