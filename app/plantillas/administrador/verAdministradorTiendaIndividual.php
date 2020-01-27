<?php ob_start(); include './app/config/nl2br2.php'; ?>

<?php foreach ($usuario as $key => $value) {  ?>
        <h2>Datos del usuario</h2>
        <ul class="list-group">
            <li class="list-group-item" style="text-align:left;"><strong>Nick administrador : </strong><?php echo $value->getUsuario(); ?></li>
            <li class="list-group-item" style="text-align:left;"><strong>Nombre del administrador : </strong><?php echo $value->getNombre(); ?></li>
            <!-- no se puede desencriptar una contraseña hash-->
            <li class="list-group-item" style="text-align:left;"><strong>Primer apellido del administrador : </strong><?php echo $value->getPrimerApellido(); ?></li>
            <li class="list-group-item" style="text-align:left;"><strong>Segundo apellido del administrador : </strong><?php echo $value->getSegundoApellido(); ?></li>
            <li class="list-group-item" style="text-align:left;"><strong>Dirección del administrador : </strong><?php echo $value->getDireccion(); ?></li>
            <li class="list-group-item" style="text-align:left;"><strong>Ciudad del administrador : </strong><?php echo $ciudadUsuario; ?></li>
            <li class="list-group-item" style="text-align:left;"><strong>Teléfono del administrador : </strong><?php echo $value->getTelefono(); ?></li>
            <li class="list-group-item" style="text-align:left;"><strong>Nif del administrador : </strong><?php echo $value->getNif(); ?></li>
            <li class="list-group-item" style="text-align:left;"><strong>Email del administrador : </strong><?php echo $value->getEmail(); ?></li>
            <li class="list-group-item" style="text-align:left;"><strong>Fax del administrador : </strong><?php echo $value->getFax(); ?></li>
            <li class="list-group-item" style="text-align:left;"><strong>Tienda del administrador : </strong><?php echo $tiendaAdministrador; ?></li>
        </ul>
  <?php } ?>

<?php $contenido = ob_get_clean() ?>
<?php include 'baseAdministrador.php' ?>
