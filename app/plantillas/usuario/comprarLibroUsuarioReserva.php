<?php ob_start(); include './app/config/nl2br2.php'; ?>

<table class="table table-condensed">
    <thead>
		<tr>
			<th>LIBRO</th>
			<th>ISBN</th>
			<th>UNIDADES</th>
			<th>PRECIO UNIDAD</th>
		</tr>
	</thead>
    <tbody>
		<tr>
			<td><?php echo $libroIndividual['Titulo']; ?></td>
			<td><?php echo $libroIndividual['ISBN']; ?></td>
			<td><?php echo $cantidad; ?></td>
			<td><?php echo round($libroIndividual['PVP'],2) . ' €'; ?></td>
		</tr>
    </tbody>
    <thead>
		<tr>
			<th>TOTAL PRECIO DE LA RESERVA</th>
		</tr>
    </thead>
    <tbody>
		<tr>
			<td><?php $cantidadTotal = round(($libroIndividual['PVP']*$cantidad) ,2) ;echo $cantidadTotal . ' €'; ?></td>
		</tr>
		<tr>
			<form class="confirmarReservaUsuario" name="confirmarReservaUsuario" method="POST" action="index.php?ctl=confirmarReservaUsuario">';
				<?php echo '<input type="hidden" name="IdEjemplar" value="'.$libroIndividual['IdEjemplar'].'">' ?>
				<?php echo '<input type="hidden" name="idLibro" value="'.$libroIndividual['IdLibro'].'">' ?>
				<?php echo '<input type="hidden" name="cantidad" value="'.$cantidad.'">' ?>
				<?php echo '<input type="hidden" name="pReserva" value="'.$cantidadTotal.'">' ?>
				<?php echo '<input type="hidden" name="IdTienda" value="'.$idTienda.'">' ?>
        <?php echo '<input type="hidden" name="PVPlibro" value="'.$libroIndividual['PVP'].'">' ?>
                <button type="submit" class="btn btn-default btn_comprar_detalle" name="comprarLibroBoton">
				<span class="glyphicon glyphicon-thumbs-up"></span> Confirmar reserva</button>
			</form>
			<form class="cancelarReservaUsuario" name="cancelarReservaUsuario" method="POST" action="index.php?ctl=cancelarReservaUsuario">';
				<?php echo '<input type="hidden" name="IdEjemplar" value="'.$libroIndividual['IdEjemplar'].'">' ?>
				<?php echo '<input type="hidden" name="idLibro" value="'.$libroIndividual['IdLibro'].'">' ?>
				<?php echo '<input type="hidden" name="cantidad" value="'.$cantidad.'">' ?>
				<?php echo '<input type="hidden" name="pReserva" value="'.$cantidadTotal.'">' ?>
				<?php echo '<input type="hidden" name="IdTienda" value="'.$idTienda.'">' ?>
        <?php echo '<input type="hidden" name="PVPlibro" value="'.$libroIndividual['PVP'].'">' ?>
				<button type="submit" class="btn btn-default btn_comprar_detalle" name="comprarLibroBoton">
				<span class="glyphicon glyphicon-thumbs-down"></span> Cancelar reserva</button>
			</form>
		</tr>
    </tbody>
 </table>

<?php $contenido = ob_get_clean() ?>
<?php include 'baseUsuario.php' ?>
