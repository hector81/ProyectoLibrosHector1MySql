<?php

class EditorialesRepositorio
{

	public function devolverEditorialesTotales() :array{
			include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
			include_once __DIR__ . '/../../fuente/modelo/editoriales.inc';
			$con = (new ConexionBaseDatos)->getConexion();
			$sql = "SELECT IdEditorial, Nombre, Direccion,IdCiudad,Telefono, Fax, Email from editoriales   ORDER BY Nombre ASC;";
			$editoriales =[];
			$stmt = $con->prepare($sql);
			$stmt->execute();
			while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
				$editoriales[] = new Editoriales($row);
			}
			$con = null;
			$stmt = null;
			return $editoriales;
	}//fin metodo

	public function devolverLibrosPorEditorial(int $idEditorial) :int{
			include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
			$con = (new ConexionBaseDatos)->getConexion();
			$sql = "SELECT COUNT(Ejemplares.IdLibro) AS CUENTA FROM Ejemplares
								JOIN Editoriales ON Editoriales.IdEditorial = Ejemplares.IdEditorial
								WHERE Editoriales.IdEditorial = ?;";
			$num = 0;
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$idEditorial,PDO::PARAM_INT);
			$stmt->execute();
			while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
				$num = $row['CUENTA'];
			}
			$con = null;
			$stmt = null;
			return $num;
	}//fin metodo

	public function borrarEditorial(int $idEditorial) :bool{
			$confirmacion =false;
			include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
			$con = (new ConexionBaseDatos)->getConexion();
			try{
					$con->beginTransaction();
					$sql = "DELETE FROM Editoriales WHERE IdEditorial = ?;";
					$stmt = $con->prepare($sql);
					$stmt->bindParam(1,$idEditorial,PDO::PARAM_INT);
					if($stmt->execute()){
							$confirmacion =true;
					}
					$con->commit();
					return $confirmacion;
			}catch(PDOException  $eX ){
					echo "Error: ".$eX;
					$con->rollback();
			}finally {
					$con = null;
					$stmt = null;
			}
	}//fin metodo

	public function devolverEditorialesTotalesPorTienda(int $idTienda) :array{
			include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
			include_once __DIR__ . '/../../fuente/modelo/editoriales.inc';
			$con = (new ConexionBaseDatos)->getConexion();
			$sql = "SELECT Editoriales.IdEditorial, Editoriales.Nombre, Editoriales.Direccion,Editoriales.IdCiudad,Editoriales.Telefono,
							Editoriales.Fax, Editoriales.Email from Editoriales
							JOIN Ejemplares ON Ejemplares.IdEditorial = Editoriales.IdEditorial
							JOIN Almacen ON Almacen.IdEjemplar = Ejemplares.IdEjemplar
							WHERE Almacen.IdTienda = ?
							ORDER BY Editoriales.Nombre ASC;";
			$editoriales =[];
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$idTienda,PDO::PARAM_INT);
			$stmt->execute();
			while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
				$editoriales[] = new Editoriales($row);
			}
			$con = null;
			$stmt = null;
			return $editoriales;
	}//fin metodo

	public function devolverEditorialesPorId(int $idEditorial) :array{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		include_once __DIR__ . '/../../fuente/modelo/editoriales.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$sql = "SELECT DISTINCT IdEditorial, Nombre, Direccion,IdCiudad,Telefono, Fax, Email from editoriales WHERE IdEditorial = ?;";
		$editoriales =[];
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$idEditorial,PDO::PARAM_INT);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			$editoriales[] = new Editoriales($row);
		}
		$con = null;
		$stmt = null;
		return $editoriales;
	}//fin metodo


	public function devolverArrayEditorialesCiudades(array $editoriales) :array{
		$arrayEditoriales = [];
		include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
		$sql = "SELECT NombreCiudad FROM Ciudades WHERE IdCiudad =  ?";
		foreach ($editoriales as $key => $value) {
			$id  = (int)$value->getIdCiudad();
			$con = (new ConexionBaseDatos)->getConexion();
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$id,PDO::PARAM_INT);
			$stmt->execute();
			while ( $row = $stmt->fetch( PDO::FETCH_ASSOC ) ){
				$arrayEditoriales[] = $row['NombreCiudad'];
			}
			$stmt =null;
			$con=null;
		}
		return $arrayEditoriales;
	}//fin metodo

	public function modificarEditorial(string $nombre,string $direccion,int $idCiudad,string $telefono,string $email,string $fax,
			int $idEditorial){
				$sql = 'UPDATE Editoriales SET Nombre = ?,Direccion = ?, IdCiudad = ?, Telefono = ?, Fax = ?, Email = ? WHERE IdEditorial = ?;';
				$boolean = false;
				include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
				try{
					$con = (new ConexionBaseDatos)->getConexion();
					$con->beginTransaction();
					$stmt = $con->prepare($sql);
					$stmt->bindParam(1,$nombre,PDO::PARAM_STR);
					$stmt->bindParam(2,$direccion,PDO::PARAM_STR);
					$stmt->bindParam(3,$idCiudad,PDO::PARAM_INT);
					$stmt->bindParam(4,$telefono,PDO::PARAM_STR);
					$stmt->bindParam(5,$fax,PDO::PARAM_STR);
					$stmt->bindParam(6,$email,PDO::PARAM_STR);
					$stmt->bindParam(7,$idEditorial,PDO::PARAM_INT);
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

	public function introducirEditorial(string $nombre,string $direccion,int $idCiudad,string $telefono,string $email,string $fax){
				$sql = 'INSERT INTO Editoriales(Nombre,Direccion,IdCiudad,Telefono,Fax,Email) VALUES(?,?,?,?,?,?);';
				$boolean = false;
				include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
				try{
					$con = (new ConexionBaseDatos)->getConexion();
					$con->beginTransaction();
					$stmt = $con->prepare($sql);
					$stmt->bindParam(1,$nombre,PDO::PARAM_STR);
					$stmt->bindParam(2,$direccion,PDO::PARAM_STR);
					$stmt->bindParam(3,$idCiudad,PDO::PARAM_INT);
					$stmt->bindParam(4,$telefono,PDO::PARAM_STR);
					$stmt->bindParam(5,$fax,PDO::PARAM_STR);
					$stmt->bindParam(6,$email,PDO::PARAM_STR);
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

	public function devolverTodosLibrosAlmacenPorEditorial(int $tienda,int $idEditorial) :array{
		$sql = "
		SELECT DISTINCT
				Almacen.stock AS ALMACEN_STOCK,
				Tiendas.IdTienda AS TIENDAS_ID,
				Libros.IdLibro AS LIBROS_IDLIBRO,
				Categorias.IdCategoria AS ID_CATEGORIA,
				Categorias.NombreCategoria AS NOMBRE_CATEGORIA,
				SubCategorias.IdSubCategoria AS ID_SUBCATEGORIA,
				Subcategorias.NombreSubCategoria AS NOMBRE_SUBCATEGORIA,
				Libros.Titulo AS LIBRO_TITULO,
				Ejemplares.YearPublicacion AS EJEMPLARES_YEARPUBLICACION,
				Ejemplares.FechaDisponibilidad AS EJEMPLARES_FECHA_DISPONIBILIDAD  ,
				Autores.Nombre AS AUTOR_NOMBRE ,
				Ejemplares.Encuadernacion AS EJEMPLARES_ENCUADERNACION,
				Ejemplares.NumeroEdicion AS EJEMPLARES_NUMERO_EDICION,
				Ejemplares.Formato AS EJEMPLARES_FORMATO,
				Ejemplares.Idioma AS EJEMPLARES_IDIOMA,
				Ejemplares.ISBN AS EJEMPLARES_ISBN,
				Ejemplares.Paginas AS EJEMPLARES_PAGINAS,
				Ejemplares.PVP AS EJEMPLARES_PVP,
				Libros.Descripcion AS LIBRO_DESCRIPCION,
				Ejemplares.Portada AS EJEMPLARES_PORTADA,
				Ejemplares.IdEjemplar AS EJEMPLARES_ID,
				Tiendas.IdTienda AS ID_TIENDA,
				Editoriales.IdEditorial AS ID_EDITORIAL,
				Editoriales.Nombre AS NOMBRE_EDITORIAL
			FROM Libros
			JOIN Autores ON Autores.IdAutor = Libros.IdAutor
			JOIN Subcategorias ON subcategorias.IdSubCategoria = Libros.IdSubCategoria
			JOIN Categorias ON Categorias.IdCategoria = Subcategorias.IdCategoria
			JOIN Ejemplares ON Ejemplares.IdLibro = Libros.IdLibro
			JOIN Almacen ON Almacen.IdEjemplar = Ejemplares.IdEjemplar
			JOIN Tiendas ON Tiendas.IdTienda = Almacen.IdTienda
			JOIN Editoriales ON Editoriales.IdEditorial = Ejemplares.IdEditorial
			WHERE Tiendas.IdTienda = ? AND Editoriales.IdEditorial = ?
			order by Libros.Titulo asc";
		$libro = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
				$con = (new ConexionBaseDatos)->getConexion();
				$stmt = $con->prepare($sql);
				$stmt->bindParam(1,$tienda,PDO::PARAM_INT);
				$stmt->bindParam(2,$idEditorial,PDO::PARAM_INT);
				$stmt->execute();
				while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
						$libro[] = [
				'ALMACEN_STOCK' => $row['ALMACEN_STOCK'],
				'TIENDAS_ID' => $row['TIENDAS_ID'],
				'LIBROS_IDLIBRO' => $row['LIBROS_IDLIBRO'],
				'ID_CATEGORIA' => $row['ID_CATEGORIA'],
				'NOMBRE_CATEGORIA' => $row['NOMBRE_CATEGORIA'],
				'ID_SUBCATEGORIA' => $row['ID_SUBCATEGORIA'],
				'NOMBRE_SUBCATEGORIA' => $row['NOMBRE_SUBCATEGORIA'],
				'LIBRO_TITULO' => $row['LIBRO_TITULO'],
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
				'EJEMPLARES_ID' => $row['EJEMPLARES_ID'],
				'ID_TIENDA' => $row['ID_TIENDA'],
				'ID_EDITORIAL' => $row['ID_EDITORIAL'],
				'NOMBRE_EDITORIAL' => $row['NOMBRE_EDITORIAL']
						];
				}
		$con = null;
		$stmt = null;
		return $libro;
	}//fin metodo

	public function devolverTodosLibrosPorEditorial($idEditorial) :array{ //Almacen.stock AS ALMACEN_STOCK,  'ALMACEN_STOCK' => $row['ALMACEN_STOCK'],
		$sql = "
		SELECT DISTINCT

				Libros.IdLibro AS LIBROS_IDLIBRO,
				Categorias.IdCategoria AS ID_CATEGORIA,
				Categorias.NombreCategoria AS NOMBRE_CATEGORIA,
				SubCategorias.IdSubCategoria AS ID_SUBCATEGORIA,
				Subcategorias.NombreSubCategoria AS NOMBRE_SUBCATEGORIA,
				Libros.Titulo AS LIBRO_TITULO,
				Ejemplares.YearPublicacion AS EJEMPLARES_YEARPUBLICACION,
				Ejemplares.FechaDisponibilidad AS EJEMPLARES_FECHA_DISPONIBILIDAD  ,
				Autores.Nombre AS AUTOR_NOMBRE ,
				Ejemplares.Encuadernacion AS EJEMPLARES_ENCUADERNACION,
				Ejemplares.NumeroEdicion AS EJEMPLARES_NUMERO_EDICION,
				Ejemplares.Formato AS EJEMPLARES_FORMATO,
				Ejemplares.Idioma AS EJEMPLARES_IDIOMA,
				Ejemplares.ISBN AS EJEMPLARES_ISBN,
				Ejemplares.Paginas AS EJEMPLARES_PAGINAS,
				Ejemplares.PVP AS EJEMPLARES_PVP,
				Libros.Descripcion AS LIBRO_DESCRIPCION,
				Ejemplares.Portada AS EJEMPLARES_PORTADA,
				Ejemplares.IdEjemplar AS EJEMPLARES_ID,
				Editoriales.IdEditorial AS ID_EDITORIAL,
				Editoriales.Nombre AS NOMBRE_EDITORIAL
			FROM Libros
			JOIN Autores ON Autores.IdAutor = Libros.IdAutor
			JOIN Subcategorias ON subcategorias.IdSubCategoria = Libros.IdSubCategoria
			JOIN Categorias ON Categorias.IdCategoria = Subcategorias.IdCategoria
			JOIN Ejemplares ON Ejemplares.IdLibro = Libros.IdLibro
			JOIN Almacen ON Almacen.IdEjemplar = Ejemplares.IdEjemplar
			JOIN Editoriales ON Editoriales.IdEditorial = Ejemplares.IdEditorial
			WHERE  Editoriales.IdEditorial = ?
			order by Libros.Titulo asc";
		$libro = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
				$con = (new ConexionBaseDatos)->getConexion();
				$stmt = $con->prepare($sql);
				$stmt->bindParam(1,$idEditorial,PDO::PARAM_INT);
				$stmt->execute();
				while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
						$libro[] = [

				'LIBROS_IDLIBRO' => $row['LIBROS_IDLIBRO'],
				'ID_CATEGORIA' => $row['ID_CATEGORIA'],
				'NOMBRE_CATEGORIA' => $row['NOMBRE_CATEGORIA'],
				'ID_SUBCATEGORIA' => $row['ID_SUBCATEGORIA'],
				'NOMBRE_SUBCATEGORIA' => $row['NOMBRE_SUBCATEGORIA'],
				'LIBRO_TITULO' => $row['LIBRO_TITULO'],
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
				'EJEMPLARES_ID' => $row['EJEMPLARES_ID'],
				'ID_EDITORIAL' => $row['ID_EDITORIAL'],
				'NOMBRE_EDITORIAL' => $row['NOMBRE_EDITORIAL']
						];
				}
		$con = null;
		$stmt = null;
		return $libro;
	}//fin metodo

}//fin metodo
