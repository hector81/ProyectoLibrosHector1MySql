<?php
ob_start();
include './app/config/nl2br2.php';
?>
<?php
echo '<h1>LIBROS ALMACEN</h1>';
foreach ($librosAlmacen as $key => $libros) {
  echo '<div class="slag" style="width: 33.333333333333333333%;float: left;display:block;height:641px;margin-bottom:2em;margin-top:3em;">';
      echo '<div class="thumbnail">';
         echo '<p><strong>STOCK DE ARTICULO EN TIENDA :</strong> '.$libros['ALMACEN_STOCK'].' ARTICULOS</p>';
         echo '<a href="index.php?ctl=verLibrosIndividualAdministrador&idLibro='.$libros['LIBROS_IDLIBRO'].'&nombreCategoria='.$libros['NOMBRE_CATEGORIA'].'">
         <img src="'.$libros['EJEMPLARES_PORTADA'].'" alt="'.$libros['LIBRO_TITULO'].'"></a>';
         echo '<div class="caption">';
            echo '<h4><a href="index.php?ctl=verLibrosIndividualAdministrador&idLibro='.$libros['LIBROS_IDLIBRO'].'&nombreCategoria='.$libros['NOMBRE_CATEGORIA'].'">
            '.$libros['LIBRO_TITULO'].'</a>';
            echo '</h4>';
         echo '</div>';
            echo '<form class="formModificacionStock" name="formModificacionStock" method="POST" action="index.php?ctl=modificarStockTienda">';
                echo 'Pon nuevo stock <input type="number" name="stockModificado" value="'.$libros['ALMACEN_STOCK'].'">';
                echo '<button type="submit" class="btn btn-default" name="modificarStockTienda">Modificar stock</button>';
                echo '<input type="hidden" name="idTienda" value="'.$idTienda.'">';
                echo '<input type="hidden" name="idEjemplar" value="'.$libros['EJEMPLARES_ID'].'">';
                echo '<input type="hidden" name="idSubcategoria" value="'.$libros['ID_SUBCATEGORIA'].'">';
                echo '<input type="hidden" name="idCategoria" value="'.$libros['ID_CATEGORIA'].'">';
            echo '</form>';
            echo '<form class="formBusqueda" name="formBusquedaLibro" method="POST" action="index.php?ctl=verLibrosIndividualAdministradorTienda">';
    					echo '<button type="submit" class="btn btn-default" name="verLibrosIndividual">Ver Libro</button>';
    					echo '<input type="hidden" name="idLibro" value="'.$libros['LIBROS_IDLIBRO'].'">';
    					echo '<input type="hidden" name="nombreCategoria" value="'.$libros['NOMBRE_CATEGORIA'].'">';
    				echo '</form>';
      echo '</div>';
   echo '</div>';
}//fin del foreach

?>

<?php
$contenido = ob_get_clean()?>
<?php
include 'baseAdministradorTienda.php';
?>
