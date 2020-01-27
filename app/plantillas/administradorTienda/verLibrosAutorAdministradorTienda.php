<?php ob_start(); include './app/config/nl2br2.php'; ?>
<?php
echo '<h1>Libros del autor '.$nombreAutor.'</h1>';
foreach ($libros as $key => $libroIndividual) {
	echo '<div class="slag" style="width: 33.333333333333333333%;float: left;display:block;height:641px;margin-bottom:2em;margin-top:3em;">';
		echo '<div class="thumbnail">';
			echo '<a href="index.php?ctl=verLibrosIndividualAdministradorTienda&idLibro='.$libroIndividual['LIBROS_IDLIBRO'].'&nombreCategoria='.$libroIndividual['NOMBRE_CATEGORIA'].'">
			<img src="'.$libroIndividual['EJEMPLARES_PORTADA'].'" alt="'.$libroIndividual['LIBRO_TITULO'].'"></a>';
			echo '<div class="caption">';
				echo '<h4><a href="index.php?ctl=verLibrosIndividualAdministradorTienda&idLibro='.$libroIndividual['LIBROS_IDLIBRO'].'&nombreCategoria='.$libroIndividual['NOMBRE_CATEGORIA'].'">
				'.$libroIndividual['LIBRO_TITULO'].'</a>';
				echo '</h4>';
				echo '<p  style="text-align:left">'.substr($libroIndividual['LIBRO_DESCRIPCION'],0,120).'...</p>';
        echo '<p><strong>Precio : '.round($libroIndividual['EJEMPLARES_PVP'],2).' €</strong></p>';
			echo '</div>';
				echo '<form class="formBusqueda" name="formBusquedaLibro" method="POST" action="index.php?ctl=verLibrosIndividualAdministradorTienda">';
					echo '<button type="submit" class="btn btn-default" name="verLibrosIndividual">Ver Libro</button>';
					echo '<input type="hidden" name="idLibro" value="'.$libroIndividual['LIBROS_IDLIBRO'].'">';
					echo '<input type="hidden" name="nombreCategoria" value="'.$libroIndividual['NOMBRE_CATEGORIA'].'">';
				echo '</form>';
				echo '<form class="formModificacionStock" name="formModificacionStock" method="POST" action="index.php?ctl=modificarStockTienda">';
						echo 'Pon nuevo stock <input type="number" name="stockModificado" value="'.$libroIndividual['ALMACEN_STOCK'].'">';
						echo '<button type="submit" class="btn btn-default" name="modificarStockTienda">Modificar stock</button>';
						echo '<input type="hidden" name="idTienda" value="'.$libroIndividual['ID_TIENDA'].'">';
						echo '<input type="hidden" name="idEjemplar" value="'.$libroIndividual['EJEMPLARES_ID'].'">';
						echo '<input type="hidden" name="idSubcategoria" value="'.$libroIndividual['ID_SUBCATEGORIA'].'">';
						echo '<input type="hidden" name="idCategoria" value="'.$libroIndividual['ID_CATEGORIA'].'">';
				echo '</form>';
		echo '</div>';
	echo '</div>';
}//fin del foreach

?>

<?php $contenido = ob_get_clean() ?>
<?php include 'baseAdministradorTienda.php' ?>
