<?php ob_start(); include './app/config/nl2br2.php'; ?>

<?php
//$librosBuscar $resultadosBusqueda = $libros;
if($resultadosBusqueda != null){
	echo '<h1>HAY '.count($resultadosBusqueda).' RESULTADOS DE LA BUSQUEDA</h1>';
	foreach ($resultadosBusqueda as $key => $libroIndividual) {
		echo '<div class="slag" style="width: 33.333333333333333333%;float: left;display:block;height:641px;margin-bottom:2em;margin-top:3em;">';
			echo '<div class="thumbnail">';
				echo '<a href="index.php?ctl=verLibrosIndividual&idLibro='.$libroIndividual['ID_LIBRO'].'&nombreCategoria='.$libroIndividual['NOMBRE_CATEGORIA'].'">
				<img src="'.$libroIndividual['PORTADA_EJEMPLAR'].'" alt="'.$libroIndividual['TITULO_LIBRO'].'"></a>';
				echo '<div class="caption">';
					echo '<h4><a href="index.php?ctl=verLibrosIndividual&idLibro='.$libroIndividual['ID_LIBRO'].'&nombreCategoria='.$libroIndividual['NOMBRE_CATEGORIA'].'">
					'.$libroIndividual['TITULO_LIBRO'].'</a>';
					echo '</h4>';
					echo '<p  style="text-align:left">'.substr($libroIndividual['LIBRO_DESCRIPCION'],0,200).'...</p>';
          echo '<p><strong>Precio :'.round($libroIndividual['PVP_EJEMPLAR'],2).' €</strong></p>';
				echo '</div>';
        echo '<div class="ratings">';  
						echo '<p class="lead text-center">';
  					echo '<form class="formBusqueda" name="formBusquedaLibro" method="POST" action="index.php?ctl=verLibrosIndividual">';
  						echo '<button type="submit" class="btn btn-default" name="verLibrosIndividual">Ver Libro</button>';
  						echo '<input type="hidden" name="idLibro" value="'.$libroIndividual['ID_LIBRO'].'">';
  						echo '<input type="hidden" name="nombreCategoria" value="'.$libroIndividual['NOMBRE_CATEGORIA'].'">';
  					echo '</form>';
  				echo '</p>';
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
