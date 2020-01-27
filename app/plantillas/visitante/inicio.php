<?php
ob_start();
include './app/config/nl2br2.php';
?>

<?php
echo '<h1>Últimos libros introducidos</h1>';
foreach ($librosPaginaPrincipal as $key1 => $arrayLibro) {
    echo '<div class="row">';
    echo '<div class="col-xs-12 col-md-12 col-lg-12 content_home">';
    echo '<h2>' . $arrayLibro['Titulo'] . '</h2>';
    echo '<img class="pull-left book_home_r" src="' . $arrayLibro['Portada'] . '"
            "height="230px" width="300px" alt="Imagen de artículo" title="Imagen de artículo">'; //230x300//160x120
    echo '<p class="parrafoIzquierda">Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis pharetra varius quam sit amet vulputate.
               Quisque mauris augue, molestie tincidunt condimentum vitae, gravida a libero. Aenean sit amet felis
               dolor, in sagittis nisi. Sed ac orci quis tortor imperdiet venenatis. Duis elementum auctor accumsan.
               Aliquam in felis sit amet augue.
            </p><br>';

    echo '<p class="pull-center">
          <span><a href="index.php?ctl=verLibrosPorBoton&categoria='.$arrayLibro['NombreCategoria'].'&redireccion=visitante"><button type="button" class="btn btn-default">
          ' . $arrayLibro['NombreCategoria'] . '</button></a></span>
          <span><a href="index.php?ctl=verLibrosPorBoton&subCategoria='.$arrayLibro['NombreSubCategoria'].'&redireccion=visitante"><button type="button" class="btn btn-default">
          ' . $arrayLibro['NombreSubCategoria'] . '</button></a></span>
          <span><a href="index.php?ctl=verLibrosPorBoton&editorial='.$arrayLibro['NOMBRE_EDITORIAL'].'&redireccion=visitante"><button type="button" class="btn btn-default">Editorial:
          ' . $arrayLibro['NOMBRE_EDITORIAL'] . '</button></a></span></p><br>';
    echo '<ul class="list-inline">';
    echo '<li><a href="index.php?ctl=verLibrosPorBoton&yearPublicacion='.$arrayLibro['YearPublicacion'].'&redireccion=visitante"><button type="button" class="btn btn-default">Año publicación
    : ' . $arrayLibro['YearPublicacion'] . '</button></a></li>';
    echo '<li><a href="index.php?ctl=verLibrosPorBoton&autor='.$arrayLibro['nombre_autor'].'&redireccion=visitante"><button type="button" class="btn btn-default">Autor
    : ' . $arrayLibro['nombre_autor'] . '</button></a></li>';
    echo '<li><strong>Precio :' . round($arrayLibro['PVP'] ,2) . ' €</strong></li>';
    echo '</ul>';
    echo '<ul class="list-inline">';
    echo '<li>';
    echo '<form class="formBusqueda" name="formBusquedaLibro" method="POST" action="index.php?ctl=verLibrosIndividual">';
    echo '<button type="submit" class="btn btn-default" name="verLibrosIndividual">Ver Libro</button>';
    echo '<input type="hidden" name="nombreCategoria" value="' . $arrayLibro['NombreCategoria'] . '">';
    echo '<input type="hidden" name="idLibro" value="' . $arrayLibro['IdLibro'] . '">';
    echo '</form>';
    echo '</li>';
    echo '</ul>';

    echo '</div>';

    echo '</div>';
    echo '<hr>';
}

?>


<?php
$contenido = ob_get_clean()?>
<?php
include 'baseInicio.php';
?>
