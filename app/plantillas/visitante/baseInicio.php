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
      <nav class="navbar navbar-inverse">
         <div class="container-fluid">
            <a class="navbar-brand" href="#"><img class="imagenI" src="Imagenes/logo.png" style="width:160px;height:61px;"></a>
            <div class="collapse navbar-collapse" id="myNavbar">
               <ul class="nav navbar-nav">
                  <!-- <li class="active"><a href="index.php?ctl=inicio">Inicio</a></li> -->
                  <li><a href="index.php?ctl=inicio">Inicio</a></li>
                  <li class="dropdown">
                     <a href="#"  class="dropdown-toggle" data-toggle="dropdown">Libros por materia<span class="caret"></span></a>
                     <ul class="dropdown-menu">
                        <li><a href="index.php?ctl=librosPorCategoria">Categorias</a></li>
                     </ul>
                  </li>
                  <li><a href="index.php?ctl=tiendas">Tiendas</a></li>
                  <li class="dropdown">
      							<a href="#"  class="dropdown-toggle" data-toggle="dropdown">Otros<span class="caret"></span></a>
      								<ul class="dropdown-menu">
      									<li><a href="index.php?ctl=verAutoresVisitante">Ver autores</a></li>
      									<li><a href="index.php?ctl=verEditorialesVisitante">Ver editoriales</a></li>
      								</ul>
      						</li>
                  <li><a href="index.php?ctl=busquedaAvanzada">Busqueda</a></li>
                  <li><a href="index.php?ctl=contacto">Contacto</a></li>
                  <li><a href="index.php?ctl=formularioInscripcion">Apuntate</a></li>
               </ul>
               <form name="busquedaVisitante" class="navbar-form navbar-right" role="search" method="POST" action="index.php?ctl=busquedaVisitante">
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
      <div class="container text-center">
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
                       action="index.php?ctl=verSubcategorias_de_Categorias&IdCategoria='.$idCategoria.'">';
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
                                        echo '<p style="color:blue;"><a href="index.php?ctl=verLibrosPorSubCategoria&IdSubCategoria='.$subCategoria['IdSubCategoria'].'" >&nbsp;&nbsp;&nbsp;<i class="fa fa-book" style="font-size:12px"></i> '.$subCategoria['NombreSubCategoria'].'</a>  '.$subCategoria['numero'].'</p>';
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
            <?php echo 'Sesión iniciada como visitante. Para adquirir libros necesitas estar registrado. '; ?><br>


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
                <input type="hidden" id="usuarioActual" name="usuarioActual" value="visitante">
                <button type="submit" class="btn btn-default">Enviar</button>
                </div>
            </form>
         </div>
      </div>
      </div>
      <footer class="footer-basic-centered">
         <p class="footer-links">
             <a href="index.php?ctl=inicio" style="margin-top:1em;">Inicio</a>
    			   <a href="index.php?ctl=librosPorCategoria" style="margin-top:1em;">Categorias</a>
    			   <a href="index.php?ctl=tiendas" style="margin-top:1em;">Tiendas</a>
    			   <a href="index.php?ctl=verAutoresVisitante" style="margin-top:1em;">Ver autores</a>
    			   <a href="index.php?ctl=verEditorialesVisitante" style="margin-top:1em;">Ver editoriales</a>
    			   <a href="index.php?ctl=busquedaAvanzada" style="margin-top:1em;">Busqueda</a>
    			   <a href="index.php?ctl=contacto" style="margin-top:1em;">Contacto</a>
    			   <a href="index.php?ctl=formularioInscripcion" style="margin-top:1em;">Apuntate</a>
         </p>
         <p class="footer-company-name">Tienda Punto y final 2018</p>
         <img class="imagenFooter" src="Imagenes/logo.png" style="width:160px;height:61px;">
      </footer>
   </body>
</html>
