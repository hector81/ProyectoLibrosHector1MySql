<?php ob_start(); include './app/config/nl2br2.php'; ?>
<?php
$contador = 0;$precioTotal=0;
//para la confirmacion
if($carrito==null){
    $error = "El carrito del usuario ".$_SESSION['userNombre']." está vacio.";
}else{
	foreach ($carrito as $key => $value) {
        echo '<table class="table table-bordered">';
			echo '<thead>';
				echo '<tr>';
					echo '<th>LIBRO</th>';
					echo '<th>CANTIDAD</th>';
					echo '<th>PRECIO TOTAL</th>';
					echo '<th>TIENDA DE COMPRA</th>';
					echo '<th>ACCIONES</th>';
				echo '</tr>';
			echo '</thead>';
			echo '<tbody>';
				echo '<tr>';
					echo '<td>'.$arrayTitulos[$contador].'</td>';
					echo '<td>'.$value->getCantidad().'</td>';
					echo '<td>'.$value->getPReserva().'</td>';
					echo '<td>'.$arrayTiendas[$contador].'</td>';
					echo '<td>';
						echo '<form action="index.php?ctl=borrarLineaDelCarrito" method="POST" name="borrarLineaDelCarrito">';
							echo '<input type="hidden" name="idEjemplar" value="'.$value->getIdEjemplar().'">';
              echo '<input type="hidden" name="IdTienda" value="'.$value->getIdTienda().'">';
              echo '<input type="hidden" name="cantidad" value="'.$value->getCantidad().'">';
							echo '<button type="submit" name="botonBorrado"><span class="glyphicon glyphicon-remove"></span></button>';
						echo '</form>';
					echo '</td>';
				echo '</tr>';
			echo '</tbody>';
		echo '</table>';
		$precioTotal += $value->getPReserva();
		$contador++;
    }
}

echo '<table class="table table-condensed">';
    echo '<thead>';
		echo '<tr>';
			echo '<th>PRECIO TOTAL CARRITO : '.$precioTotal.'</th>';
			echo '<th>';
				echo '<form action="index.php?ctl=borrarCarrito" method="POST" name="borrarCarrito">';
					echo '<input type="hidden" name="usuario" value="'.$_SESSION['userNombre'].'">';
					echo '<input type="submit" name="botonBorrar" value="Borrar carrito">';
				echo '</form>';
			echo '</th>';
			echo '<th>';
				echo '<form action="index.php?ctl=confirmarVenta" method="POST" name="confirmarVenta">';
					echo '<input type="hidden" name="usuario" value="'.$_SESSION['userNombre'].'">';
					echo '<input type="hidden" name="precioTotal" value="'.$precioTotal.'">';
					echo '<input type="submit" name="botonConfirmar" value="CONFIRMAR CARRITO">';
				echo '</form>';
			echo '</th>';
		echo '</tr>';
    echo '</thead>';
echo '</table>';
?>

<?php $contenido = ob_get_clean() ?>

<?php
include_once 'baseUsuario.php';
?>
