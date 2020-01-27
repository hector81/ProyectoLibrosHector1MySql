<?php
ob_start();
include './app/config/nl2br2.php';
?>
<?php
echo '<h1>Últimos libros introducidos</h1>';
foreach ($librosPaginaPrincipal as $key1 => $arrayLibro) {
    echo '<form class="formBusqueda" name="formBusquedaLibro" method="POST" action="index.php?ctl=verLibrosIndividualAdministrador">';
    echo '<div class="row">';
    echo '<div class="col-xs-12 col-md-12 col-lg-12 content_home">';
    echo '<h2>' . $arrayLibro['Titulo'] . '</h2>';
    echo '<a href="detalle_articulo.html"><img class="pull-left book_home_r" src="' . $arrayLibro['Portada'] . '"
            "height="230px" width="300px" alt="Imagen de artículo" title="Imagen de artículo"></a>'; //230x300//160x120
    echo '<p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Duis pharetra varius quam sit amet vulputate.
               Quisque mauris augue, molestie tincidunt condimentum vitae, gravida a libero. Aenean sit amet felis
               dolor, in sagittis nisi. Sed ac orci quis tortor imperdiet venenatis. Duis elementum auctor accumsan.
               Aliquam in felis sit amet augue.
            </p>';
            echo '<p class="pull-center">
                    <span><button type="button" class="btn btn-default"><a href="index.php?ctl=verLibrosPorBoton&categoria='.$arrayLibro['NombreCategoria'].'&redireccion=superAdministrador">
                    ' . $arrayLibro['NombreCategoria'] . '</button></a></span>
                    <span><button type="button" class="btn btn-default"><a href="index.php?ctl=verLibrosPorBoton&subCategoria='.$arrayLibro['NombreSubCategoria'].'&redireccion=superAdministrador">
                    ' . $arrayLibro['NombreSubCategoria'] . '</button></a></span>
                    <span><button type="button" class="btn btn-default"><a href="index.php?ctl=verLibrosPorBoton&editorial='.$arrayLibro['NOMBRE_EDITORIAL'].'&redireccion=superAdministrador">Editorial:
                    ' . $arrayLibro['NOMBRE_EDITORIAL'] . '</button></a></span></p><br>';

            echo '<ul class="list-inline">';
            echo '<li><button type="button" class="btn btn-default"><a href="index.php?ctl=verLibrosPorBoton&yearPublicacion='.$arrayLibro['YearPublicacion'].'&redireccion=superAdministrador">Año publicación
            : ' . $arrayLibro['YearPublicacion'] . '</a></button></li>';
            echo '<li><button type="button" class="btn btn-default"><a href="index.php?ctl=verLibrosPorBoton&autor='.$arrayLibro['nombre_autor'].'&redireccion=superAdministrador">Autor
            : ' . $arrayLibro['nombre_autor'] . '</a></button></li>';
            echo '<li><strong>Precio :' . round($arrayLibro['PVP'] ,2) . ' €</strong></li>';
            echo '</ul>';
    echo '<button type="submit" class="btn btn-default" name="verLibrosIndividualAdministrador">Ver Libro</button>';
    echo '<input type="hidden" name="nombreCategoria" value="' . $arrayLibro['NombreCategoria'] . '">';
    echo '<input type="hidden" name="idLibro" value="' . $arrayLibro['IdLibro'] . '">';

    echo '</div>';

    echo '</div>';
    echo '</form>';
    echo '<hr>';
}

?>
<?php
$contenido = ob_get_clean()?>
<?php
include 'baseAdministrador.php';
?>
