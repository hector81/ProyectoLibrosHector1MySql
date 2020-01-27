<?php

class EjemplaresRepositorio
{
    public function verLibrosPorYearUsuario(string $year) :array {
		$sql = "SELECT  DISTINCT LIBROS_IDLIBRO,ID_CATEGORIA,NOMBRE_CATEGORIA,ID_SUBCATEGORIA,NOMBRE_SUBCATEGORIA,EJEMPLARES_YEARPUBLICACION,EJEMPLARES_IDIOMA,
			EJEMPLARES_FECHA_DISPONIBILIDAD,AUTOR_NOMBRE,EJEMPLARES_ENCUADERNACION,EJEMPLARES_NUMERO_EDICION,EJEMPLARES_FORMATO
			,EJEMPLARES_ISBN,EJEMPLARES_PAGINAS,EJEMPLARES_PVP,LIBRO_DESCRIPCION,EJEMPLARES_PORTADA,EDITORIAL_NOMBRE,LIBRO_TITULO, EJEMPLARES_ID

			FROM librosBusquedaInicio WHERE EJEMPLARES_YEARPUBLICACION LIKE ?  ORDER BY LIBRO_TITULO ASC ;";
		$libro = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$year,PDO::PARAM_STR);
		$stmt->execute();
		while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
			$libro[] = [
				'LIBROS_IDLIBRO' => $row['LIBROS_IDLIBRO'],
				'ID_CATEGORIA' => $row['ID_CATEGORIA'],
				'NOMBRE_CATEGORIA' => $row['NOMBRE_CATEGORIA'],
				'ID_SUBCATEGORIA' => $row['ID_SUBCATEGORIA'],
				'NOMBRE_SUBCATEGORIA' => $row['NOMBRE_SUBCATEGORIA'],
				'EJEMPLARES_YEARPUBLICACION' => $row['EJEMPLARES_YEARPUBLICACION'],
				'EJEMPLARES_FECHA_DISPONIBILIDAD' => $row['EJEMPLARES_FECHA_DISPONIBILIDAD'],
				'AUTOR_NOMBRE' => $row['AUTOR_NOMBRE'],
				'EJEMPLARES_ENCUADERNACION' => $row['EJEMPLARES_ENCUADERNACION'],
				'EJEMPLARES_NUMERO_EDICION' => $row['EJEMPLARES_NUMERO_EDICION'],
				'EJEMPLARES_FORMATO' => $row['EJEMPLARES_FORMATO'],
				'EJEMPLARES_IDIOMA' => $row['EJEMPLARES_IDIOMA'],
				'EJEMPLARES_ISBN' => $row['EJEMPLARES_ISBN'],
				'EJEMPLARES_PAGINAS' => $row['EJEMPLARES_PAGINAS'],
				'EJEMPLARES_PVP' => $row['EJEMPLARES_PVP'],
				'LIBRO_DESCRIPCION' => $row['LIBRO_DESCRIPCION'],
				'EJEMPLARES_PORTADA' => $row['EJEMPLARES_PORTADA'],
				'EDITORIAL_NOMBRE' => $row['EDITORIAL_NOMBRE'],
				'LIBRO_TITULO' => $row['LIBRO_TITULO'],
        'EJEMPLARES_ID' => $row['EJEMPLARES_ID'],

			];
		}
		$con = null;
		$stmt = null;
		return $libro;
    }//fin metodo

    public function verLibrosPorAutorUsuario(string $autor) :array {
		$sql = "SELECT  DISTINCT LIBROS_IDLIBRO,ID_CATEGORIA,NOMBRE_CATEGORIA,ID_SUBCATEGORIA,NOMBRE_SUBCATEGORIA,EJEMPLARES_YEARPUBLICACION,EJEMPLARES_IDIOMA,
			EJEMPLARES_FECHA_DISPONIBILIDAD,AUTOR_NOMBRE,EJEMPLARES_ENCUADERNACION,EJEMPLARES_NUMERO_EDICION,EJEMPLARES_FORMATO
			,EJEMPLARES_ISBN,EJEMPLARES_PAGINAS,EJEMPLARES_PVP,LIBRO_DESCRIPCION,EJEMPLARES_PORTADA,EDITORIAL_NOMBRE,LIBRO_TITULO, EJEMPLARES_ID

			FROM librosBusquedaInicio WHERE AUTOR_NOMBRE LIKE ?  ORDER BY LIBRO_TITULO ASC;";
		$libro = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$autor,PDO::PARAM_STR);
		$stmt->execute();
		while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
			$libro[] = [
				'LIBROS_IDLIBRO' => $row['LIBROS_IDLIBRO'],
				'ID_CATEGORIA' => $row['ID_CATEGORIA'],
				'NOMBRE_CATEGORIA' => $row['NOMBRE_CATEGORIA'],
				'ID_SUBCATEGORIA' => $row['ID_SUBCATEGORIA'],
				'NOMBRE_SUBCATEGORIA' => $row['NOMBRE_SUBCATEGORIA'],
				'EJEMPLARES_YEARPUBLICACION' => $row['EJEMPLARES_YEARPUBLICACION'],
				'EJEMPLARES_FECHA_DISPONIBILIDAD' => $row['EJEMPLARES_FECHA_DISPONIBILIDAD'],
				'AUTOR_NOMBRE' => $row['AUTOR_NOMBRE'],
				'EJEMPLARES_ENCUADERNACION' => $row['EJEMPLARES_ENCUADERNACION'],
				'EJEMPLARES_NUMERO_EDICION' => $row['EJEMPLARES_NUMERO_EDICION'],
				'EJEMPLARES_FORMATO' => $row['EJEMPLARES_FORMATO'],
				'EJEMPLARES_IDIOMA' => $row['EJEMPLARES_IDIOMA'],
				'EJEMPLARES_ISBN' => $row['EJEMPLARES_ISBN'],
				'EJEMPLARES_PAGINAS' => $row['EJEMPLARES_PAGINAS'],
				'EJEMPLARES_PVP' => $row['EJEMPLARES_PVP'],
				'LIBRO_DESCRIPCION' => $row['LIBRO_DESCRIPCION'],
				'EJEMPLARES_PORTADA' => $row['EJEMPLARES_PORTADA'],
				'EDITORIAL_NOMBRE' => $row['EDITORIAL_NOMBRE'],
				'LIBRO_TITULO' => $row['LIBRO_TITULO'],
        'EJEMPLARES_ID' => $row['EJEMPLARES_ID'],

			];
		}
		$con = null;
		$stmt = null;
		return $libro;
    }//fin metodo

    public function verLibrosPorCategoriaUsuarioBoton(string $categoria) :array {
		$sql = "SELECT DISTINCT LIBROS_IDLIBRO,ID_CATEGORIA,NOMBRE_CATEGORIA,ID_SUBCATEGORIA,NOMBRE_SUBCATEGORIA,EJEMPLARES_YEARPUBLICACION,EJEMPLARES_IDIOMA,
			EJEMPLARES_FECHA_DISPONIBILIDAD,AUTOR_NOMBRE,EJEMPLARES_ENCUADERNACION,EJEMPLARES_NUMERO_EDICION,EJEMPLARES_FORMATO
			,EJEMPLARES_ISBN,EJEMPLARES_PAGINAS,EJEMPLARES_PVP,LIBRO_DESCRIPCION,EJEMPLARES_PORTADA,EDITORIAL_NOMBRE,LIBRO_TITULO, EJEMPLARES_ID

			FROM librosBusquedaInicio WHERE NOMBRE_CATEGORIA LIKE ?  ORDER BY LIBRO_TITULO ASC ;";
		$libro = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$categoria,PDO::PARAM_STR);
		$stmt->execute();
		while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
			$libro[] = [
				'LIBROS_IDLIBRO' => $row['LIBROS_IDLIBRO'],
				'ID_CATEGORIA' => $row['ID_CATEGORIA'],
				'NOMBRE_CATEGORIA' => $row['NOMBRE_CATEGORIA'],
				'ID_SUBCATEGORIA' => $row['ID_SUBCATEGORIA'],
				'NOMBRE_SUBCATEGORIA' => $row['NOMBRE_SUBCATEGORIA'],
				'EJEMPLARES_YEARPUBLICACION' => $row['EJEMPLARES_YEARPUBLICACION'],
				'EJEMPLARES_FECHA_DISPONIBILIDAD' => $row['EJEMPLARES_FECHA_DISPONIBILIDAD'],
				'AUTOR_NOMBRE' => $row['AUTOR_NOMBRE'],
				'EJEMPLARES_ENCUADERNACION' => $row['EJEMPLARES_ENCUADERNACION'],
				'EJEMPLARES_NUMERO_EDICION' => $row['EJEMPLARES_NUMERO_EDICION'],
				'EJEMPLARES_FORMATO' => $row['EJEMPLARES_FORMATO'],
				'EJEMPLARES_IDIOMA' => $row['EJEMPLARES_IDIOMA'],
				'EJEMPLARES_ISBN' => $row['EJEMPLARES_ISBN'],
				'EJEMPLARES_PAGINAS' => $row['EJEMPLARES_PAGINAS'],
				'EJEMPLARES_PVP' => $row['EJEMPLARES_PVP'],
				'LIBRO_DESCRIPCION' => $row['LIBRO_DESCRIPCION'],
				'EJEMPLARES_PORTADA' => $row['EJEMPLARES_PORTADA'],
				'EDITORIAL_NOMBRE' => $row['EDITORIAL_NOMBRE'],
				'LIBRO_TITULO' => $row['LIBRO_TITULO'],
        'EJEMPLARES_ID' => $row['EJEMPLARES_ID'],

			];
		}
		$con = null;
		$stmt = null;
		return $libro;
    }//fin metodo

    public function verLibrosPorSubCategoriaUsuarioBoton(string $subCategoria) :array {
		$sql = "SELECT DISTINCT LIBROS_IDLIBRO,ID_CATEGORIA,NOMBRE_CATEGORIA,ID_SUBCATEGORIA,NOMBRE_SUBCATEGORIA,EJEMPLARES_YEARPUBLICACION,EJEMPLARES_IDIOMA,
			EJEMPLARES_FECHA_DISPONIBILIDAD,AUTOR_NOMBRE,EJEMPLARES_ENCUADERNACION,EJEMPLARES_NUMERO_EDICION,EJEMPLARES_FORMATO
			,EJEMPLARES_ISBN,EJEMPLARES_PAGINAS,EJEMPLARES_PVP,LIBRO_DESCRIPCION,EJEMPLARES_PORTADA,EDITORIAL_NOMBRE,LIBRO_TITULO, EJEMPLARES_ID

			FROM librosBusquedaInicio WHERE NOMBRE_SUBCATEGORIA LIKE ?  ORDER BY LIBRO_TITULO ASC ;";
		$libro = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$subCategoria,PDO::PARAM_STR);
		$stmt->execute();
		while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
			$libro[] = [
				'LIBROS_IDLIBRO' => $row['LIBROS_IDLIBRO'],
				'ID_CATEGORIA' => $row['ID_CATEGORIA'],
				'NOMBRE_CATEGORIA' => $row['NOMBRE_CATEGORIA'],
				'ID_SUBCATEGORIA' => $row['ID_SUBCATEGORIA'],
				'NOMBRE_SUBCATEGORIA' => $row['NOMBRE_SUBCATEGORIA'],
				'EJEMPLARES_YEARPUBLICACION' => $row['EJEMPLARES_YEARPUBLICACION'],
				'EJEMPLARES_FECHA_DISPONIBILIDAD' => $row['EJEMPLARES_FECHA_DISPONIBILIDAD'],
				'AUTOR_NOMBRE' => $row['AUTOR_NOMBRE'],
				'EJEMPLARES_ENCUADERNACION' => $row['EJEMPLARES_ENCUADERNACION'],
				'EJEMPLARES_NUMERO_EDICION' => $row['EJEMPLARES_NUMERO_EDICION'],
				'EJEMPLARES_FORMATO' => $row['EJEMPLARES_FORMATO'],
				'EJEMPLARES_IDIOMA' => $row['EJEMPLARES_IDIOMA'],
				'EJEMPLARES_ISBN' => $row['EJEMPLARES_ISBN'],
				'EJEMPLARES_PAGINAS' => $row['EJEMPLARES_PAGINAS'],
				'EJEMPLARES_PVP' => $row['EJEMPLARES_PVP'],
				'LIBRO_DESCRIPCION' => $row['LIBRO_DESCRIPCION'],
				'EJEMPLARES_PORTADA' => $row['EJEMPLARES_PORTADA'],
				'EDITORIAL_NOMBRE' => $row['EDITORIAL_NOMBRE'],
				'LIBRO_TITULO' => $row['LIBRO_TITULO'],
        'EJEMPLARES_ID' => $row['EJEMPLARES_ID'],

			];
		}
		$con = null;
		$stmt = null;
		return $libro;
    }//fin metodo

    public function verLibrosPorEditorialUsuarioBoton(string $editorial) :array {
		$sql = "SELECT DISTINCT LIBROS_IDLIBRO,ID_CATEGORIA,NOMBRE_CATEGORIA,ID_SUBCATEGORIA,NOMBRE_SUBCATEGORIA,EJEMPLARES_YEARPUBLICACION,EJEMPLARES_IDIOMA,
			EJEMPLARES_FECHA_DISPONIBILIDAD,AUTOR_NOMBRE,EJEMPLARES_ENCUADERNACION,EJEMPLARES_NUMERO_EDICION,EJEMPLARES_FORMATO
			,EJEMPLARES_ISBN,EJEMPLARES_PAGINAS,EJEMPLARES_PVP,LIBRO_DESCRIPCION,EJEMPLARES_PORTADA,EDITORIAL_NOMBRE,LIBRO_TITULO, EJEMPLARES_ID

			FROM librosBusquedaInicio WHERE EDITORIAL_NOMBRE LIKE ? ORDER BY LIBRO_TITULO ASC ;";
		$libro = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$editorial,PDO::PARAM_STR);
		$stmt->execute();
		while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
			$libro[] = [
				'LIBROS_IDLIBRO' => $row['LIBROS_IDLIBRO'],
				'ID_CATEGORIA' => $row['ID_CATEGORIA'],
				'NOMBRE_CATEGORIA' => $row['NOMBRE_CATEGORIA'],
				'ID_SUBCATEGORIA' => $row['ID_SUBCATEGORIA'],
				'NOMBRE_SUBCATEGORIA' => $row['NOMBRE_SUBCATEGORIA'],
				'EJEMPLARES_YEARPUBLICACION' => $row['EJEMPLARES_YEARPUBLICACION'],
				'EJEMPLARES_FECHA_DISPONIBILIDAD' => $row['EJEMPLARES_FECHA_DISPONIBILIDAD'],
				'AUTOR_NOMBRE' => $row['AUTOR_NOMBRE'],
				'EJEMPLARES_ENCUADERNACION' => $row['EJEMPLARES_ENCUADERNACION'],
				'EJEMPLARES_NUMERO_EDICION' => $row['EJEMPLARES_NUMERO_EDICION'],
				'EJEMPLARES_FORMATO' => $row['EJEMPLARES_FORMATO'],
				'EJEMPLARES_IDIOMA' => $row['EJEMPLARES_IDIOMA'],
				'EJEMPLARES_ISBN' => $row['EJEMPLARES_ISBN'],
				'EJEMPLARES_PAGINAS' => $row['EJEMPLARES_PAGINAS'],
				'EJEMPLARES_PVP' => $row['EJEMPLARES_PVP'],
				'LIBRO_DESCRIPCION' => $row['LIBRO_DESCRIPCION'],
				'EJEMPLARES_PORTADA' => $row['EJEMPLARES_PORTADA'],
				'EDITORIAL_NOMBRE' => $row['EDITORIAL_NOMBRE'],
				'LIBRO_TITULO' => $row['LIBRO_TITULO'],
        'EJEMPLARES_ID' => $row['EJEMPLARES_ID'],

			];
		}
		$con = null;
		$stmt = null;
		return $libro;
    }//fin metodo


    public function insertarEjemplares(int $numeroEdicion,string $tipoEncuadernacion,
        string $fechaDisponibilidad,string $yearPublicacion,string $formato,int $idEditorial,string $idioma,string $isbn,
        int $paginas,float $PVP,array $subirFoto,
        int $ultimoIdLibroInsertado,array $categoria,array $subCategorias) :bool{
          include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
          $con = (new ConexionBaseDatos)->getConexion();
          $sql = "INSERT INTO Ejemplares(NumeroEdicion,Encuadernacion,FechaDisponibilidad,YearPublicacion,Formato
                ,IdEditorial,Idioma,ISBN,Paginas,PVP,Portada,IdLibro)
                VALUES(?,?,GETDATE(),?,?,?,?,?,?,?,?,?);";
          $boolEj= false;
          try{
              $con->beginTransaction();
              $stmt = $con->prepare($sql);
              $stmt->bindParam(1,$numeroEdicion,PDO::PARAM_INT);
              $stmt->bindParam(2,$tipoEncuadernacion,PDO::PARAM_STR);
              //$stmt->bindParam(3,$fechaDisponibilidad,PDO::PARAM_STR);
              $stmt->bindParam(3,$yearPublicacion,PDO::PARAM_STR);
              $stmt->bindParam(4,$formato,PDO::PARAM_STR);
              $stmt->bindParam(5,$idEditorial,PDO::PARAM_INT);
              $stmt->bindParam(6,$idioma,PDO::PARAM_STR);
              $stmt->bindParam(7,$isbn,PDO::PARAM_STR);
              $stmt->bindParam(8,$paginas,PDO::PARAM_INT);
              $stmt->bindParam(9,$PVP,PDO::PARAM_INT);
              ////PARA LA imagen
              $fotoF = $subirFoto['imagen'];//string
              $tipo = $subirFoto['tipo'];//string
              $rutaImagenSubida = 'Imagenes/'.$categoria[0]->getAlias().'/'.$subCategorias[0]->getAlias().'/'.$fotoF;
              if ( strpos($tipo, "gif") || strpos($tipo, "jpeg") || strpos($tipo, "jpg") || strpos($tipo, "png") || strpos($tipo, "bmp") ){
                  $stmt->bindParam(10,$rutaImagenSubida,PDO::PARAM_STR);
              }
              $stmt->bindParam(11,$ultimoIdLibroInsertado,PDO::PARAM_INT);
              if($stmt->execute()){
                  $boolEj = true;
              }
              $con->commit();
              return $boolEj;
          }catch(PDOException $ex){
            throw $ex;
            $con->rollBack();
          }finally{
            $con = null;
            $stmt = null;
          }
  	}//fin metodo

    public function comprobarISBNrepetido(string $isbn) :bool{
      $sql = "SELECT COUNT(ISBN) AS NUMERO FROM ejemplares WHERE ISBN = ?;";
      $respuesta = true;
      include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
      $con = (new ConexionBaseDatos)->getConexion();
      $stmt = $con->prepare($sql);
      $stmt->bindParam(1,$isbn,PDO::PARAM_STR);
      $stmt->execute();
      while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
        if($row['NUMERO'] >0){//Si es mayor que 0, tenia ISBN repetido
          $respuesta = false;
        }
      }
      $con = null;
      $stmt = null;
      return $respuesta;
    }//fin metodo



    public function verLibrosPorYearUsuarioTienda(string $year,int $idTienda) :array {
		$sql = "SELECT  DISTINCT LIBROS_IDLIBRO,ID_CATEGORIA,NOMBRE_CATEGORIA,ID_SUBCATEGORIA,NOMBRE_SUBCATEGORIA,EJEMPLARES_YEARPUBLICACION,EJEMPLARES_IDIOMA,
			EJEMPLARES_FECHA_DISPONIBILIDAD,AUTOR_NOMBRE,EJEMPLARES_ENCUADERNACION,EJEMPLARES_NUMERO_EDICION,EJEMPLARES_FORMATO
			,EJEMPLARES_ISBN,EJEMPLARES_PAGINAS,EJEMPLARES_PVP,LIBRO_DESCRIPCION,EJEMPLARES_PORTADA,EDITORIAL_NOMBRE,LIBRO_TITULO, EJEMPLARES_ID
      ,ALMACEN_STOCK,TIENDAS_ID
			FROM librosBusquedaInicio WHERE EJEMPLARES_YEARPUBLICACION LIKE ? AND TIENDAS_ID = ? ORDER BY LIBRO_TITULO ASC ;";
		$libro = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$year,PDO::PARAM_STR);
    $stmt->bindParam(2,$idTienda,PDO::PARAM_INT);
		$stmt->execute();
		while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
			$libro[] = [
				'LIBROS_IDLIBRO' => $row['LIBROS_IDLIBRO'],
				'ID_CATEGORIA' => $row['ID_CATEGORIA'],
				'NOMBRE_CATEGORIA' => $row['NOMBRE_CATEGORIA'],
				'ID_SUBCATEGORIA' => $row['ID_SUBCATEGORIA'],
				'NOMBRE_SUBCATEGORIA' => $row['NOMBRE_SUBCATEGORIA'],
				'EJEMPLARES_YEARPUBLICACION' => $row['EJEMPLARES_YEARPUBLICACION'],
				'EJEMPLARES_FECHA_DISPONIBILIDAD' => $row['EJEMPLARES_FECHA_DISPONIBILIDAD'],
				'AUTOR_NOMBRE' => $row['AUTOR_NOMBRE'],
				'EJEMPLARES_ENCUADERNACION' => $row['EJEMPLARES_ENCUADERNACION'],
				'EJEMPLARES_NUMERO_EDICION' => $row['EJEMPLARES_NUMERO_EDICION'],
				'EJEMPLARES_FORMATO' => $row['EJEMPLARES_FORMATO'],
				'EJEMPLARES_IDIOMA' => $row['EJEMPLARES_IDIOMA'],
				'EJEMPLARES_ISBN' => $row['EJEMPLARES_ISBN'],
				'EJEMPLARES_PAGINAS' => $row['EJEMPLARES_PAGINAS'],
				'EJEMPLARES_PVP' => $row['EJEMPLARES_PVP'],
				'LIBRO_DESCRIPCION' => $row['LIBRO_DESCRIPCION'],
				'EJEMPLARES_PORTADA' => $row['EJEMPLARES_PORTADA'],
				'EDITORIAL_NOMBRE' => $row['EDITORIAL_NOMBRE'],
				'LIBRO_TITULO' => $row['LIBRO_TITULO'],
        'EJEMPLARES_ID' => $row['EJEMPLARES_ID'],
        'ALMACEN_STOCK' => $row['ALMACEN_STOCK'],
        'TIENDAS_ID' => $row['TIENDAS_ID']
			];
		}
		$con = null;
		$stmt = null;
		return $libro;
    }//fin metodo

    public function verLibrosPorAutorUsuarioTienda(string $autor,int $idTienda) :array {
		$sql = "SELECT  LIBROS_IDLIBRO,ID_CATEGORIA,NOMBRE_CATEGORIA,ID_SUBCATEGORIA,NOMBRE_SUBCATEGORIA,EJEMPLARES_YEARPUBLICACION,EJEMPLARES_IDIOMA,
			EJEMPLARES_FECHA_DISPONIBILIDAD,AUTOR_NOMBRE,EJEMPLARES_ENCUADERNACION,EJEMPLARES_NUMERO_EDICION,EJEMPLARES_FORMATO
			,EJEMPLARES_ISBN,EJEMPLARES_PAGINAS,EJEMPLARES_PVP,LIBRO_DESCRIPCION,EJEMPLARES_PORTADA,EDITORIAL_NOMBRE,LIBRO_TITULO, EJEMPLARES_ID
      ,ALMACEN_STOCK,TIENDAS_ID
			FROM librosBusquedaInicio WHERE AUTOR_NOMBRE LIKE ?  AND TIENDAS_ID = ?  ORDER BY LIBRO_TITULO ASC;";
		$libro = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$autor,PDO::PARAM_STR);
    $stmt->bindParam(2,$idTienda,PDO::PARAM_INT);
		$stmt->execute();
		while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
			$libro[] = [
				'LIBROS_IDLIBRO' => $row['LIBROS_IDLIBRO'],
				'ID_CATEGORIA' => $row['ID_CATEGORIA'],
				'NOMBRE_CATEGORIA' => $row['NOMBRE_CATEGORIA'],
				'ID_SUBCATEGORIA' => $row['ID_SUBCATEGORIA'],
				'NOMBRE_SUBCATEGORIA' => $row['NOMBRE_SUBCATEGORIA'],
				'EJEMPLARES_YEARPUBLICACION' => $row['EJEMPLARES_YEARPUBLICACION'],
				'EJEMPLARES_FECHA_DISPONIBILIDAD' => $row['EJEMPLARES_FECHA_DISPONIBILIDAD'],
				'AUTOR_NOMBRE' => $row['AUTOR_NOMBRE'],
				'EJEMPLARES_ENCUADERNACION' => $row['EJEMPLARES_ENCUADERNACION'],
				'EJEMPLARES_NUMERO_EDICION' => $row['EJEMPLARES_NUMERO_EDICION'],
				'EJEMPLARES_FORMATO' => $row['EJEMPLARES_FORMATO'],
				'EJEMPLARES_IDIOMA' => $row['EJEMPLARES_IDIOMA'],
				'EJEMPLARES_ISBN' => $row['EJEMPLARES_ISBN'],
				'EJEMPLARES_PAGINAS' => $row['EJEMPLARES_PAGINAS'],
				'EJEMPLARES_PVP' => $row['EJEMPLARES_PVP'],
				'LIBRO_DESCRIPCION' => $row['LIBRO_DESCRIPCION'],
				'EJEMPLARES_PORTADA' => $row['EJEMPLARES_PORTADA'],
				'EDITORIAL_NOMBRE' => $row['EDITORIAL_NOMBRE'],
				'LIBRO_TITULO' => $row['LIBRO_TITULO'],
        'EJEMPLARES_ID' => $row['EJEMPLARES_ID'],
        'ALMACEN_STOCK' => $row['ALMACEN_STOCK'],
        'TIENDAS_ID' => $row['TIENDAS_ID']
			];
		}
		$con = null;
		$stmt = null;
		return $libro;
    }//fin metodo

    public function verLibrosPorCategoriaUsuarioBotonTienda(string $categoria,int $idTienda) :array {
		$sql = "SELECT  LIBROS_IDLIBRO,ID_CATEGORIA,NOMBRE_CATEGORIA,ID_SUBCATEGORIA,NOMBRE_SUBCATEGORIA,EJEMPLARES_YEARPUBLICACION,EJEMPLARES_IDIOMA,
			EJEMPLARES_FECHA_DISPONIBILIDAD,AUTOR_NOMBRE,EJEMPLARES_ENCUADERNACION,EJEMPLARES_NUMERO_EDICION,EJEMPLARES_FORMATO
			,EJEMPLARES_ISBN,EJEMPLARES_PAGINAS,EJEMPLARES_PVP,LIBRO_DESCRIPCION,EJEMPLARES_PORTADA,EDITORIAL_NOMBRE,LIBRO_TITULO, EJEMPLARES_ID
      ,ALMACEN_STOCK,TIENDAS_ID
			FROM librosBusquedaInicio WHERE NOMBRE_CATEGORIA LIKE ?  AND TIENDAS_ID = ?  ORDER BY LIBRO_TITULO ASC ;";
		$libro = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$categoria,PDO::PARAM_STR);
    $stmt->bindParam(2,$idTienda,PDO::PARAM_INT);
		$stmt->execute();
		while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
			$libro[] = [
				'LIBROS_IDLIBRO' => $row['LIBROS_IDLIBRO'],
				'ID_CATEGORIA' => $row['ID_CATEGORIA'],
				'NOMBRE_CATEGORIA' => $row['NOMBRE_CATEGORIA'],
				'ID_SUBCATEGORIA' => $row['ID_SUBCATEGORIA'],
				'NOMBRE_SUBCATEGORIA' => $row['NOMBRE_SUBCATEGORIA'],
				'EJEMPLARES_YEARPUBLICACION' => $row['EJEMPLARES_YEARPUBLICACION'],
				'EJEMPLARES_FECHA_DISPONIBILIDAD' => $row['EJEMPLARES_FECHA_DISPONIBILIDAD'],
				'AUTOR_NOMBRE' => $row['AUTOR_NOMBRE'],
				'EJEMPLARES_ENCUADERNACION' => $row['EJEMPLARES_ENCUADERNACION'],
				'EJEMPLARES_NUMERO_EDICION' => $row['EJEMPLARES_NUMERO_EDICION'],
				'EJEMPLARES_FORMATO' => $row['EJEMPLARES_FORMATO'],
				'EJEMPLARES_IDIOMA' => $row['EJEMPLARES_IDIOMA'],
				'EJEMPLARES_ISBN' => $row['EJEMPLARES_ISBN'],
				'EJEMPLARES_PAGINAS' => $row['EJEMPLARES_PAGINAS'],
				'EJEMPLARES_PVP' => $row['EJEMPLARES_PVP'],
				'LIBRO_DESCRIPCION' => $row['LIBRO_DESCRIPCION'],
				'EJEMPLARES_PORTADA' => $row['EJEMPLARES_PORTADA'],
				'EDITORIAL_NOMBRE' => $row['EDITORIAL_NOMBRE'],
				'LIBRO_TITULO' => $row['LIBRO_TITULO'],
        'EJEMPLARES_ID' => $row['EJEMPLARES_ID'],
        'ALMACEN_STOCK' => $row['ALMACEN_STOCK'],
        'TIENDAS_ID' => $row['TIENDAS_ID']
			];
		}
		$con = null;
		$stmt = null;
		return $libro;
    }//fin metodo

    public function verLibrosPorSubCategoriaUsuarioBotonTienda(string $subCategoria,int $idTienda) :array {
		$sql = "SELECT  LIBROS_IDLIBRO,ID_CATEGORIA,NOMBRE_CATEGORIA,ID_SUBCATEGORIA,NOMBRE_SUBCATEGORIA,EJEMPLARES_YEARPUBLICACION,EJEMPLARES_IDIOMA,
			EJEMPLARES_FECHA_DISPONIBILIDAD,AUTOR_NOMBRE,EJEMPLARES_ENCUADERNACION,EJEMPLARES_NUMERO_EDICION,EJEMPLARES_FORMATO
			,EJEMPLARES_ISBN,EJEMPLARES_PAGINAS,EJEMPLARES_PVP,LIBRO_DESCRIPCION,EJEMPLARES_PORTADA,EDITORIAL_NOMBRE,LIBRO_TITULO, EJEMPLARES_ID
      ,ALMACEN_STOCK,TIENDAS_ID
			FROM librosBusquedaInicio WHERE NOMBRE_SUBCATEGORIA LIKE ?  AND TIENDAS_ID = ?  ORDER BY LIBRO_TITULO ASC ;";
		$libro = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$subCategoria,PDO::PARAM_STR);
    $stmt->bindParam(2,$idTienda,PDO::PARAM_INT);
		$stmt->execute();
		while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
			$libro[] = [
				'LIBROS_IDLIBRO' => $row['LIBROS_IDLIBRO'],
				'ID_CATEGORIA' => $row['ID_CATEGORIA'],
				'NOMBRE_CATEGORIA' => $row['NOMBRE_CATEGORIA'],
				'ID_SUBCATEGORIA' => $row['ID_SUBCATEGORIA'],
				'NOMBRE_SUBCATEGORIA' => $row['NOMBRE_SUBCATEGORIA'],
				'EJEMPLARES_YEARPUBLICACION' => $row['EJEMPLARES_YEARPUBLICACION'],
				'EJEMPLARES_FECHA_DISPONIBILIDAD' => $row['EJEMPLARES_FECHA_DISPONIBILIDAD'],
				'AUTOR_NOMBRE' => $row['AUTOR_NOMBRE'],
				'EJEMPLARES_ENCUADERNACION' => $row['EJEMPLARES_ENCUADERNACION'],
				'EJEMPLARES_NUMERO_EDICION' => $row['EJEMPLARES_NUMERO_EDICION'],
				'EJEMPLARES_FORMATO' => $row['EJEMPLARES_FORMATO'],
				'EJEMPLARES_IDIOMA' => $row['EJEMPLARES_IDIOMA'],
				'EJEMPLARES_ISBN' => $row['EJEMPLARES_ISBN'],
				'EJEMPLARES_PAGINAS' => $row['EJEMPLARES_PAGINAS'],
				'EJEMPLARES_PVP' => $row['EJEMPLARES_PVP'],
				'LIBRO_DESCRIPCION' => $row['LIBRO_DESCRIPCION'],
				'EJEMPLARES_PORTADA' => $row['EJEMPLARES_PORTADA'],
				'EDITORIAL_NOMBRE' => $row['EDITORIAL_NOMBRE'],
				'LIBRO_TITULO' => $row['LIBRO_TITULO'],
        'EJEMPLARES_ID' => $row['EJEMPLARES_ID'],
        'ALMACEN_STOCK' => $row['ALMACEN_STOCK'],
        'TIENDAS_ID' => $row['TIENDAS_ID']
			];
		}
		$con = null;
		$stmt = null;
		return $libro;
    }//fin metodo

    public function verLibrosPorEditorialUsuarioBotonTienda(string $editorial,int $idTienda) :array {
		$sql = "SELECT  LIBROS_IDLIBRO,ID_CATEGORIA,NOMBRE_CATEGORIA,ID_SUBCATEGORIA,NOMBRE_SUBCATEGORIA,EJEMPLARES_YEARPUBLICACION,EJEMPLARES_IDIOMA,
			EJEMPLARES_FECHA_DISPONIBILIDAD,AUTOR_NOMBRE,EJEMPLARES_ENCUADERNACION,EJEMPLARES_NUMERO_EDICION,EJEMPLARES_FORMATO
			,EJEMPLARES_ISBN,EJEMPLARES_PAGINAS,EJEMPLARES_PVP,LIBRO_DESCRIPCION,EJEMPLARES_PORTADA,EDITORIAL_NOMBRE,LIBRO_TITULO, EJEMPLARES_ID
      ,ALMACEN_STOCK,TIENDAS_ID
			FROM librosBusquedaInicio WHERE EDITORIAL_NOMBRE LIKE ?  AND TIENDAS_ID = ? ORDER BY LIBRO_TITULO ASC ;";
		$libro = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$editorial,PDO::PARAM_STR);
    $stmt->bindParam(2,$idTienda,PDO::PARAM_INT);
		$stmt->execute();
		while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
			$libro[] = [
				'LIBROS_IDLIBRO' => $row['LIBROS_IDLIBRO'],
				'ID_CATEGORIA' => $row['ID_CATEGORIA'],
				'NOMBRE_CATEGORIA' => $row['NOMBRE_CATEGORIA'],
				'ID_SUBCATEGORIA' => $row['ID_SUBCATEGORIA'],
				'NOMBRE_SUBCATEGORIA' => $row['NOMBRE_SUBCATEGORIA'],
				'EJEMPLARES_YEARPUBLICACION' => $row['EJEMPLARES_YEARPUBLICACION'],
				'EJEMPLARES_FECHA_DISPONIBILIDAD' => $row['EJEMPLARES_FECHA_DISPONIBILIDAD'],
				'AUTOR_NOMBRE' => $row['AUTOR_NOMBRE'],
				'EJEMPLARES_ENCUADERNACION' => $row['EJEMPLARES_ENCUADERNACION'],
				'EJEMPLARES_NUMERO_EDICION' => $row['EJEMPLARES_NUMERO_EDICION'],
				'EJEMPLARES_FORMATO' => $row['EJEMPLARES_FORMATO'],
				'EJEMPLARES_IDIOMA' => $row['EJEMPLARES_IDIOMA'],
				'EJEMPLARES_ISBN' => $row['EJEMPLARES_ISBN'],
				'EJEMPLARES_PAGINAS' => $row['EJEMPLARES_PAGINAS'],
				'EJEMPLARES_PVP' => $row['EJEMPLARES_PVP'],
				'LIBRO_DESCRIPCION' => $row['LIBRO_DESCRIPCION'],
				'EJEMPLARES_PORTADA' => $row['EJEMPLARES_PORTADA'],
				'EDITORIAL_NOMBRE' => $row['EDITORIAL_NOMBRE'],
				'LIBRO_TITULO' => $row['LIBRO_TITULO'],
        'EJEMPLARES_ID' => $row['EJEMPLARES_ID'],
        'ALMACEN_STOCK' => $row['ALMACEN_STOCK'],
        'TIENDAS_ID' => $row['TIENDAS_ID']
			];
		}
		$con = null;
		$stmt = null;
		return $libro;
    }//fin metodo

}//fin clase
