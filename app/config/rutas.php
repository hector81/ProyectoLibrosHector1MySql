<?php

$mapeoRutas = array(
    //VISITANTE//////////////////////////////////////////////////////////////////////////////
    'inicio' =>
    array('controller' => 'usuarioController', 'action' => 'inicio'),
    'inicio' =>
    array('controller' => 'librosController', 'action' => 'librosPaginaPrincipal'),
    'busquedaVisitante' =>
    array('controller' => 'librosController', 'action' => 'busquedaVisitante'),
    'inicioUsuarioComprobar' =>
    array('controller' => 'usuarioController', 'action' => 'inicioUsuarioComprobar'),
    'verLibrosIndividual' =>
    array('controller' => 'librosController', 'action' => 'verLibrosIndividual'),
    'librosPorCategoria' =>
    array('controller' => 'CategoriasController', 'action' => 'librosPorCategoria'),
    'verSubcategorias_de_Categorias' =>
    array('controller' => 'subCategoriasController', 'action' => 'verSubcategorias_de_Categorias'),
    'verLibrosPorSubCategoria' =>
    array('controller' => 'librosController', 'action' => 'verLibrosPorSubCategoria'),
    'formularioInscripcion' =>
    array('controller' => 'usuarioController', 'action' => 'formularioInscripcion'),
    'tiendas' =>
    array('controller' => 'tiendasController', 'action' => 'tiendas'),
    'verTiendasIndividual' =>
    array('controller' => 'tiendasController', 'action' => 'verTiendasIndividual'),
    'contacto' =>
    array('controller' => 'usuarioController', 'action' => 'contacto'),
    'inscribirUsuarioNuevo' =>
    array('controller' => 'usuarioController', 'action' => 'inscribirUsuarioNuevo'),
    'enviarMensajeContacto' =>
    array('controller' => 'usuarioController', 'action' => 'enviarMensajeContacto'),
    'busquedaAvanzada' =>
    array('controller' => 'librosController', 'action' => 'busquedaAvanzada'),
    'resultadosBusquedaVisitante' =>
    array('controller' => 'librosController', 'action' => 'resultadosBusquedaVisitante'),
    'verAutoresVisitante' =>
    array('controller' => 'autoresController', 'action' => 'verAutoresVisitante'),
    'verLibrosAutorVisitante' =>
    array('controller' => 'autoresController', 'action' => 'verLibrosAutorVisitante'),
    'verEditorialesVisitante' =>
    array('controller' => 'editorialesController', 'action' => 'verEditorialesVisitante'),
    'verLibrosEditorialesVisitantes' =>
    array('controller' => 'editorialesController', 'action' => 'verLibrosEditorialesVisitantes'),
    'enviarMensajeContactoVisitante' =>
    array('controller' => 'usuarioController', 'action' => 'enviarMensajeContactoVisitante'),
    //USUARIO//////////////////////////////////////////////////////////////////////////////
    'inicioUsuario' =>
    array('controller' => 'usuarioController', 'action' => 'inicioUsuario'),
    'inicioUsuario' =>
    array('controller' => 'librosController', 'action' => 'librosPaginaPrincipalUsuario'),
    'cerrarSesion' =>
    array('controller' => 'usuarioController', 'action' => 'cerrarSesion'),
    'verLibrosIndividualUsuario' =>
    array('controller' => 'librosController', 'action' => 'verLibrosIndividualUsuario'),
    'librosPorCategoriaUsuario' =>
    array('controller' => 'CategoriasController', 'action' => 'librosPorCategoriaUsuario'),
    'verLibrosPorSubCategoriaUsuario' =>
    array('controller' => 'librosController', 'action' => 'verLibrosPorSubCategoriaUsuario'),
    'verSubcategorias_de_CategoriasUsuario' =>
    array('controller' => 'subCategoriasController', 'action' => 'verSubcategorias_de_CategoriasUsuario'),
    'busqueda' =>
    array('controller' => 'librosController', 'action' => 'busqueda'),
    'resultadosBusqueda' =>
    array('controller' => 'librosController', 'action' => 'resultadosBusqueda'),
    'comprarLibroUsuarioReserva' =>
    array('controller' => 'reservaController', 'action' => 'comprarLibroUsuarioReserva'),
    'busquedaUsuarioRegistrado' =>
    array('controller' => 'librosController', 'action' => 'busquedaUsuarioRegistrado'),
    'verLibrosPorBoton' =>
    array('controller' => 'ejemplaresController', 'action' => 'verLibrosPorBoton'),
    'confirmarReservaUsuario' =>
    array('controller' => 'librosReservadosController', 'action' => 'confirmarReservaUsuario'),
    'verCarrito' =>
    array('controller' => 'librosReservadosController', 'action' => 'verCarrito'),
    'cancelarReservaUsuario' =>
    array('controller' => 'reservaController', 'action' => 'cancelarReservaUsuario'),
    'borrarLineaDelCarrito' =>
    array('controller' => 'librosReservadosController', 'action' => 'borrarLineaDelCarrito'),
    'borrarCarrito' =>
    array('controller' => 'librosReservadosController', 'action' => 'borrarCarrito'),
    'confirmarVenta' =>
    array('controller' => 'ventaController', 'action' => 'confirmarVenta'),
    'verMisCompras' =>
    array('controller' => 'detallesVentaController', 'action' => 'verMisCompras'),
    'verTiendasUsuario' =>
    array('controller' => 'tiendasController', 'action' => 'verTiendasUsuario'),
    'contactoUsuario' =>
    array('controller' => 'usuarioController', 'action' => 'contactoUsuario'),
    'verAutoresUsuarios' =>
    array('controller' => 'autoresController', 'action' => 'verAutoresUsuarios'),
    'verLibrosAutorUsuario' =>
    array('controller' => 'autoresController', 'action' => 'verLibrosAutorUsuario'),
    'verEditorialesUsuario' =>
    array('controller' => 'editorialesController', 'action' => 'verEditorialesUsuario'),
    'verLibrosEditorialesUsuarios' =>
    array('controller' => 'editorialesController', 'action' => 'verLibrosEditorialesUsuarios'),
    'modificarMiPerfilUsuario' =>
    array('controller' => 'usuarioController', 'action' => 'modificarMiPerfilUsuario'),
    'modificarUsuarioUsuario' =>
    array('controller' => 'usuarioController', 'action' => 'modificarUsuarioUsuario'),
    'verTiendasUsuarioPorId' =>
    array('controller' => 'tiendasController', 'action' => 'verTiendasUsuarioPorId'),
    //ADMINISTRADORES SUPERADMINISTRADORES//////////////////////////////////////////////////////////////////////////////
    'inicioAdministrador' =>
    array('controller' => 'superAdministradorController', 'action' => 'inicioAdministrador'),
    'inicioAdministrador' =>
    array('controller' => 'librosController', 'action' => 'librosPaginaPrincipalAdministrador'),
    'administrarUsuarios' =>
    array('controller' => 'superAdministradorController', 'action' => 'administrarUsuarios'),
    'verLibrosIndividualAdministrador' =>
    array('controller' => 'librosController', 'action' => 'verLibrosIndividualAdministrador'),
    'verLibrosPorSubCategoriaAdministrador' =>
    array('controller' => 'librosController', 'action' => 'verLibrosPorSubCategoriaAdministrador'),
    'verSubcategorias_de_CategoriasAdministrador' =>
    array('controller' => 'subCategoriasController', 'action' => 'verSubcategorias_de_CategoriasAdministrador'),
    'borrarUsuarios' =>
    array('controller' => 'superAdministradorController', 'action' => 'borrarUsuarios'),
    'modificarUsuario' =>
    array('controller' => 'superAdministradorController', 'action' => 'modificarUsuario'),
    'enviarDatosModificacionUsuario' =>
    array('controller' => 'superAdministradorController', 'action' => 'enviarDatosModificacionUsuario'),
    'verCategoriasAdministrador' =>
    array('controller' => 'CategoriasController', 'action' => 'verCategoriasAdministrador'),
    'borrarCategoriaAdministrador' =>
    array('controller' => 'CategoriasController', 'action' => 'borrarCategoriaAdministrador'),
    'modificarCategoriaAdministrador' =>
    array('controller' => 'CategoriasController', 'action' => 'modificarCategoriaAdministrador'),
    'enviarDatosModificacionCategoria' =>
    array('controller' => 'CategoriasController', 'action' => 'enviarDatosModificacionCategoria'),
    'verSubCategoriasAdministrador' =>
    array('controller' => 'SubCategoriasController', 'action' => 'verSubCategoriasAdministrador'),
    'borrarSubCategoriaAdministrador' =>
    array('controller' => 'SubCategoriasController', 'action' => 'borrarSubCategoriaAdministrador'),
    'modificarSubCategoriaAdministrador' =>
    array('controller' => 'SubCategoriasController', 'action' => 'modificarSubCategoriaAdministrador'),
    'enviarDatosModificacionSubCategoria' =>
    array('controller' => 'SubCategoriasController', 'action' => 'enviarDatosModificacionSubCategoria'),
    'administrarTiendas' =>
    array('controller' => 'tiendasController', 'action' => 'administrarTiendas'),
    'borrarTiendaAdministradores' =>
    array('controller' => 'tiendasController', 'action' => 'borrarTiendaAdministradores'),
    'verTiendasIndividualAdministrador' =>
    array('controller' => 'tiendasController', 'action' => 'verTiendasIndividualAdministrador'),
    'modificarTiendaAdministrador' =>
    array('controller' => 'tiendasController', 'action' => 'modificarTiendaAdministrador'),
    'enviarDatosModificacionTienda' =>
    array('controller' => 'tiendasController', 'action' => 'enviarDatosModificacionTienda'),
    'insertarNuevaTiendaAdministrador' =>
    array('controller' => 'tiendasController', 'action' => 'insertarNuevaTiendaAdministrador'),
    'enviarDatosInsercionTienda' =>
    array('controller' => 'tiendasController', 'action' => 'enviarDatosInsercionTienda'),
    'librosPorCategoriaSuperAdministrador' =>
    array('controller' => 'CategoriasController', 'action' => 'librosPorCategoriaSuperAdministrador'),
    'verUsuarioIndividual' =>
    array('controller' => 'superAdministradorController', 'action' => 'verUsuarioIndividual'),
    'administrarAlmacen' =>
    array('controller' => 'almacenController', 'action' => 'administrarAlmacen'),
    'enviarDatosAlmacen' =>
    array('controller' => 'almacenController', 'action' => 'enviarDatosAlmacen'),
    'borrarSuperadministrador' =>
    array('controller' => 'superAdministradorController', 'action' => 'borrarSuperadministrador'),
    'borrarAdministrador' =>
    array('controller' => 'superAdministradorController', 'action' => 'borrarAdministrador'),
    'verAdministradorTiendaIndividual' =>
    array('controller' => 'superAdministradorController', 'action' => 'verAdministradorTiendaIndividual'),
    'verSuperAdministrador' =>
    array('controller' => 'superAdministradorController', 'action' => 'verSuperAdministrador'),
    'modificarAdministradorTienda' =>
    array('controller' => 'superAdministradorController', 'action' => 'modificarAdministradorTienda'),
    'modificarSuperAdministrador' =>
    array('controller' => 'superAdministradorController', 'action' => 'modificarSuperAdministrador'),
    'enviarDatosModificacionSuperAdministrador' =>
    array('controller' => 'superAdministradorController', 'action' => 'enviarDatosModificacionSuperAdministrador'),
    'enviarDatosModificacionAdministradorTienda' =>
    array('controller' => 'superAdministradorController', 'action' => 'enviarDatosModificacionAdministradorTienda'),
    'busquedaSuperAdministrador' =>
    array('controller' => 'librosController', 'action' => 'busquedaSuperAdministrador'),
    'modificarStockTienda' =>
    array('controller' => 'almacenController', 'action' => 'modificarStockTienda'),
    'administrarUsuariosRegistrados' =>
    array('controller' => 'superAdministradorController', 'action' => 'administrarUsuariosRegistrados'),
    'administrarAdministradoresTiendas' =>
    array('controller' => 'superAdministradorController', 'action' => 'administrarAdministradoresTiendas'),
    'administrarSuperAdministradores' =>
    array('controller' => 'superAdministradorController', 'action' => 'administrarSuperAdministradores'),
    'cambiarEstadoUsuario' =>
    array('controller' => 'superAdministradorController', 'action' => 'cambiarEstadoUsuario'),
    'cambiarEstadoAdministradorTienda' =>
    array('controller' => 'superAdministradorController', 'action' => 'cambiarEstadoAdministradorTienda'),
    'cambiarEstadoSuperAdministrador' =>
    array('controller' => 'superAdministradorController', 'action' => 'cambiarEstadoSuperAdministrador'),
    'enviarDatosModificacionAdministradorTienda' =>
    array('controller' => 'superAdministradorController', 'action' => 'enviarDatosModificacionAdministradorTienda'),
    'cambiarEstadoSuperAdministrador' =>
    array('controller' => 'superAdministradorController', 'action' => 'cambiarEstadoSuperAdministrador'),
    'inscribirUsuariosNuevos' =>
    array('controller' => 'superAdministradorController', 'action' => 'inscribirUsuariosNuevos'),
    'introducirUsuario' =>
    array('controller' => 'superAdministradorController', 'action' => 'introducirUsuario'),
    'introducirAdministradorTienda' =>
    array('controller' => 'superAdministradorController', 'action' => 'introducirAdministradorTienda'),
    'introducirSuperAdministrador' =>
    array('controller' => 'superAdministradorController', 'action' => 'introducirSuperAdministrador'),
    'enviarDatosIntroduccionSuperAdministrador' =>
    array('controller' => 'superAdministradorController', 'action' => 'enviarDatosIntroduccionSuperAdministrador'),
    'enviarDatosIntroduccionAdministradorTienda' =>
    array('controller' => 'superAdministradorController', 'action' => 'enviarDatosIntroduccionAdministradorTienda'),
    'enviarDatosIntroduccionUsuario' =>
    array('controller' => 'superAdministradorController', 'action' => 'enviarDatosIntroduccionUsuario'),
    'verTodasLasVentas' =>
    array('controller' => 'detallesVentaController', 'action' => 'verTodasLasVentas'),
    'modificarLibrosAdministrador' =>
    array('controller' => 'librosController', 'action' => 'modificarLibrosAdministrador'),
    'enviarDatosModificacionLibro' =>
    array('controller' => 'librosController', 'action' => 'enviarDatosModificacionLibro'),
    'introducirLibros' =>
    array('controller' => 'librosController', 'action' => 'introducirLibros'),
    'introducirAutores' =>
    array('controller' => 'autoresController', 'action' => 'introducirAutores'),
    'enviarDatosIntroduccionAutores' =>
    array('controller' => 'autoresController', 'action' => 'enviarDatosIntroduccionAutores'),
    'verAutores' =>
    array('controller' => 'autoresController', 'action' => 'verAutores'),
    'borrarAutorAdministrador' =>
    array('controller' => 'autoresController', 'action' => 'borrarAutorAdministrador'),
    'modificarAutorAdministrador' =>
    array('controller' => 'autoresController', 'action' => 'modificarAutorAdministrador'),
    'enviarDatosModificacionAutor' =>
    array('controller' => 'autoresController', 'action' => 'enviarDatosModificacionAutor'),
    'administrarEditoriales' =>
    array('controller' => 'editorialesController', 'action' => 'administrarEditoriales'),
    'modificarEditorialAdministrador' =>
    array('controller' => 'editorialesController', 'action' => 'modificarEditorialAdministrador'),
    'enviarDatosModificacionAdministradorEditorial' =>
    array('controller' => 'editorialesController', 'action' => 'enviarDatosModificacionAdministradorEditorial'),
    'introducirEditoriales' =>
    array('controller' => 'editorialesController', 'action' => 'introducirEditoriales'),
    'enviarDatosintroduccionAdministradorEditorial' =>
    array('controller' => 'editorialesController', 'action' => 'enviarDatosintroduccionAdministradorEditorial'),
    'enviarDatosIntroduccionIntroducciónLibros' =>
    array('controller' => 'librosController', 'action' => 'enviarDatosIntroduccionIntroducciónLibros'),
    'introducirCategoria' =>
    array('controller' => 'CategoriasController', 'action' => 'introducirCategoria'),
    'enviarDatosInsercionCategoria' =>
    array('controller' => 'CategoriasController', 'action' => 'enviarDatosInsercionCategoria'),
    'introducirSubCategoria' =>
    array('controller' => 'subCategoriasController', 'action' => 'introducirSubCategoria'),
    'enviarDatosInsercionSubCategoria' =>
    array('controller' => 'subCategoriasController', 'action' => 'enviarDatosInsercionSubCategoria'),
    'verVentasPorTiendaAdministrador' =>
    array('controller' => 'tiendasController', 'action' => 'verVentasPorTiendaAdministrador'),
    'verVentasTiendaSuperAdministrador' =>
    array('controller' => 'detallesVentaController', 'action' => 'verVentasTiendaSuperAdministrador'),
    'confirmarPagoLineasuperAdministrador' =>
    array('controller' => 'detallesVentaController', 'action' => 'confirmarPagoLineasuperAdministrador'),
    'anularLineaPedidoSuperAdministrador' =>
    array('controller' => 'detallesVentaController', 'action' => 'anularLineaPedidoSuperAdministrador'),
    'modificarMiPerfilSuperAdministrador' =>
    array('controller' => 'superAdministradorController', 'action' => 'modificarMiPerfilSuperAdministrador'),
    'borrarEditorialAdministrador' =>
    array('controller' => 'editorialesController', 'action' => 'borrarEditorialAdministrador'),
    'borrarLibroAdministrador' =>
    array('controller' => 'librosController', 'action' => 'borrarLibroAdministrador'),
    //ADMINISTRADOR TIENDAS//////////////////////////////////////////////////////////////////////////////
    'inicioAdministradorTienda' =>
    array('controller' => 'administradorTiendaController', 'action' => 'inicioAdministradorTienda'),
    'inicioAdministradorTienda' =>
    array('controller' => 'librosController', 'action' => 'librosPaginaPrincipalAdministradorTienda'),
    'verLibrosPorSubCategoriaAdministradorTienda' =>
    array('controller' => 'librosController', 'action' => 'verLibrosPorSubCategoriaAdministradorTienda'),
    'verMiTienda' =>
    array('controller' => 'administradorTiendaController', 'action' => 'verMiTienda'),
    'verTiendasIndividualAdministradorTienda' =>
    array('controller' => 'tiendasController', 'action' => 'verTiendasIndividualAdministradorTienda'),
    'modificarTiendaAdministradorTienda' =>
    array('controller' => 'tiendasController', 'action' => 'modificarTiendaAdministradorTienda'),
    'enviarDatosModificacionTiendaAdministrador' =>
    array('controller' => 'tiendasController', 'action' => 'enviarDatosModificacionTiendaAdministrador'),
    'administrarAlmacenAdministradorTienda' =>
    array('controller' => 'administradorTiendaController', 'action' => 'administrarAlmacenAdministradorTienda'),
    'verLibrosIndividualAdministradorTienda' =>
    array('controller' => 'librosController', 'action' => 'verLibrosIndividualAdministradorTienda'),
    'verCategoriasAdministradorTienda' =>
    array('controller' => 'CategoriasController', 'action' => 'verCategoriasAdministradorTienda'),
    'verSubcategorias_de_CategoriasAdministradorTienda' =>
    array('controller' => 'subCategoriasController', 'action' => 'verSubcategorias_de_CategoriasAdministradorTienda'),
    'busquedaTiendaAdministrador' =>
    array('controller' => 'librosController', 'action' => 'busquedaTiendaAdministrador'),
    'modificarPrecioAdministradorTienda' =>
    array('controller' => 'almacenController', 'action' => 'modificarPrecioAdministradorTienda'),
    'enviarDatosAlmacenAdministradorTienda' =>
    array('controller' => 'almacenController', 'action' => 'enviarDatosAlmacenAdministradorTienda'),
    'verTodosMisLibrosAdministradorTienda' =>
    array('controller' => 'almacenController', 'action' => 'verTodosMisLibrosAdministradorTienda'),
    'verAutoresAdministradorTienda' =>
    array('controller' => 'autoresController', 'action' => 'verAutoresAdministradorTienda'),
    'verLibrosAutorAdministradorTienda' =>
    array('controller' => 'autoresController', 'action' => 'verLibrosAutorAdministradorTienda'),
    'verEditorialesAdministradorTiendas' =>
    array('controller' => 'editorialesController', 'action' => 'verEditorialesAdministradorTiendas'),
    'verLibrosEditorialesAdministradorTiendas' =>
    array('controller' => 'editorialesController', 'action' => 'verLibrosEditorialesAdministradorTiendas'),
    'verVentasMiTienda' =>
    array('controller' => 'detallesVentaController', 'action' => 'verVentasMiTienda'),
    'verUsuariosCompras' =>
    array('controller' => 'ventaController', 'action' => 'verUsuariosCompras'),
    'confirmarPagoLinea' =>
    array('controller' => 'detallesVentaController', 'action' => 'confirmarPagoLinea'),
    'modificarMiPerfilAdministradorTienda' =>
    array('controller' => 'administradorTiendaController', 'action' => 'modificarMiPerfilAdministradorTienda'),
    'modificarMiPerfilAdministradorTiendaAdministrador' =>
    array('controller' => 'administradorTiendaController', 'action' => 'modificarMiPerfilAdministradorTiendaAdministrador'),
    'anularLineaPedido' =>
    array('controller' => 'detallesVentaController', 'action' => 'anularLineaPedido'),
    'verTienda' =>
    array('controller' => 'tiendasController', 'action' => 'verTienda'),
);


 ?>
