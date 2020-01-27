<?php ob_start(); include './app/config/nl2br2.php'; ?>


<?php
echo '<div class="col-xs-12 col-md-12 col-lg-12 content_home">';
    echo '<div class="row">';
         echo '<div class="col-xs-12 col-md-12 col-lg-12">';
               echo '<h2>'.$libroIndividual['Titulo'].'</h2>';
               echo '<img class="pull-left book_home_r" src="'.$libroIndividual['Portada'].'" alt="imagen de artículo" title="imagen de artículo">';
               echo '<p class="parrafoIzquierda"><strong>Año de edición:</strong> '.$libroIndividual['YearPublicacion'].'</p>';
               echo '<p class="parrafoIzquierda"><strong>Nombre autor :</strong> '.$libroIndividual['nombre_autor'].'</p>';
               echo '<p class="parrafoIzquierda"><strong>Categoria :</strong> '.$libroIndividual['Nombre_Categoria'].'</p>';
               echo '<p class="parrafoIzquierda"><strong>Nombre SubCategoria :</strong> '.$libroIndividual['Nombre_SubCategoria'].'</p>';
               echo '<p class="parrafoIzquierda"><strong>Idioma:</strong> '.$libroIndividual['Idioma'].'</p>';
               echo '<p class="parrafoIzquierda"><strong>Precio: </strong> '.round($libroIndividual['PVP'] ,2)  .' €</p>';
               echo '<p class="parrafoIzquierda"><strong>Páginas:</strong> '.$libroIndividual['Paginas'].'</p>';
               echo '<p class="parrafoIzquierda"><strong>Encuadernacion :</strong> '.$libroIndividual['Encuadernacion'].'</p>';
               echo '<p class="parrafoIzquierda"><strong>Numero Edicion:</strong> '.$libroIndividual['Numero_Edicion'].'</p>';
               echo '<p class="parrafoIzquierda"><strong>Formato :</strong> '.$libroIndividual['Formato'].'</p>';
               echo '<p class="parrafoIzquierda"><strong>ISBN :</strong> '.$libroIndividual['ISBN'].'</p>';
               echo '<div class="row">';
                  echo '<div class="col-xs-12 col-md-12 col-lg-12">';
                     echo '<h4><strong>Reseña</strong></h4>';
                     echo '<p class="parrafoIzquierda">'.$libroIndividual['Descripcion'].'';
                     echo '</p>';
                  echo '</div>';
               echo '</div>';

               echo '
                     <div class="btn-group">

                     <span><a href="index.php?ctl=verLibrosPorBoton&categoria='.$libroIndividual['Nombre_Categoria'].'&redireccion=visitante">
                     <button type="button" class="btn btn-default">
                     ' . $libroIndividual['Nombre_Categoria'] . '</button></a></span>

                     <span><a href="index.php?ctl=verLibrosPorBoton&subCategoria='.$libroIndividual['Nombre_SubCategoria'].'&redireccion=visitante">
                     <button type="button" class="btn btn-default">
                     ' . $libroIndividual['Nombre_SubCategoria'] . '</button></a></span>

                     <span><a href="index.php?ctl=verLibrosPorBoton&editorial='.$libroIndividual['NOMBRE_EDITORIAL'].'&redireccion=visitante">
                     <button type="button" class="btn btn-default">Editorial
                     ' . $libroIndividual['NOMBRE_EDITORIAL'] . '</button></a></span><br>
                     </button>
                     </div>';



               echo '</form>';
           echo '</div>';
       echo '</div>';
   echo '</div>';



?>




<?php $contenido = ob_get_clean() ?>
<?php include 'baseInicio.php' ?>
