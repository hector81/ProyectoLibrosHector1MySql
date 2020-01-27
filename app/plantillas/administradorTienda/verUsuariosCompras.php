<?php
ob_start();
include './app/config/nl2br2.php';
?>
<?php
echo '<h2>USUARIOS</h2>';
echo '<p>En esta tabla estan todos los usuario inscritos con compras en tu tienda</p>';
foreach ($listaUsuarios as $key1 => $value) {  
    echo '<table class="table table-condensed">';
        echo '<thead>';
            echo '<tr>';
                echo '<th style="word-break: break-all;">Nick</th>';
                echo '<th style="word-break: break-all;">Nombre</th>';
                echo '<th style="word-break: break-all;">Apellido</th>';
                echo '<th style="word-break: break-all;">Activo</th>';
                echo '<th style="word-break: break-all;">Nif</th>';
                echo '<th style="word-break: break-all;">Email</th>';
            echo '</tr>';
        echo '</thead>';
        echo '<tbody>';
            echo '<tr>';
                echo '<td style="word-break: break-all;">' . $value->getUsuario() . '</td>';
                echo '<td style="word-break: break-all;">' . $value->getNombre(). '</td>';
                echo '<td style="word-break: break-all;">' . $value->getPrimerApellido() . '</td>';
                echo '<td style="word-break: break-all;">';
                echo '</td>';
                echo '<td style="word-break: break-all;">' . $value->getNif() . '</td>';
                echo '<td style="word-break: break-all;">' . $value->getEmail() . '</td>';
            echo '</tr>';
      echo '</tbody>';
      echo '</table>';
}

?>



<?php
$contenido = ob_get_clean()?>
<?php
include 'baseAdministradorTienda.php';
?>
