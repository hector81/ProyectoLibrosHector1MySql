<?php ob_start(); include './app/config/nl2br2.php'; ?>
<h4>Recuerda que tienes una semana para recoger tus pedidos. En caso contrario se te anularan</h4>
<?php
$precioLinea=0; $precioTotal=0;$ventaSinPagar = 0;$ventaPagada =0;
//para la confirmacion
if($compras==null){
    $error = "El usuario ".$_SESSION['userNombre']." no tiene  compras.";
}else{
  $contador = 0;$error = "El usuario ".$_SESSION['userNombre']." tiene las siguientes compras.";
	foreach ($compras as $key => $value) {
        $precioLinea =(float) $value['Cantidad']*$value['PVP'];
        echo '<table class="table table-bordered">';
			echo '<thead>';
				echo '<tr>';
					echo '<th>LIBRO</th>';
					echo '<th>CANTIDAD</th>';
					echo '<th>PRECIO UNIDAD</th>';
          echo '<th>PRECIO TOTAL LINEA</th>';
					echo '<th>TIENDA DE COMPRA</th>';
          echo '<th>FECHA DE COMPRA</th>';
				echo '</tr>';
			echo '</thead>';
			echo '<tbody>';
				echo '<tr>';
					echo '<td>'.$arrayTitulos[$contador].'</td>';
					echo '<td>'.$value['Cantidad'].'</td>';
					echo '<td>'.round($value['PVP'],2).'</td>';
          echo '<td>'.$precioLinea.'</td>';
					echo '<td>'.$arrayTiendas[$contador].'</td>';
          echo '<td>'.$value['FechaCompra'].'</td>';
				echo '</tr>';
			echo '</tbody>';
		echo '</table>';
    if($value['Nulo']){
          if($value['Activo']){
              echo '<table>';
                  echo '<tr><td><strong>PENDIENTE DE RECOGER Y DE PAGAR</strong></td></tr>';
              echo '</table><br><br>';
              $ventaSinPagar += $precioLinea;
          }else{
              echo '<table>';
                  echo '<tr><td><strong>PAGADO Y ENTREGADO</strong></td></tr>';
              echo '</table><br><br>';
              $ventaPagada += $precioLinea;
          }
    }else{
          echo '<table>';
              echo '<tr><td><strong>ESTE PEDIDO HA SIDO ANULADO</strong></td></tr>';
          echo '</table><br><br>';
          $precioLinea = 0;
    }


    $precioTotal += $precioLinea;
		$contador++;
    }
}

echo '<table class="table table-condensed">';
    echo '<thead>';
		echo '<tr>';
      echo '<th>VENTAS PENDIENTES DE PAGO: '.round($ventaSinPagar,2).'</th>';
      echo '<th>VENTAS PAGADAS: '.round($ventaPagada,2).'</th>';
			echo '<th>VENTAS TOTALES: '.round($precioTotal,2).'</th>';
		echo '</tr>';
    echo '</thead>';
echo '</table>';
?>


<?php $contenido = ob_get_clean() ?>

<?php
include_once 'baseUsuario.php';
?>
