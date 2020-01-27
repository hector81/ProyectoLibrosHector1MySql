<?php

class LibrosRepositorio
{
    public function mostrarlibrosPaginaPrincipal() :array{
		//LLAMAMOS A LA VISTA librosPaginaPrincipal
		$sql = "SELECT  IdLibro, Titulo,YearPublicacion ,nombre_autor,Idioma,Paginas,PVP,Descripcion,Portada,NombreCategoria,NombreSubCategoria
			,NOMBRE_EDITORIAL,IdEjemplar FROM librosPaginaPrincipal ORDER BY idlibro desc LIMIT 5 ;";
		$librosPagina = [];$libro = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		
		
		/*
		$con = (new ConexionBaseDatos)->getConexion();
		try {
			foreach($con->query($sql) as $fila) {
				$libro = [
					'IdLibro' => $fila['IdLibro'],
					'Titulo' => $fila['Titulo'],
					'YearPublicacion' => $fila['YearPublicacion'],
					'nombre_autor' => $fila['nombre_autor'],
					'Idioma' => $fila['Idioma'],
					'Paginas' => $fila['Paginas'],
					'PVP' => $fila['PVP'],
					'Descripcion' => $fila['Descripcion'],
					'Portada' => $fila['Portada'],
					'NombreCategoria' => $fila['NombreCategoria'],
					'NombreSubCategoria' => $fila['NombreSubCategoria'],
					'NOMBRE_EDITORIAL' => $fila['NOMBRE_EDITORIAL'],
					'IdEjemplar' => $fila['IdEjemplar']
				];
				$librosPagina[] = $libro;
			}
			$con = null;//cierra conexion
		} catch (PDOException $e) {
			print "¡Error!: " . $e->getMessage() . "<br/>";
			die();
		}
		*/
		
		
		$con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->execute();
		while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
			$libro = [
				'IdLibro' => $row['IdLibro'],
				'Titulo' => $row['Titulo'],
				'YearPublicacion' => $row['YearPublicacion'],
				'nombre_autor' => $row['nombre_autor'],
				'Idioma' => $row['Idioma'],
				'Paginas' => $row['Paginas'],
				'PVP' => $row['PVP'],
				'Descripcion' => $row['Descripcion'],
				'Portada' => $row['Portada'],
				'NombreCategoria' => $row['NombreCategoria'],
				'NombreSubCategoria' => $row['NombreSubCategoria'],
				'NOMBRE_EDITORIAL' => $row['NOMBRE_EDITORIAL'],
				'IdEjemplar' => $row['IdEjemplar']
			];
			$librosPagina[] = $libro;
		}
		$con = null;
		$stmt = null;

		
		return $librosPagina;
    }//fin metodo

    public function librosCategoriasLateral() :array{
		//LLAMAMOS A LA VISTA LibrosLateral1
		$sql = "SELECT IdCategoria,NombreCategoria, numero FROM LibrosLateral1";
		$lateralCategorias = [];$categoria = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
        $con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->execute();
		while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
			$categoria = [
				'IdCategoria' => $row['IdCategoria'],
				'NombreCategoria' => $row['NombreCategoria'],
				'numero' => $row['numero']
			];
			$lateralCategorias[] = $categoria;
		}
		$con = null;
		$stmt = null;
		return $lateralCategorias;
    }//fin metodo

    public function librosSubCategoriasLateral() :array{
		//LLAMAMOS A LA VISTA LibrosLateral2
		$sql = "SELECT IdSubCategoria,NombreSubCategoria, IdCategoria,numero FROM LibrosLateral2";
		$lateralSubCategorias = [];$subCategoria = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->execute();
		while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
			$subCategoria = [
				'IdSubCategoria' => $row['IdSubCategoria'],
				'NombreSubCategoria' => $row['NombreSubCategoria'],
				'IdCategoria' => $row['IdCategoria'],
				'numero' => $row['numero']
			];
			$lateralSubCategorias[] = $subCategoria;
		}
		$con = null;
		$stmt = null;
		return $lateralSubCategorias;
    }//fin metodo


    public function verLibrosIndividual(int $idLibro) :array{
		//LLAMAMOS A LA VISTA libroIndividual
		$sql = "SELECT  IdEjemplar,IdLibro,Nombre_Categoria ,IdSubCategoria,Nombre_SubCategoria ,Titulo,YearPublicacion,FechaDisponibilidad  ,nombre_autor ,
			Encuadernacion,  Numero_Edicion, Formato,Idioma,ISBN,Paginas,PVP,Descripcion,Portada,NOMBRE_EDITORIAL, IdCategoria FROM libroIndividual WHERE IdLibro = ?;";
		$libro = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$idLibro,PDO::PARAM_INT);
		$stmt->execute();
		while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
			$libro = [
				'IdEjemplar' => $row['IdEjemplar'],
				'IdLibro' => $row['IdLibro'],
				'Nombre_Categoria' => $row['Nombre_Categoria'],
				'IdSubCategoria' => $row['IdSubCategoria'],
				'Nombre_SubCategoria' => $row['Nombre_SubCategoria'],
				'Titulo' => $row['Titulo'],
				'YearPublicacion' => $row['YearPublicacion'],
				'FechaDisponibilidad' => $row['FechaDisponibilidad'],
				'nombre_autor' => $row['nombre_autor'],
				'Encuadernacion' => $row['Encuadernacion'],
				'Numero_Edicion' => $row['Numero_Edicion'],
				'Formato' => $row['Formato'],
				'Idioma' => $row['Idioma'],
				'ISBN' => $row['ISBN'],
				'Paginas' => $row['Paginas'],
				'PVP' => $row['PVP'],
				'Descripcion' => $row['Descripcion'],
				'Portada' => $row['Portada'],
				'NOMBRE_EDITORIAL' => $row['NOMBRE_EDITORIAL'],
        'IdCategoria' => $row['IdCategoria'],
			];
		}
		$con = null;
		$stmt = null;
		return $libro;
    }//fin metodo


    public function verLibrosPorSubCategoria(int $IdSubCategoria) :array{
    		//LLAMAMOS A LA VISTA libroIndividual
    		$sql = "SELECT IdLibro,IdSubCategoria,NombreCategoria,NombreSubCategoria, Titulo,YearPublicacion ,FechaDisponibilidad,Idioma,ISBN, Paginas,PVP,Descripcion,Portada,IdEjemplar
    			FROM librosSubcategoriasVer WHERE IdSubCategoria = ?;";
    		$libro = [];$arrayLibro = [];
    		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
    		$con = (new ConexionBaseDatos)->getConexion();
    		$stmt = $con->prepare($sql);
    		$stmt->bindParam(1,$IdSubCategoria,PDO::PARAM_INT);
    		$stmt->execute();
    		while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
    			$libro = [
    				'IdLibro' => $row['IdLibro'],
    				'IdSubCategoria' => $row['IdSubCategoria'],
    				'NombreCategoria' => $row['NombreCategoria'],
    				'NombreSubCategoria' => $row['NombreSubCategoria'],
    				'Titulo' => $row['Titulo'],
    				'YearPublicacion' => $row['YearPublicacion'],
    				'FechaDisponibilidad' => $row['FechaDisponibilidad'],
    				'Idioma' => $row['Idioma'],
    				'ISBN' => $row['ISBN'],
    				'Paginas' => $row['Paginas'],
    				'PVP' => $row['PVP'],
    				'Descripcion' => $row['Descripcion'],
    				'Portada' => $row['Portada'],
    				'IdEjemplar' => $row['IdEjemplar'],
    			];
    			$arrayLibro[] = $libro;
    		}
    		$con = null;
    		$stmt = null;
    		return $arrayLibro;
    }//fin metodo

    public function verLibrosPorSubCategoriaIdTienda(int $IdSubCategoria, int $idTienda) :array{
    		//LLAMAMOS A LA VISTA libroIndividual
    		$sql = "SELECT IdLibro,IdCategoria,IdSubCategoria,NombreCategoria,NombreSubCategoria, Titulo,YearPublicacion ,FechaDisponibilidad
        ,Idioma,ISBN, Paginas,PVP,Descripcion,Portada,IdEjemplar,IdTienda,Stock
    			FROM librosSubcategoriasVerporTienda WHERE IdSubCategoria = ? AND idTienda = ? ORDER BY Titulo asc;";
    		$libro = [];$arrayLibro = [];
    		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
    		$con = (new ConexionBaseDatos)->getConexion();
    		$stmt = $con->prepare($sql);
    		$stmt->bindParam(1,$IdSubCategoria,PDO::PARAM_INT);
        $stmt->bindParam(2,$idTienda,PDO::PARAM_INT);
    		$stmt->execute();
    		while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
    			$libro = [
    				'IdLibro' => $row['IdLibro'],
    				'IdCategoria' => $row['IdCategoria'],
            'IdSubCategoria' => $row['IdSubCategoria'],
    				'NombreCategoria' => $row['NombreCategoria'],
    				'NombreSubCategoria' => $row['NombreSubCategoria'],
    				'Titulo' => $row['Titulo'],
    				'YearPublicacion' => $row['YearPublicacion'],
    				'FechaDisponibilidad' => $row['FechaDisponibilidad'],
    				'Idioma' => $row['Idioma'],
    				'ISBN' => $row['ISBN'],
    				'Paginas' => $row['Paginas'],
    				'PVP' => $row['PVP'],
    				'Descripcion' => $row['Descripcion'],
    				'Portada' => $row['Portada'],
    				'IdEjemplar' => $row['IdEjemplar'],
            'IdTienda' => $row['IdTienda'],
            'Stock' => $row['Stock'],
    			];
    			$arrayLibro[] = $libro;
    		}
    		$con = null;
    		$stmt = null;
    		return $arrayLibro;
    }//fin metodo

    public function devolverIdCategoria(string $nombreCategoria) :int{
        $sql = "SELECT IdCategoria FROM Categorias WHERE NombreCategoria = ?;";
        $idCategoria = 0;
        include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
    		$con = (new ConexionBaseDatos)->getConexion();
    		$stmt = $con->prepare($sql);
    		$stmt->bindParam(1,$nombreCategoria,PDO::PARAM_STR);
    		$stmt->execute();
    		while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
    			$idCategoria = $row['IdCategoria'];
    		}
    		$con = null;
    		$stmt = null;
    		return $idCategoria;
    }//fin metodo

    //funcion para devolver todos los años de los libros
    public function devolverYearLibros() :array{
        $sql = "SELECT DISTINCT YearPublicacion FROM ejemplares ORDER BY YearPublicacion ASC ";
        $year = [];
        include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->execute();
		while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
			$year[] = $row['YearPublicacion'];
		}
		$con = null;
		$stmt = null;
		return $year;
    }//fin metodo

    public function resultadosBusqueda(string $palabra1) :array {
		$palabra2 = $palabra1."%";
		$palabra3= "%".$palabra1;
		$palabra4= "%".$palabra1."%";
		$sql = "SELECT  DISTINCT LIBROS_IDLIBRO,ID_CATEGORIA,NOMBRE_CATEGORIA,ID_SUBCATEGORIA,NOMBRE_SUBCATEGORIA,EJEMPLARES_YEARPUBLICACION,EJEMPLARES_IDIOMA,
					EJEMPLARES_FECHA_DISPONIBILIDAD,AUTOR_NOMBRE,EJEMPLARES_ENCUADERNACION,EJEMPLARES_NUMERO_EDICION,EJEMPLARES_FORMATO
					,EJEMPLARES_ISBN,EJEMPLARES_PAGINAS,EJEMPLARES_PVP,LIBRO_DESCRIPCION,EJEMPLARES_PORTADA,EDITORIAL_NOMBRE,LIBRO_TITULO, EJEMPLARES_ID
				FROM librosBusquedaInicio WHERE
					NOMBRE_CATEGORIA LIKE ? OR NOMBRE_CATEGORIA LIKE ? OR NOMBRE_CATEGORIA LIKE ? OR NOMBRE_CATEGORIA LIKE ? OR
					NOMBRE_SUBCATEGORIA LIKE ? OR NOMBRE_SUBCATEGORIA LIKE ? OR NOMBRE_SUBCATEGORIA LIKE ? OR NOMBRE_SUBCATEGORIA LIKE ? OR
					EJEMPLARES_YEARPUBLICACION LIKE ? OR EJEMPLARES_YEARPUBLICACION LIKE ? OR EJEMPLARES_YEARPUBLICACION LIKE ? OR EJEMPLARES_YEARPUBLICACION LIKE ? OR
					AUTOR_NOMBRE LIKE ? OR AUTOR_NOMBRE LIKE ? OR AUTOR_NOMBRE LIKE ? OR AUTOR_NOMBRE LIKE ? OR
					LIBRO_TITULO LIKE ? OR LIBRO_TITULO LIKE ? OR LIBRO_TITULO LIKE ? OR LIBRO_TITULO LIKE ? OR
					EDITORIAL_NOMBRE LIKE ? OR EDITORIAL_NOMBRE LIKE ? OR EDITORIAL_NOMBRE LIKE ? OR EDITORIAL_NOMBRE LIKE ?
				;";
		$libro = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$palabra1,PDO::PARAM_STR);
		$stmt->bindParam(2,$palabra2,PDO::PARAM_STR);
		$stmt->bindParam(3,$palabra3,PDO::PARAM_STR);
		$stmt->bindParam(4,$palabra4,PDO::PARAM_STR);
		$stmt->bindParam(5,$palabra1,PDO::PARAM_STR);
		$stmt->bindParam(6,$palabra2,PDO::PARAM_STR);
		$stmt->bindParam(7,$palabra3,PDO::PARAM_STR);
		$stmt->bindParam(8,$palabra4,PDO::PARAM_STR);
		$stmt->bindParam(9,$palabra1,PDO::PARAM_STR);
		$stmt->bindParam(10,$palabra1,PDO::PARAM_STR);
		$stmt->bindParam(11,$palabra1,PDO::PARAM_STR);
		$stmt->bindParam(12,$palabra1,PDO::PARAM_STR);
		$stmt->bindParam(13,$palabra1,PDO::PARAM_STR);
		$stmt->bindParam(14,$palabra2,PDO::PARAM_STR);
		$stmt->bindParam(15,$palabra3,PDO::PARAM_STR);
		$stmt->bindParam(16,$palabra4,PDO::PARAM_STR);
		$stmt->bindParam(17,$palabra1,PDO::PARAM_STR);
		$stmt->bindParam(18,$palabra2,PDO::PARAM_STR);
		$stmt->bindParam(19,$palabra3,PDO::PARAM_STR);
		$stmt->bindParam(20,$palabra4,PDO::PARAM_STR);
		$stmt->bindParam(21,$palabra1,PDO::PARAM_STR);
		$stmt->bindParam(22,$palabra2,PDO::PARAM_STR);
		$stmt->bindParam(23,$palabra3,PDO::PARAM_STR);
		$stmt->bindParam(24,$palabra4,PDO::PARAM_STR);
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
        'EJEMPLARES_ID' => $row['EJEMPLARES_ID']
			 ];
		}
		$con = null;
		$stmt = null;
		return $libro;
    }//fin metodo



    public function busquedaAvanzada(int $autoresId,int $editorialId,int $tiendasId,string $yearPublicacion,int $idcategoria,
        int $idsubcategoria,string $titulo) :array{
         $resultadosBusqueda = [];

  		   include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
         //primero comprobamos que no esten todos vacios y si lo estan devolvemos null
         if( $autoresId == null && $editorialId == null && $tiendasId == null && $yearPublicacion == null && $idcategoria == null &&
             $idsubcategoria == null && $titulo == null  ){
                $resultadosBusqueda == null;
         }else{
              //creamos la sentencia donde buscaremos
             $sql = "SELECT DISTINCT ID_EJEMPLAR, ID_LIBRO,ID_CATEGORIA ,NOMBRE_CATEGORIA,ID_SUBCATEGORIA,
                   NOMBRE_SUBCATEGORIA
                   , TITULO_LIBRO , YEAR_PUBLICACION ,FECHA_DISPONIBILIDAD , NOMBRE_AUTOR ,
                   ENCUADERNACION, NUMERO_EDICION,
                   FORMATO_EJEMPLAR,
                   IDIOMA_EJEMPLAR,ISBN_EJEMPLAR,
                   PAGINAS_EJEMPLAR, PVP_EJEMPLAR,
                   LIBRO_DESCRIPCION , PORTADA_EJEMPLAR,
                  ID_AUTOR,  NOMBRE_EDITORIAL,ID_EDITORIAL_EJEMPLAR
                  FROM Vista_para_busquedas WHERE ";
              //vamos a contar los AND que añadiremos a la sentencia según el número de parametros pasados
              $contador = 0;
              $contArrayAnd = [$autoresId,$editorialId,$tiendasId,$yearPublicacion,$idcategoria,$idsubcategoria,$titulo];
              foreach ($contArrayAnd as $key => $value) {
                 if( $value != null){
                   $contador++;
                 }
              }

              //añadiremos a la sentencia los parametros pasados si no están vacios y le añadiremos AND delante según el contador
             if($autoresId !="") {
                  $sql .= " ID_AUTOR = '$autoresId' ";
                  if($contador > 1){
                      $sql .= " AND ";
                  }
                  $contador--;
             }
             if($editorialId !="") {
                  $sql .= " ID_EDITORIAL_EJEMPLAR  ='$editorialId' ";
                  if($contador > 1){
                      $sql .= " AND ";
                  }
                  $contador--;
             }
             if($tiendasId !="") {
                  $sql .= " ID_TIENDA  ='$tiendasId' ";
                  if($contador > 1){
                      $sql .= " AND ";
                  }
                  $contador--;
             }
             if($yearPublicacion !="") {
                  $sql .= " YEAR_PUBLICACION ='$yearPublicacion' ";
                  if($contador > 1){
                      $sql .= " AND ";
                  }
                  $contador--;
             }
             if($idcategoria !="") {
                  $sql .= " ID_CATEGORIA = '$idcategoria' ";
                  if($contador > 1){
                      $sql .= " AND ";
                  }
                  $contador--;
             }
             if($idsubcategoria !="") {
                  $sql .= " ID_SUBCATEGORIA ='$idsubcategoria' ";
                  if($contador > 1){
                      $sql .= " AND ";
                  }
                  $contador--;
             }
             if($titulo !="") {
                  $sql .= " TITULO_LIBRO LIKE '%$titulo%'  ";
                  if($contador > 1){
                      $sql .= " AND ";
                  }
                  $contador--;
             }


            // ejecutamos

             $con = (new ConexionBaseDatos)->getConexion();
             $stmt = $con->prepare($sql);

             $stmt->execute();
             while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
                 $resultadosBusqueda[] = [
                     'ID_EJEMPLAR' => $row['ID_EJEMPLAR'],
                     'ID_LIBRO' => $row['ID_LIBRO'],
                     'ID_CATEGORIA' => $row['ID_CATEGORIA'],
                     'NOMBRE_CATEGORIA' => $row['NOMBRE_CATEGORIA'],
                     'ID_SUBCATEGORIA' => $row['ID_SUBCATEGORIA'],
                     'NOMBRE_SUBCATEGORIA' => $row['NOMBRE_SUBCATEGORIA'],
                     'TITULO_LIBRO' => $row['TITULO_LIBRO'],
                     'YEAR_PUBLICACION' => $row['YEAR_PUBLICACION'],
                     'FECHA_DISPONIBILIDAD' => $row['FECHA_DISPONIBILIDAD'],
                     'NOMBRE_AUTOR' => $row['NOMBRE_AUTOR'],
                     'ENCUADERNACION' => $row['ENCUADERNACION'],
                     'NUMERO_EDICION' => $row['NUMERO_EDICION'],
                     'FORMATO_EJEMPLAR' => $row['FORMATO_EJEMPLAR'],
                     'IDIOMA_EJEMPLAR' => $row['IDIOMA_EJEMPLAR'],
                     'ISBN_EJEMPLAR' => $row['ISBN_EJEMPLAR'],
                     'PAGINAS_EJEMPLAR' => $row['PAGINAS_EJEMPLAR'],
                     'PVP_EJEMPLAR' => $row['PVP_EJEMPLAR'],
                     'LIBRO_DESCRIPCION' => $row['LIBRO_DESCRIPCION'],
                     'PORTADA_EJEMPLAR' => $row['PORTADA_EJEMPLAR'],
                     'ID_AUTOR' => $row['ID_AUTOR'],
                     'NOMBRE_EDITORIAL' => $row['NOMBRE_EDITORIAL'],
                     'ID_EDITORIAL_EJEMPLAR' => $row['ID_EDITORIAL_EJEMPLAR'],
                 ];
             }
             $con = null;
             $stmt = null;
         }
          return $resultadosBusqueda;
    }//fin metodo



    public function insertarImagenYsacarRutaImagenLibro(string $name,string $type, string $tmp_name,string $error,string $size
        ,array $categoria,array $subCategorias) :array{
          //Subimos imagen cargando con ajax
          $valid_extensions = array('jpeg', 'jpg', 'png', 'gif', 'bmp'); // extensiones validas que va a aceptar
          //$path = 'C:/xampp/htdocs/ProyectoLibrosHector1/Imagenes/OtrasImagenes/';
          $path = 'C:/xampp/htdocs/ProyectoLibrosHector1/Imagenes/'.$categoria[0]->getAlias().'/'.$subCategorias[0]->getAlias().'/'; // directorio subida

          if(isset($name) && isset($type) && isset($tmp_name) && isset($error) && isset($size))
          {
           // get uploaded file's extension
           $ext = strtolower(pathinfo($name, PATHINFO_EXTENSION));
           // can upload same image using rand function
           $final_image = rand(1000,1000000).$name;

           // comprobamos que sea un formato valido
           if(in_array($ext, $valid_extensions))
           {
            $path = $path.strtolower($final_image);
            //este metodo mueve la foto al fichero
            move_uploaded_file($tmp_name,$path);
           }
           else
           {
            echo 'invalid file';
           }
          }
          //////////////////FIN introduccion IMAGEN //////////////////
          $elementos = array('imagen' => $final_image, 'tipo' => $type);
          return $elementos;
  	}//fin metodo

    public function modificarLibroAdministrador(array $subirFoto,float $PVP,int $idEjemplar,int $idLibro,array $categoria,array $subCategorias) :bool{
          include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
          $con = (new ConexionBaseDatos)->getConexion();
          $sql = "UPDATE Ejemplares SET PVP = ?,Portada = ? WHERE IdEjemplar = ? AND IdLibro = ? ;";
          $boolmodificadoLibro = false;
          try{
              $con->beginTransaction();
              $stmt = $con->prepare($sql);
              $stmt->bindParam(1,$PVP,PDO::PARAM_INT);
              ////PARA LA imagen
              $fotoF = $subirFoto['imagen'];//string
              $tipo = $subirFoto['tipo'];//string
              $rutaImagenSubida = 'Imagenes/'.$categoria[0]->getAlias().'/'.$subCategorias[0]->getAlias().'/'.$fotoF;
              if ( strpos($tipo, "gif") || strpos($tipo, "jpeg") || strpos($tipo, "jpg") || strpos($tipo, "png") || strpos($tipo, "bmp") ){
                  $stmt->bindParam(2,$rutaImagenSubida,PDO::PARAM_STR);
              }
              $stmt->bindParam(3,$idEjemplar,PDO::PARAM_INT);
              $stmt->bindParam(4,$idLibro,PDO::PARAM_INT);
              if($stmt->execute()){
                  $boolmodificadoLibro = true;
              }
              $con->commit();
              return $boolmodificadoLibro;
          }catch(PDOException $ex){
            throw $ex;
            $con->rollBack();
          }finally{
            $con = null;
            $stmt = null;
          }
  	}//fin metodo

    public function modificarLibroAdministradorSinFoto(float $PVP,int $idEjemplar,int $idLibro,array $categoria,array $subCategorias) :bool{
          include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
          $con = (new ConexionBaseDatos)->getConexion();
          $sql = "UPDATE Ejemplares SET PVP = ?  WHERE IdEjemplar = ? AND IdLibro = ? ;";
          $boolmodificadoLibro = false;
          try{
              $con->beginTransaction();
              $stmt = $con->prepare($sql);
              $stmt->bindParam(1,$PVP,PDO::PARAM_INT);
              $stmt->bindParam(2,$idEjemplar,PDO::PARAM_INT);
              $stmt->bindParam(3,$idLibro,PDO::PARAM_INT);
              if($stmt->execute()){
                  $boolmodificadoLibro = true;
              }
              $con->commit();
              return $boolmodificadoLibro;
          }catch(PDOException $ex){
            throw $ex;
            $con->rollBack();
          }finally{
            $con = null;
            $stmt = null;
          }
  	}//fin metodo

    public function insertarLibro(int $idSubcategoria,string $titulo,int $idAutor,string $descripcion) :bool{
          include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
          $con = (new ConexionBaseDatos)->getConexion();
          $sql = "INSERT INTO Libros(IdSubCategoria,Titulo,IdAutor,Descripcion) VALUES(?,?,?,?);";
          $boolmodificadoLibro = false;
          try{
              $con->beginTransaction();
              $stmt = $con->prepare($sql);
              $stmt->bindParam(1,$idSubcategoria,PDO::PARAM_INT);
              $stmt->bindParam(2,$titulo,PDO::PARAM_STR);
              $stmt->bindParam(3,$idAutor,PDO::PARAM_INT);
              $stmt->bindParam(4,$descripcion,PDO::PARAM_STR);
              if($stmt->execute()){
                  $boolmodificadoLibro = true;
              }
              $con->commit();
              return $boolmodificadoLibro;
          }catch(PDOException $ex){
            throw $ex;
            $con->rollBack();
          }finally{
            $con = null;
            $stmt = null;
          }
  	}//fin metodo

    public function sacarUltimoIdLibro() :int{
        include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
        $con = (new ConexionBaseDatos)->getConexion();
        $sql = "SELECT top 1 IdLibro FROM Libros
                ORDER BY IdLibro DESC;";
        $id = 0;
        $stmt = $con->prepare($sql);
        $stmt->bindParam(1,$idSubcategoria,PDO::PARAM_INT);
        $stmt->bindParam(2,$titulo,PDO::PARAM_STR);
        $stmt->bindParam(3,$idAutor,PDO::PARAM_INT);
        $stmt->execute();
        while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
          $id = $row['IdLibro'];
        }
        $con = null;
        $stmt = null;
        return $id;
    }//fin metodo

    public function sacarUltimoIdEjemplar() :int{
        include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
        $con = (new ConexionBaseDatos)->getConexion();
        $sql = "SELECT top 1 IdEjemplar FROM Ejemplares
                ORDER BY IdEjemplar DESC;";
        $id = 0;
        $stmt = $con->prepare($sql);
        $stmt->bindParam(1,$idSubcategoria,PDO::PARAM_INT);
        $stmt->bindParam(2,$titulo,PDO::PARAM_STR);
        $stmt->bindParam(3,$idAutor,PDO::PARAM_INT);
        $stmt->execute();
        while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
          $id = $row['IdEjemplar'];
        }
        $con = null;
        $stmt = null;
        return $id;
    }//fin metodo


    public function devolverStockLibroPorTienda(int $idTienda, int  $idlIBRO) :int{
        include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
        $con = (new ConexionBaseDatos)->getConexion();
        $sql = "SELECT top 1 IdLibro FROM Libros
                ORDER BY IdLibro DESC;";
        $id = 0;
        $stmt = $con->prepare($sql);
        $stmt->bindParam(1,$idSubcategoria,PDO::PARAM_INT);
        $stmt->bindParam(2,$titulo,PDO::PARAM_STR);
        $stmt->bindParam(3,$idAutor,PDO::PARAM_INT);
        $stmt->execute();
        while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
          $id = $row['IdLibro'];
        }
        $con = null;
        $stmt = null;
        return $id;
    }//fin metodo

    public function borrarLibro(int $idLibro) :bool{
  		$sql = "DELETE FROM Libros WHERE IdLibro = ?;";
  		$boolean = false;
  		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
  		try{
  			$con = (new ConexionBaseDatos)->getConexion();
  			$con->beginTransaction();
  			$stmt = $con->prepare($sql);
  			$stmt->bindParam(1,$idLibro,PDO::PARAM_INT);
  			if($stmt->execute()){
  				$boolean = true;
  			}
  			$con->commit();
  			return $boolean;
  		}catch(PDOException $ex){
  			throw $ex;
  			$con->rollBack();
  		}finally{
  			$con = null;
  			$stmt = null;
  		}
  	}//fin metodo

    public function devolverNumeroVentasAsociadasLibro(int $idLibro) :int{
        include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
        $sql = "SELECT COUNT(Libros.IdLibro) AS Cuenta FROM Libros
                JOIN Ejemplares ON Ejemplares.IdLibro = Libros.IdLibro
                JOIN DetalleVenta ON DetalleVenta.IdEjemplar = Ejemplares.IdEjemplar
                WHERE Libros.IdLibro = ?;";
        $n = 0;
    	  $con = (new ConexionBaseDatos)->getConexion();
    	  $stmt = $con->prepare($sql);
        $stmt->bindParam(1,$idLibro,PDO::PARAM_INT);
    	  $stmt->execute();
    	  while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
    		  $n = $row['Cuenta'];
    	  }
    	  $stmt = null;
    	  $con = null;
  	    return $n;
    }//fin metodo

    public function devolverNumeroReservasAsociadasLibro(int $idLibro) :int{
        include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
        $sql = "SELECT COUNT(Libros.IdLibro) AS Cuenta FROM Libros
                JOIN Ejemplares ON Ejemplares.IdLibro = Libros.IdLibro
                JOIN LibrosReservados ON LibrosReservados.IdEjemplar  = Ejemplares.IdEjemplar
                WHERE Libros.IdLibro = ?;";
        $n = 0;
    	  $con = (new ConexionBaseDatos)->getConexion();
    	  $stmt = $con->prepare($sql);
        $stmt->bindParam(1,$idLibro,PDO::PARAM_INT);
    	  $stmt->execute();
    	  while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
    		  $n = $row['Cuenta'];
    	  }
    	  $stmt = null;
    	  $con = null;
  	    return $n;
    }//fin metodo

    public function insertarLibroCatalogosTienda(array $tiendaTotal,int $ultimoIdEjemplarInsertado) :bool{
  			include_once __DIR__ . '/../../core/conexionBaseDatos.inc';//EXEC insertarStockCeroNuevaTienda 1,7 //IdEjemplar,IdTienda //430
  			$boolStock= false;
  			foreach ($tiendaTotal as $key => $value) {
            $idTienda = (int)$value->getIdTienda();
            $con = (new ConexionBaseDatos)->getConexion();
            $sql = "EXEC insertarStockCeroNuevoLibroTiendas ?,? ;";
            $boolStock= false; //lo iniciamos en el bucle a false para comprobar que hace bien todas las vueltas
            try{
                  $con->beginTransaction();
                  $stmt = $con->prepare($sql);
                  $stmt->bindParam(1,$ultimoIdEjemplarInsertado,PDO::PARAM_INT);
                  $stmt->bindParam(2,$idTienda,PDO::PARAM_INT);
              if($stmt->execute()){
                  $boolStock= true;
              }
              $con->commit();
            }catch(PDOException  $eX ){
                echo "Error: ".$eX;
                $con->rollback();
            }finally {
                $con = null;
                $stmt = null;
            }
        }
  			return $boolStock;
  	}//fin metodo

}//fin clase
