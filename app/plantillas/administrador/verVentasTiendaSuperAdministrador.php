<?php ob_start(); include './app/config/nl2br2.php'; ?>
<?php
$precioLinea=0; $precioTotal=0;$ventaSinPagar = 0;$ventaPagada =0;
//para la confirmacion
if($compras==null){
    $error = "La tienda ".$nombreTienda." todavía no tiene  compras.";
}else{
  $contador = 0;$error = "La tienda ".$nombreTienda." tiene las siguientes compras.";
	foreach ($compras as $key => $value) {
        $precioLinea =(float) $value['Cantidad']*$value['PVP'];
        echo '<table class="table table-bordered">';
			echo '<thead>';
				echo '<tr>';
          echo '<th>USUARIO</th>';
					echo '<th>LIBRO</th>';
					echo '<th>CANTIDAD</th>';
					echo '<th>PRECIO UNIDAD</th>';
          echo '<th>PRECIO TOTAL LINEA</th>';
          echo '<th>FECHA DE COMPRA</th>';
				echo '</tr>';
			echo '</thead>';
			echo '<tbody>';
				echo '<tr>';
          echo '<td>'.$value['Usuario'].'</td>';
					echo '<td>'.$arrayTitulos[$contador].'</td>';
					echo '<td>'.$value['Cantidad'].'</td>';
					echo '<td>'.round($value['PVP'],2).'</td>';
          echo '<td>'.$precioLinea.'</td>';
          echo '<td>'.$value['FechaCompra'].'</td>';
				echo '</tr>';
			echo '</tbody>';
		echo '</table>';
    if($value['Nulo']){
          if($value['Activo']){
              echo '<table>';
                  echo '<tr><td><strong>EL PEDIDO ESTA PENDIENTE DE PAGO Y ENTREGA</strong></td></tr>';
                  echo '<tr><td>';
                  echo '<form class="confirmarPagoLineasuperAdministrador" name="confirmarPagoLineasuperAdministrador" method="POST" action="index.php?ctl=confirmarPagoLineasuperAdministrador">';
                    echo '<button type="submit" class="btn btn-default" name="confirmarPagoLinea">Confirmar pago y entrega</button>';
                    echo '<input type="hidden" name="IdTienda" value="'.$value['IdTienda'].'">';
                    echo '<input type="hidden" name="IdVenta" value="'.$value['IdVenta'].'">';
                    echo '<input type="hidden" name="IdEjemplar" value="'.$value['IdEjemplar'].'">';
                    echo '<input type="hidden" name="nombreTienda" value="'.$nombreTienda.'">';
                  echo '</form>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;';
                  echo '<form class="anularLineaPedidoSuperAdministrador" name="anularLineaPedidoSuperAdministrador" method="POST" action="index.php?ctl=anularLineaPedidoSuperAdministrador">';
                      echo '<button type="submit" class="btn btn-default" name="anularLineaPedidoSuperAdministrador">Anular pedido</button>';
                      echo '<input type="hidden" name="IdTienda" value="'.$value['IdTienda'].'">';
                      echo '<input type="hidden" name="IdVenta" value="'.$value['IdVenta'].'">';
                      echo '<input type="hidden" name="IdEjemplar" value="'.$value['IdEjemplar'].'">';
                      echo '<input type="hidden" name="nombreTienda" value="'.$nombreTienda.'">';
                    echo '</form>';
                  echo '</td></tr>';
              echo '</table><br><br>';
              $ventaSinPagar += $precioLinea;
          }else{
              echo '<table>';
                  echo '<tr><td><strong>EL PEDIDO HA SIDO ENTREGADO Y PAGADO</strong></td></tr>';
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
include_once 'baseAdministrador.php';
?>
