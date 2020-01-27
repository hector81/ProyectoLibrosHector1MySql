<?php

class AutoresRepositorio
{
	public function devolverAutoresTotales() :array{
				include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
				include_once __DIR__ . '/../../fuente/modelo/autores.inc';
				$con = (new ConexionBaseDatos)->getConexion();
				$sql = "SELECT IdAutor,Nombre,Nacionalidad,IdPais FROM Autores  ORDER BY Nombre ASC;";
				$autores =[];
				$stmt = $con->prepare($sql);
				$stmt->execute();
				while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
					$autores[] = new Autores($row);
				}
				$con = null;
				$stmt = null;
				return $autores;
	}//fin metodo

	public function devolverNumeroLibrosAutor(int $idAutor) :int{
				include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
				$con = (new ConexionBaseDatos)->getConexion();
				$sql = "SELECT COUNT(Libros.IdLibro) as cuentas FROM Autores
								JOIN Libros ON Libros.IdAutor = Autores.IdAutor
								WHERE Autores.IdAutor = ?;";
				$cont =0;
				$stmt = $con->prepare($sql);
				$stmt->bindParam(1,$idAutor,PDO::PARAM_INT);
				$stmt->execute();
				while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
					$cont= $row['cuentas'];
				}
				$con = null;
				$stmt = null;
				return $cont;
	}//fin metodo

	public function devolverAutoresTotalesPorTienda(int $idTienda) :array{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		include_once __DIR__ . '/../../fuente/modelo/autores.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$sql = "SELECT Autores.IdAutor,Autores.Nombre,Autores.Nacionalidad,Autores.IdPais FROM Autores
				JOIN Libros ON Libros.IdAutor = Autores.IdAutor
				JOIN Ejemplares ON Ejemplares.IdLibro = Libros.IdLibro
				JOIN Almacen ON Almacen.IdEjemplar = Ejemplares.IdEjemplar
				WHERE Almacen.IdTienda = ?
				ORDER BY Nombre ASC";
		$autores =[];
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$idTienda,PDO::PARAM_INT);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			$autores[] = new Autores($row);
		}
		$con = null;
		$stmt = null;
		return $autores;
	}//fin metodo



	public function devolverAutorPorId(int $idAutor) :array{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		include_once __DIR__ . '/../../fuente/modelo/autores.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$sql = "SELECT IdAutor,Nombre,Nacionalidad,IdPais FROM Autores WHERE IdAutor = ?;";
		$autor =[];
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$idAutor,PDO::PARAM_INT);
		$stmt->execute();
		while($row = $stmt->fetch(PDO::FETCH_ASSOC)){
			$autor[] = new Autores($row);
		}
		$con = null;
		$stmt = null;
		return $autor;
	}//fin metodo

	public function introducirAutor(string $nombreAutor,int $idPais,string $nacionalidad) :bool{
		$sql ="INSERT INTO Autores(Nombre,Nacionalidad,IdPais) VALUES(?,?,?)";
		$respuesta = false;
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
			try{
				$con = (new ConexionBaseDatos)->getConexion();
				$con->beginTransaction();
				$stmt = $con->prepare($sql);
				$stmt->bindParam(1,$nombreAutor,PDO::PARAM_STR);
				$stmt->bindParam(2,$nacionalidad,PDO::PARAM_STR);
				$stmt->bindParam(3,$idPais,PDO::PARAM_INT);
				if($stmt->execute()){
				  $respuesta = true;
				}
				$con->commit();

			}catch(PDOException $ex){
			   throw $ex;
			   $con->rollBack();
			}finally{
			  $con = null;
			  $stmt = null;
			}
		return $respuesta;
	}//fin metodo

	public function borrarAutorAdministrador(int $idAutor) :bool{
      $sql = "DELETE FROM Autores WHERE IdAutor = ?;";
      $boolean = false;
      include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
      try{
          $con = (new ConexionBaseDatos)->getConexion();
          $con->beginTransaction();
          $stmt = $con->prepare($sql);
          $stmt->bindParam(1,$idAutor,PDO::PARAM_INT);
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

	public function modificarAutor(string $nombreAutor,int $idPais,int $idAutor,string $nacionalidad) :bool{
			$sql = "UPDATE Autores SET Nombre = ?, Nacionalidad = ?, IdPais = ? WHERE IdAutor = ?;";
			$boolean = false;
			include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
			try{
					$con = (new ConexionBaseDatos)->getConexion();
					$con->beginTransaction();
					$stmt = $con->prepare($sql);
					$stmt->bindParam(1,$nombreAutor,PDO::PARAM_STR);
					$stmt->bindParam(2,$nacionalidad,PDO::PARAM_STR);
					$stmt->bindParam(3,$idPais,PDO::PARAM_INT);
					$stmt->bindParam(4,$idAutor,PDO::PARAM_INT);
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

	public function devolverTodosLibrosAlmacenPorAutor(int $tienda,int $idAutor) :array{
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
				Tiendas.IdTienda AS ID_TIENDA
			FROM Libros
			JOIN Autores ON Autores.IdAutor = Libros.IdAutor
			JOIN Subcategorias ON subcategorias.IdSubCategoria = Libros.IdSubCategoria
			JOIN Categorias ON Categorias.IdCategoria = Subcategorias.IdCategoria
			JOIN Ejemplares ON Ejemplares.IdLibro = Libros.IdLibro
			JOIN Almacen ON Almacen.IdEjemplar = Ejemplares.IdEjemplar
			JOIN Tiendas ON Tiendas.IdTienda = Almacen.IdTienda
			WHERE Tiendas.IdTienda = ? AND Autores.IdAutor = ?

			GROUP BY Almacen.stock,Tiendas.IdTienda,Libros.IdLibro,Categorias.NombreCategoria,Categorias.IdCategoria,SubCategorias.IdSubCategoria
				,Subcategorias.NombreSubCategoria,Libros.Titulo,Ejemplares.YearPublicacion,Ejemplares.FechaDisponibilidad
				,Ejemplares.FechaDisponibilidad,Autores.Nombre,Ejemplares.Encuadernacion,Ejemplares.NumeroEdicion,Ejemplares.Formato
				,Ejemplares.Idioma,Ejemplares.ISBN,Ejemplares.Paginas,Ejemplares.PVP,Libros.Descripcion,Ejemplares.Portada,Ejemplares.IdEjemplar,Tiendas.IdTienda
			order by Libros.Titulo asc";
		$libro = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
				$con = (new ConexionBaseDatos)->getConexion();
				$stmt = $con->prepare($sql);
				$stmt->bindParam(1,$tienda,PDO::PARAM_INT);
				$stmt->bindParam(2,$idAutor,PDO::PARAM_INT);
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
				'ID_TIENDA' => $row['ID_TIENDA']
						];
				}
		$con = null;
		$stmt = null;
		return $libro;
	}//fin metodo

	public function devolverTodosLibrosPorAutor(int $idAutor){
		$sql = "
		SELECT DISTINCT
				Almacen.stock AS ALMACEN_STOCK,
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
				Ejemplares.IdEjemplar AS EJEMPLARES_ID
			FROM Libros
			JOIN Autores ON Autores.IdAutor = Libros.IdAutor
			JOIN Subcategorias ON subcategorias.IdSubCategoria = Libros.IdSubCategoria
			JOIN Categorias ON Categorias.IdCategoria = Subcategorias.IdCategoria
			JOIN Ejemplares ON Ejemplares.IdLibro = Libros.IdLibro
			JOIN Almacen ON Almacen.IdEjemplar = Ejemplares.IdEjemplar
			WHERE Autores.IdAutor = ?

			order by Libros.Titulo asc";
		$libro = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
				$con = (new ConexionBaseDatos)->getConexion();
				$stmt = $con->prepare($sql);
				$stmt->bindParam(1,$idAutor,PDO::PARAM_INT);
				$stmt->execute();
				while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
						$libro[] = [
				'ALMACEN_STOCK' => $row['ALMACEN_STOCK'],
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
				'EJEMPLARES_ID' => $row['EJEMPLARES_ID']
						];
				}
		$con = null;
		$stmt = null;
		return $libro;
	}//fin metodo

}//fin clase

?>
