<?php ob_start(); include './app/config/nl2br2.php'; ?>

<?php
echo '<h1>'.$libros[0]['NombreSubCategoria'].'</h1>';
foreach ($libros as $key => $libroIndividual) {
	echo '<div class="slag" style="width: 33.333333333333333333%;float: left;display:block;height:641px;margin-bottom:2em;margin-top:3em;">';
		echo '<div class="thumbnail">';
			echo '<a href="index.php?ctl=verLibrosIndividualUsuario&idLibro='.$libroIndividual['IdLibro'].'&nombreCategoria='.$libroIndividual['NombreCategoria'].'">
				<img src="'.$libroIndividual['Portada'].'" alt="'.$libroIndividual['Titulo'].'"></a>';
			echo '<div class="caption">';
				echo '<h4><a href="index.php?ctl=verLibrosIndividualUsuario&idLibro='.$libroIndividual['IdLibro'].'&nombreCategoria='.$libroIndividual['NombreCategoria'].'">
				'.$libroIndividual['Titulo'].'</a>';
				echo '</h4>';
				echo '<p  style="text-align:left">'.substr($libroIndividual['Descripcion'],0,120).'...</p>';
        echo '<p><strong>Precio :'.round($libroIndividual['PVP'],2).' €</strong></p>';
			echo '</div>';
				echo '<p class="lead text-center">';
					echo '<form class="formBusqueda" name="formBusquedaLibro" method="POST" action="index.php?ctl=verLibrosIndividualUsuario">';
						echo '<button type="submit" class="btn btn-default btn_comprar_detalle" name="comprarLibroBoton">
						   <span class="glyphicon glyphicon-shopping-cart"></span> Comprar</button>';
							echo '<input type="hidden" name="idLibro" value="'.$libroIndividual['IdLibro'].'">';
							echo '<input type="hidden" name="nombreCategoria" value="'.$libroIndividual['NombreCategoria'].'">';
					echo '</form>';
					echo '<form class="formBusqueda" name="formBusquedaLibro" method="POST" action="index.php?ctl=verLibrosIndividualUsuario">';
						echo '<button type="submit" class="btn btn-default" name="verLibrosIndividual">Ver Libro</button>';
						echo '<input type="hidden" name="idLibro" value="'.$libroIndividual['IdLibro'].'">';
						echo '<input type="hidden" name="nombreCategoria" value="'.$libroIndividual['NombreCategoria'].'">';
					echo '</form>';
				echo '</p>';
		echo '</div>';
   echo '</div>';
}//fin del foreach
?>

<?php $contenido = ob_get_clean() ?>
<?php include 'baseUsuario.php' ?>
