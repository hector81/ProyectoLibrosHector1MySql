<?php
ob_start();
include './app/config/nl2br2.php';
?>
<?php
    echo '<form id="formInscribirUsuariosNuevos" name="formInscribirUsuariosNuevos" action="index.php?ctl=inscribirUsuariosNuevos" method="POST">';
        echo 'INSCRIBIR USUARIO NUEVO COMO: ';
        echo '<select id="tipoUsuario" name="tipoUsuario">';
            echo '<option value="3">Usuario</option>';
            echo '<option value="2">Administrador de Tienda</option>';
            echo '<option value="1">Super Administrador</option>';
        echo '</select>&nbsp;&nbsp;&nbsp;';
        echo '<input type="submit" name="enviarTipo" value="Enviar">';
    echo '</form>';
?>
<?php
foreach ($listaUsuarios as $key1 => $value) {
    if ($key1 == 'AdministradorTienda') {
            echo '<h2>ADMINISTRADORES TIENDAS</h2>';
            echo '<p>En esta tabla estan todos los administradores de tiendas inscritos</p>';
            echo '<table class="table table-condensed">';
            echo '<thead>';
            echo '<tr>';
            echo '<th style="word-break: break-all;">Nick</th>';
            echo '<th style="word-break: break-all;">Nombre</th>';
            echo '<th style="word-break: break-all;">Apellido</th>';
            echo '<th style="word-break: break-all;">Activo</th>';
            echo '<th style="word-break: break-all;">Nif</th>';
            echo '<th style="word-break: break-all;">Email</th>';
            echo '<th style="word-break: break-all;">Acciones</th>';
            echo '</tr>';
            echo '</thead>';
            echo '<tbody>';
            foreach ($value as $key => $tipoUsuario) {
                echo '<tr>';
                echo '<td style="word-break: break-all;">' . $tipoUsuario->getUsuario() . '</td>';
                echo '<td style="word-break: break-all;">' . $tipoUsuario->getNombre(). '</td>';
                echo '<td style="word-break: break-all;">' . $tipoUsuario->getPrimerApellido() . '</td>';
                echo '<td style="word-break: break-all;">';
                if($tipoUsuario->getActivo()){
                    echo '<a href="index.php?ctl=cambiarEstadoAdministradorTienda&email=' . $tipoUsuario->getEmail(). '&redireccion=listaCompleta&estado='.$tipoUsuario->getActivo().'">
                          <span class="glyphicon glyphicon-thumbs-up"></span></a>';
                }else{
                    echo '<a href="index.php?ctl=cambiarEstadoAdministradorTienda&email=' . $tipoUsuario->getEmail(). '&redireccion=listaCompleta&estado='.$tipoUsuario->getActivo().'">
                          <span class="glyphicon glyphicon-thumbs-down"></span></a>';
                }
                echo '</td>';
                echo '<td style="word-break: break-all;">' . $tipoUsuario->getNif() . '</td>';
                echo '<td style="word-break: break-all;">' . $tipoUsuario->getEmail() . '</td>';
                echo '<td style="word-break: break-all;">
                    <a href="index.php?ctl=modificarAdministradorTienda&email=' . $tipoUsuario->getEmail() . '&redireccion=listaCompleta">
                    <span class="glyphicon glyphicon-pencil"></span>
                    </a>
                    <a href="index.php?ctl=borrarAdministrador&email=' . $tipoUsuario->getEmail() . '&redireccion=listaCompleta">
                    <span class="glyphicon glyphicon-remove"></span>
                    </a>
                    <a href="index.php?ctl=verAdministradorTiendaIndividual&email=' . $tipoUsuario->getEmail() . '&redireccion=listaCompleta">
                    <span class="glyphicon glyphicon-eye-open"></span>
                    </a>
                    </td>';
                echo '</tr>';
            }
            echo '</tbody>';
            echo '</table>';

    }
    if ($key1 == 'Usuario') {
            echo '<h2>USUARIOS</h2>';
            echo '<p>En esta tabla estan todos los usuario inscritos:</p>';
            echo '<table class="table table-condensed">';
            echo '<thead>';
            echo '<tr>';
            echo '<th style="word-break: break-all;">Nick</th>';
            echo '<th style="word-break: break-all;">Nombre</th>';
            echo '<th style="word-break: break-all;">Apellido</th>';
            echo '<th style="word-break: break-all;">Activo</th>';
            echo '<th style="word-break: break-all;">Nif</th>';
            echo '<th style="word-break: break-all;">Email</th>';
            echo '<th style="word-break: break-all;">Acciones</th>';
            echo '</tr>';
            echo '</thead>';
            echo '<tbody>';
            foreach ($value as $key => $tipoUsuario) {
                echo '<tr>';
                echo '<td style="word-break: break-all;">' . $tipoUsuario->getUsuario() . '</td>';
                echo '<td style="word-break: break-all;">' . $tipoUsuario->getNombre(). '</td>';
                echo '<td style="word-break: break-all;">' . $tipoUsuario->getPrimerApellido() . '</td>';
                echo '<td style="word-break: break-all;">';
                if($tipoUsuario->getActivo()){
                    echo '<a href="index.php?ctl=cambiarEstadoUsuario&email=' . $tipoUsuario->getEmail(). '&redireccion=listaCompleta&estado='.$tipoUsuario->getActivo().'">
                          <span class="glyphicon glyphicon-thumbs-up"></span></a>';
                }else{
                    echo '<a href="index.php?ctl=cambiarEstadoUsuario&email=' . $tipoUsuario->getEmail(). '&redireccion=listaCompleta&estado='.$tipoUsuario->getActivo().'">
                          <span class="glyphicon glyphicon-thumbs-down"></span></a>';
                }
                echo '</td>';
                echo '<td style="word-break: break-all;">' . $tipoUsuario->getNif() . '</td>';
                echo '<td style="word-break: break-all;">' . $tipoUsuario->getEmail() . '</td>';
                echo '<td style="word-break: break-all;">
                  <a href="index.php?ctl=modificarUsuario&email=' . $tipoUsuario->getEmail(). '&redireccion=listaCompleta">
                  <span class="glyphicon glyphicon-pencil"></span>
                  </a>
                  <a href="index.php?ctl=borrarUsuarios&email=' . $tipoUsuario->getEmail() . '&redireccion=listaCompleta">
                  <span class="glyphicon glyphicon-remove"></span>
                  </a>
                  <a href="index.php?ctl=verUsuarioIndividual&email=' . $tipoUsuario->getEmail() . '&redireccion=listaCompleta">
                  <span class="glyphicon glyphicon-eye-open"></span>
                  </a>
                  </td>';
                echo '</tr>';
            }
            echo '</tbody>';
            echo '</table>';
    }
    if ($key1 == 'SuperAdministrador') {
            echo '<h2>SUPER ADMINISTRADOR</h2>';
            echo '<p>En esta tabla estaN los super administradores:</p>';
            echo '<table class="table table-condensed">';
            echo '<thead>';
            echo '<tr>';
            echo '<th style="word-break: break-all;">Nick</th>';
            echo '<th style="word-break: break-all;">Nombre</th>';
            echo '<th style="word-break: break-all;">Apellido</th>';
            echo '<th style="word-break: break-all;">Activo</th>';
            echo '<th style="word-break: break-all;">Nif</th>';
            echo '<th style="word-break: break-all;">Email</th>';
            echo '<th style="word-break: break-all;">Acciones</th>';
            echo '</tr>';
            echo '</thead>';
            echo '<tbody>';
            foreach ($value as $key => $tipoUsuario) {
                echo '<tr>';
                echo '<td style="word-break: break-all;">' . $tipoUsuario->getUsuario() . '</td>';
                echo '<td style="word-break: break-all;">' . $tipoUsuario->getNombre(). '</td>';
                echo '<td style="word-break: break-all;">' . $tipoUsuario->getPrimerApellido() . '</td>';
                echo '<td style="word-break: break-all;">';
                if($tipoUsuario->getActivo()){
                    echo '<a href="index.php?ctl=cambiarEstadoSuperAdministrador&email=' . $tipoUsuario->getEmail(). '&redireccion=listaCompleta&estado='.$tipoUsuario->getActivo().'">
                          <span class="glyphicon glyphicon-thumbs-up"></span></a>';
                }else{
                    echo '<a href="index.php?ctl=cambiarEstadoSuperAdministrador&email=' . $tipoUsuario->getEmail(). '&redireccion=listaCompleta&estado='.$tipoUsuario->getActivo().'">
                          <span class="glyphicon glyphicon-thumbs-down"></span></a>';
                }
                echo '</td>';
                echo '<td style="word-break: break-all;">' . $tipoUsuario->getNif() . '</td>';
                echo '<td style="word-break: break-all;">' . $tipoUsuario->getEmail() . '</td>';
                echo '<td style="word-break: break-all;">
                  <a href="index.php?ctl=modificarSuperAdministrador&email=' . $tipoUsuario->getEmail() . '&redireccion=listaCompleta">
                  <span class="glyphicon glyphicon-pencil"></span>
                  </a>
                  <a href="index.php?ctl=borrarSuperadministrador&email=' . $tipoUsuario->getEmail() . '&redireccion=listaCompleta">
                  <span class="glyphicon glyphicon-remove"></span>
                  </a>
                  <a href="index.php?ctl=verSuperAdministrador&email=' . $tipoUsuario->getEmail(). '&redireccion=listaCompleta">
                  <span class="glyphicon glyphicon-eye-open"></span>
                  </a>
                  </td>';
                echo '</tr>';
            }
            echo '</tbody>';
            echo '</table>';
    }
}

?>



<?php
$contenido = ob_get_clean()?>
<?php
include 'baseAdministrador.php';
?>
