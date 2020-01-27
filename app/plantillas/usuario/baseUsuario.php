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
		<link rel="stylesheet" href="web/css/font-awesome.css">
		<link rel="stylesheet" href="web/css/fontawesome.min.css">
		<link href="web/css/custom.css" rel="stylesheet">
		<script src="web/js/bootstrap.min.js"></script>
	</head>
	<body>
		<!-- PRINCIPIO NAV -->
		<nav class="navbar navbar-inverse">
			<div class="container-fluid">
				<a class="navbar-brand" href="#"><img class="imagenI" src="Imagenes/logo.png" style="width:160px;height:61px;"></a>
				<div class="collapse navbar-collapse" id="myNavbar">
					<ul class="nav navbar-nav">
						<!-- <li class="active"><a href="index.php?ctl=inicioUsuario">Inicio</a></li> -->
						<li class="active"><a href="index.php?ctl=inicioUsuario">Inicio</a></li>
						<li class="dropdown">
							<a href="#"  class="dropdown-toggle" data-toggle="dropdown">Libros por materia<span class="caret"></span></a>
								<ul class="dropdown-menu">
									<li><a href="index.php?ctl=librosPorCategoriaUsuario">Libros por categoria</a></li>
									<li><a href="index.php?ctl=verAutoresUsuarios">Libros por autor</a></li>
									<li><a href="index.php?ctl=verEditorialesUsuario">Libros por editoriales</a></li>
								</ul>
						</li>
						<li><a href="index.php?ctl=verTiendasUsuario">Tiendas</a></li>
						<li><a href="index.php?ctl=busqueda">Busqueda</a></li>
						<li><a href="index.php?ctl=contactoUsuario">Contacto</a></li>
						<li class="dropdown">
							<a href="#"  class="dropdown-toggle" data-toggle="dropdown">Carrito<span class="caret"></span></a>
								<ul class="dropdown-menu">
									<li><a href="index.php?ctl=verCarrito">Carrito</a></li>
									<li><a href="index.php?ctl=verMisCompras">Ver mis compras</a></li>
								</ul>
						</li>
						<li><a href="index.php?ctl=cerrarSesion">Cerrar Sesion</a></li>
					</ul>
					<form name="busquedaUsuarioRegistrado" class="navbar-form navbar-right" role="search" method="POST" action="index.php?ctl=busquedaUsuarioRegistrado">
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
		<!-- PRINCIPIO CONTAINER TEXT -->
		<div class="container text-center">
			<div class="row">
            <!-- LATERAL -->
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
                          action="index.php?ctl=verSubcategorias_de_CategoriasUsuario&IdCategoria='.$idCategoria.'">';
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
                                           echo '<p style="color:blue;"><a href="index.php?ctl=verLibrosPorSubCategoriaUsuario&IdSubCategoria='.$subCategoria['IdSubCategoria'].'" >&nbsp;&nbsp;&nbsp;<i class="fa fa-book" style="font-size:12px"></i> '.$subCategoria['NombreSubCategoria'].'</a>  '.$subCategoria['numero'].'</p>';
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
            <!-- FIN LATERAL -->
            <div class="col-sm-12 col-md-9 col-lg-9 content-padding">
               <div><span class="errorRojo"><?= isset($error)?$error: null; ?></span></div>
               <?= $contenido ?>
            </div>
            <div class="col-sm-2 well">
								<?php echo $_SESSION['userNombre'].' ,has iniciado sesión como '.$_SESSION['grupoUser'] ;?><br>
	            

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
                   <input type="hidden" name="usuarioActual" value="usuario">
                   <button type="submit" class="btn btn-default">Enviar</button>
               </div>
							 <br><br>
               </form>
							 <form name="modificarMiPerfilUsuario" class="modificarMiPerfilUsuario" method="POST" action="index.php?ctl=modificarMiPerfilUsuario">
                   <button type="submit" class="btn btn-default">Modificar mi perfil</button>
               </form>
            </div>
         </div>
      </div>
      <footer class="footer-basic-centered">
         <p class="footer-links">
					 		<a href="index.php?ctl=inicioUsuario" style="margin-top:1em;">Inicio</a>
							<a href="index.php?ctl=librosPorCategoriaUsuario" style="margin-top:1em;">Libros por categoria</a>
							<a href="index.php?ctl=verAutoresUsuarios" style="margin-top:1em;">Libros por autor</a>
							<a href="index.php?ctl=verEditorialesUsuario" style="margin-top:1em;">Libros por editoriales</a>
							<a href="index.php?ctl=verTiendasUsuario" style="margin-top:1em;">Tiendas</a>
							<a href="index.php?ctl=busqueda" style="margin-top:1em;">Busqueda</a>
							<a href="index.php?ctl=contactoUsuario" style="margin-top:1em;">Contacto</a>
							<a href="index.php?ctl=verCarrito" style="margin-top:1em;">Carrito</a>
							<a href="index.php?ctl=verMisCompras" style="margin-top:1em;">Ver mis compras</a>
							<a href="index.php?ctl=cerrarSesion" style="margin-top:1em;">Cerrar Sesion</a>
							<a href="index.php?ctl=cerrarSesion" style="margin-top:1em;">Cerrar Sesion</a>
         </p>
         <p class="footer-company-name">Tienda Punto y final 2018</p>
         <img class="imagenFooter" src="Imagenes/logo.png" style="width:160px;height:61px;">
      </footer>
   </body>
</html>
