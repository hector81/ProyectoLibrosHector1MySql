<?php ob_start(); include './app/config/nl2br2.php'; ?>

<?php
echo '<form class="formBusqueda" name="formBusquedaLibro" method="POST" action="index.php?ctl=comprarLibroUsuarioReserva">';
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
				echo '<p class="parrafoIzquierda"><strong>Precio: </strong> '.round($libroIndividual['PVP'] ,2) .' euros</p>';
				echo '<p class="parrafoIzquierda"><strong>Páginas:</strong> '.$libroIndividual['Paginas'].'</p>';
				echo '<p class="parrafoIzquierda"><strong>Encuadernacion :</strong> '.$libroIndividual['Encuadernacion'].'</p>';
				echo '<p class="parrafoIzquierda"><strong>Numero Edicion:</strong> '.$libroIndividual['Numero_Edicion'].'</p>';
				echo '<p class="parrafoIzquierda"><strong>Formato :</strong> '.$libroIndividual['Formato'].'</p>';
				echo '<p class="parrafoIzquierda"><strong>ISBN :</strong> '.$libroIndividual['ISBN'].'</p>';
				/////   descripcion
				echo '<div class="row">';
					echo '<div class="col-xs-12 col-md-12 col-lg-12">';
						echo '<h4><strong>Reseña</strong></h4>';
						echo '<p class="parrafoIzquierda">'.$libroIndividual['Descripcion'].'';
						echo '</p>';
					echo '</div>';
				echo '</div>';

			    echo '<p class="pull-center">
					<span><a href="index.php?ctl=verLibrosPorBoton&categoria='.$libroIndividual['Nombre_Categoria'].'&redireccion=usuario">
					<button type="button" class="btn btn-default">' . $libroIndividual['Nombre_Categoria'] . '</button></a></span>
					<span><a href="index.php?ctl=verLibrosPorBoton&subCategoria='.$libroIndividual['Nombre_SubCategoria'].'&redireccion=usuario">
					<button type="button" class="btn btn-default">' . $libroIndividual['Nombre_SubCategoria'] . '</button></a></span>
					<span><a href="index.php?ctl=verLibrosPorBoton&editorial='.$libroIndividual['NOMBRE_EDITORIAL'].'&redireccion=usuario">
					<button type="button" class="btn btn-default">Editorial:' . $libroIndividual['NOMBRE_EDITORIAL'] . '</button></a></span></p><br>';

			    echo '<div class="col-sm-12 col-md-12 col-lg-12">';
					echo '<label for="idTienda">Elige tienda de compra. En el selector encontraras la cantidad de libros disponibles por tienda  </label>';
					echo '<select id="idTienda" name="idTienda" class="idTienda">';
							echo "<option value=''>Selecciona tienda de compra</option>";
							$contador = 0;
							foreach ($tiendas as $key1 => $value1) {
								echo "<option value='".$value1->getIdTienda()."'>".$value1->getNombre()."
								.Libros disponibles en la tienda = ".$existenciasLibroPorTienda[$contador]." libros</option>";
								$contador++;
							}
					echo '</select>';
				echo '</div><br><br><br><br>';

				echo '<div class="col-sm-12 col-md-6 col-lg-6">';
					echo '<label for="cantidad">Cantidad a comprar  </label>';
					echo '<input type="number" value="0" name="cantidad" id="cantidad">';
				echo '</div>';

				echo '<p class="lead">';
					echo '<button type="submit" class="btn btn-default btn_comprar_detalle" name="comprarLibroBoton">
					<span class="glyphicon glyphicon-shopping-cart"></span> Comprar</button>';
					echo '<input type="hidden" name="idLibro" value="'.$libroIndividual['IdLibro'].'">';
					echo '<input type="hidden" name="IdEjemplar" value="'.$libroIndividual['IdEjemplar'].'">';
					echo '<input type="hidden" name="nombreCategoria" value="'.$libroIndividual['Nombre_Categoria'].'">';
				echo '</p>';

			echo '</div>';
		echo '</div>';
	echo '</div>';
echo '</form>';


?>




<?php $contenido = ob_get_clean() ?>
<?php include 'baseUsuario.php' ?>
