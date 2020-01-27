<?php
ob_start();
include './app/config/nl2br2.php';
?>
<h2>Administrador mi libreria</h2>
<div class="row">
	<div class="col-xs-12 col-md-12 col-lg-12 content_home">
		<div class="row">
            <!-- TIENDA -->
            <?php
                foreach ($miTienda as $key => $value) {
                    echo '<div class="slag" style="width:100%;">';
						echo '<div class="thumbnail">';
							echo '<a href="index.php?ctl=verTienda&idTienda='.$value->getIdTienda().'" ><img src="'.$value->getImagenTienda().'"
							alt="imagen de tienda" title="imagen de tienda"></a>';
							echo '<div class="caption">';
								echo '<h4><a href="index.php?ctl=verTienda&idTienda='.$value->getIdTienda().'" >'.$value->getNombre().'</a>';
								echo '</h4>';
								echo '<p class="mg_tiendas_p">Dirección : '.$value->getDireccion().'. Telefono : '.$value->getTelefono().'</p>';
								echo '<a href="index.php?ctl=modificarTiendaAdministradorTienda&idTienda=' . $value->getIdTienda(). '">';
								echo '<span class="glyphicon glyphicon-pencil"></span>';
								echo '</a>&nbsp;&nbsp;&nbsp;';
								echo '<a href="index.php?ctl=verTienda&idTienda=' . $value->getIdTienda(). '">';
								echo '<span class="glyphicon glyphicon-eye-open"></span>';
								echo '</a>&nbsp;&nbsp;&nbsp;';
							echo '</div>';
						echo '</div>';
					echo '</div>';
                }
            ?>
            <!-- TIENDA -->
		</div>
	</div>
</div>
<?php
$contenido = ob_get_clean()?>
<?php
include 'baseAdministradorTienda.php';
?>
