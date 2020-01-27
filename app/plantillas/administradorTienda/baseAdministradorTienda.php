<!DOCTYPE html>
<html lang="en">
	<head>
		<title>Pagina Inicio visitante Gestión Libros </title>
		<meta charset="utf-8">
		<meta http-equiv="X-UA-Compatible" content="IE=edge">
		<meta name="viewport" content="width=device-width, initial-scale=1">
		<link rel="stylesheet" type="text/css" href="web/css/estilos.css" media="screen" />
		<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/4.7.0/css/font-awesome.min.css">
		<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.3.1/jquery.min.js"></script>
		<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>
		<link href="web/css/bootstrap.min.css" rel="stylesheet">
		<link rel="stylesheet" href="web/css/font-awesome.min.css">
		<link href="web/css/custom.css" rel="stylesheet">
		<script src="web/js/bootstrap.min.js"></script>
	</head>
	<body>
		<!-- INICIO NAV -->
		<nav class="navbar navbar-inverse">
			<div class="container-fluid">
				<a class="navbar-brand" href="#"><img class="imagenI" src="Imagenes/logo.png" style="width:160px;height:61px;"></a>
				<div class="collapse navbar-collapse" id="myNavbar">
					<ul class="nav navbar-nav">
						<li><a href="index.php?ctl=inicioAdministradorTienda">Inicio</a></li>
						<li><a href="index.php?ctl=verCategoriasAdministradorTienda">Categorias</a></li>
						<li><a href="index.php?ctl=verMiTienda">Mi tienda</a></li>
						<li class="dropdown">
							<a href="#"  class="dropdown-toggle" data-toggle="dropdown">Mi almacen<span class="caret"></span></a>
								<ul class="dropdown-menu">
									<li><a href="index.php?ctl=administrarAlmacenAdministradorTienda">Ver libros filtrados</a></li>
									<li><a href="index.php?ctl=verTodosMisLibrosAdministradorTienda">Ver todos mis libros</a></li>
								</ul>
						</li>
						<li class="dropdown">
							<a href="#"  class="dropdown-toggle" data-toggle="dropdown">Ventas<span class="caret"></span></a>
								<ul class="dropdown-menu">
									<li><a href="index.php?ctl=verVentasMiTienda">Ventas</a></li>
									<li><a href="index.php?ctl=verUsuariosCompras">Ver usuarios con compras</a></li>
								</ul>
						</li>
						<li class="dropdown">
							<a href="#"  class="dropdown-toggle" data-toggle="dropdown">Otros<span class="caret"></span></a>
								<ul class="dropdown-menu">
									<li><a href="index.php?ctl=verAutoresAdministradorTienda">Ver autores</a></li>
									<li><a href="index.php?ctl=verEditorialesAdministradorTiendas">Ver editoriales</a></li>
								</ul>
						</li>

						<li><a href="index.php?ctl=cerrarSesion">Cerrar Sesion</a></li>
					</ul>
					<form name="busquedaUsuarioRegistrado" class="navbar-form navbar-right" role="search" method="POST" action="index.php?ctl=busquedaTiendaAdministrador">
						<div class="form-group input-group">
							<input type="text" class="form-control" placeholder="Search.." value="" name="palabraBusqueda">
							<span class="input-group-btn">
								<button class="btn btn-default" type="submit">
									<span class="glyphicon glyphicon-search"></span>
								</button>
							</span>
						</div>
					</form>
				</div>
			</div>
		</nav>
		<!-- FIN NAV -->
		<div class="container text-center">
			<!-- PRINCIPIO LATERAL IZQUIERDA-->
			<?php include_once __DIR__ . "/../../../fuente/Repositorio/librosRepositorio.inc"; ?>
			<?php $librosCategoriasLateral = (new LibrosRepositorio)->librosCategoriasLateral();//es un multarray de 2 ?>
			<?php $librosSubCategoriasLateral = (new LibrosRepositorio)->librosSubCategoriasLateral();//es un multarray de 2 ?>
			<div class="col-sm-3 well">
				<div class="baseLibrosLateral">
					<?php
						$numeroC =0;
						foreach ($librosCategoriasLateral as $key1 => $categoria) {
							foreach ($categoria as $key2 => $propiedadCategoria) {
								if($key2 == 'NombreCategoria'){
									$nombreCategoria = $propiedadCategoria;
								}
								if($key2 == 'numero'){
									$cantidadCategoria = $propiedadCategoria;
								}
								if($key2 == 'IdCategoria'){
									$idCategoria = $propiedadCategoria;
								}
							}
							$numeroC++;
							echo '<form name="verSubcategoriasCat" class="formSubcategorias" method="GET"
								action="index.php?ctl=verSubcategorias_de_CategoriasAdministradorTienda&IdCategoria='.$idCategoria.'">';
									echo '<p style="color:red;">';
										echo '<button type="button" data-toggle="collapse" data-target="#demo'.$numeroC.'" style="border:none;background:none;">';
										echo '<i class="fa fa-book" style="font-size:24px"></i> '.$nombreCategoria.'  '.$cantidadCategoria.'';
										echo '</button>';
									echo '</p>';
							echo '</form>';

							//echo '<p style="color:red;"><a href="index.php?ctl=verSubcategorias_de_Categorias&IdCategoria='.$idCategoria.'"
							//style="color:red;"><i class="fa fa-book" style="font-size:24px"></i> '.$nombreCategoria.'</a>  '.$cantidadCategoria.'</p>';
							echo '<div id="demo'.$numeroC.'" class="collapse">';
							foreach ($librosSubCategoriasLateral as $key3 => $subCategoria) {
								foreach ($subCategoria as $key4 => $propiedadSubCategoria) {
									if($key4 == 'IdCategoria'){
										$bool =false;
										if($propiedadSubCategoria == $idCategoria){
											$bool=true;
										}
										if($bool){
											echo '<p style="color:blue;"><a href="index.php?ctl=verLibrosPorSubCategoriaAdministradorTienda&IdSubCategoria='.$subCategoria['IdSubCategoria'].'" >&nbsp;&nbsp;&nbsp;<i class="fa fa-book" style="font-size:12px"></i> '.$subCategoria['NombreSubCategoria'].'</a>  '.$subCategoria['numero'].'</p>';
										}
										$bool =false;
									}
								}
							}
							echo '</div>';
						}
					?>
				</div>
			</div>
			<!-- FIN LATERAL IZQUIERDA -->

			<!-- PRINCIPIO  MEDIO -->
			<div class="col-sm-12 col-md-9 col-lg-9 content-padding">
				<div><span class="errorRojo"><?= isset($error)?$error: null; ?></span></div>
				<!-- PRINCIPIO CONTENIDO -->
				<?= $contenido ?>
				<!-- FIN CONTENIDO -->


			</div>
			<!-- FIN MEDIO -->

			<!-- PRINCIPIO LATERAL DERECHA -->
			<div class="col-sm-2 well">
				<?php echo $_SESSION['userNombre'].' ,has iniciado sesión como '.$_SESSION['grupoUser'] ;?><br>
				<?php echo 'Tu tienda administrada es <strong>'.$_SESSION['nombreTienda'].'</strong>'; ?>
				<form name="accederUsuarios" class="formAccederUsuarios" method="POST" action="index.php?ctl=inicioUsuarioComprobar">
					<div class="container2">
						<h2>Acceso usuarios</h2>
						<div class="form-group">
							<label for="email">Email:</label>
							<input type="email" name="email" class="form-control" id="email" placeholder="Enter email">
						</div>
						<div class="form-group">
							<label for="pwd">Contraseña:</label>
							<input type="password" name="password" class="form-control" id="pwd" placeholder="Enter password">
						</div>
						<input type="hidden" name="usuarioActual" value="administradorTienda">
						<button type="submit" class="btn btn-default">Enviar</button>
					</div>
					<br><br>
				</form>
				<form name="modificarMiPerfilAdministradorTienda" class="modificarMiPerfilAdministradorTienda" method="POST" action="index.php?ctl=modificarMiPerfilAdministradorTienda">
							<button type="submit" class="btn btn-default">Modificar mi perfil</button>
					</form>
            </div>

			<!-- FIN LATERAL DERECHA -->


		</div> <!-- FIN CONTAINER TEXT CENTER -->
      </div> <!-- ESTE MIRAR PARA QUITAR -->

			<!-- PRINCIPIO FOOTER -->
			<footer class="footer-basic-centered">
				<p class="footer-links">
							<a href="index.php?ctl=inicioAdministradorTienda">Inicio</a>
							<a href="index.php?ctl=verCategoriasAdministradorTienda">Categorias</a>
							<a href="index.php?ctl=verMiTienda">Mi tienda</a>
							<a href="index.php?ctl=administrarAlmacenAdministradorTienda">Ver libros filtrados</a>
							<a href="index.php?ctl=verTodosMisLibrosAdministradorTienda">Ver todos mis libros</a>
							<a href="index.php?ctl=verVentasMiTienda">Ventas</a>
							<a href="index.php?ctl=verUsuariosCompras">Ver usuarios con compras</a>
							<a href="index.php?ctl=verAutoresAdministradorTienda">Ver autores</a>
							<a href="index.php?ctl=verEditorialesAdministradorTiendas">Ver editoriales</a>
							<a href="index.php?ctl=cerrarSesion">Cerrar Sesion</a>
				</p>
				<p class="footer-company-name">Tienda Punto y final 2018</p>
				<img class="imagenFooter" src="Imagenes/logo.png" style="width:160px;height:61px;">
			</footer>
			<!-- FIN FOOTER -->
   </body>
</html>
