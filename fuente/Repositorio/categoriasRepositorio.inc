<?php

class CategoriasRepositorio
{

	public function devolverCategorias() :array{
		$sql = "SELECT  NUMERO_LIBROS, IdCategoria, NombreCategoria, Descripcion
			FROM librosPorMateria;";
		$categorias = [];$arrayCategorias=[];
		include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
        $con = (new ConexionBaseDatos)->getConexion();
        $stmt = $con->prepare($sql);
        $stmt->execute();
        while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
            $categorias  = [
                'NUMERO_LIBROS' => $row['NUMERO_LIBROS'],
                'IdCategoria' => $row['IdCategoria'],
                'NombreCategoria' => $row['NombreCategoria'],
                'Descripcion' => $row['Descripcion'],
            ];
            $arrayCategorias[]=$categorias;
        }
		$con = null;
		$stmt = null;
		return $arrayCategorias;
	}//fin metodo

	public function verCategoriasAdministrador() :array{
		$sql = "SELECT IdCategoria, NombreCategoria, Descripcion,Alias FROM Categorias;";
		$listaCategoria = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		include_once __DIR__ . '/../../fuente/Modelo/Categorias.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->execute();
		while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
			$categoria = new Categorias($row);
			$listaCategoria[] = $categoria;
		}
		$con = null;
		$stmt = null;
		return $listaCategoria;
	}//fin metodo

	public function borrarCategoriaAdministrador(int $idCategoria) :bool{
		$sql = "DELETE FROM Categorias WHERE IdCategoria = ?;";
		$boolean = false;
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		try{
			$con = (new ConexionBaseDatos)->getConexion();
			$con->beginTransaction();
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$idCategoria,PDO::PARAM_INT);
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

	public function devolverCategoriasPorId(int $idCategoria) :array{
		include_once __DIR__ . '/../../fuente/Modelo/Categorias.inc';
		$sql = "SELECT  IdCategoria, NombreCategoria, Descripcion,Alias FROM Categorias WHERE IdCategoria =?;";
		$arrayCategorias=[];
		include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$idCategoria,PDO::PARAM_INT);
		$stmt->execute();
		while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
			$categoria = new Categorias($row);
			$arrayCategorias[] = $categoria;
		}
		$con = null;
		$stmt = null;
		return $arrayCategorias;
	}//fin metodo

	public function modificarCategoriaAdministradorId(int $idCategoria,string $nombreCategoria,string $descripcion) :bool{
		$sql = "UPDATE Categorias SET NombreCategoria = ?, Descripcion = ? WHERE IdCategoria = ?;";
		$boolean = false;
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		try{
			$con = (new ConexionBaseDatos)->getConexion();
			$con->beginTransaction();
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$nombreCategoria,PDO::PARAM_STR);
			$stmt->bindParam(2,$descripcion,PDO::PARAM_STR);
			$stmt->bindParam(3,$idCategoria,PDO::PARAM_INT);
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

	public function introducirCategoriaAdministrador(string $nombreCategoria,string $nombreAlias,string $descripcion) :bool{
		$sql = "INSERT INTO Categorias(NombreCategoria,Descripcion,Alias) VALUES(?,?,?);";
		$boolean = false;
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		try{
			$con = (new ConexionBaseDatos)->getConexion();
			$con->beginTransaction();
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$nombreCategoria,PDO::PARAM_STR);
			$stmt->bindParam(2,$descripcion,PDO::PARAM_STR);
			$stmt->bindParam(3,$nombreAlias,PDO::PARAM_INT);
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

	public function crearCarpetaCategoria(string $nombreAlias){
			$boolean = false;
			$carpeta = 'C:/xampp/htdocs/ProyectoLibrosHector1/Imagenes/'.$nombreAlias;
			if (!file_exists($carpeta)) {
					mkdir($carpeta, 0777, true);
					$boolean = true;
			}
			return $boolean;
	}//fin metodo

	public function comprobarDuplicadosNombresCategorias(string $nombreCategoria,string $nombreAlias) :bool{
        $sql = "SELECT NombreCategoria,Alias FROM Categorias;";
        $boolean = true;
        include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
        $con = (new ConexionBaseDatos)->getConexion();
        $stmt = $con->prepare($sql);
        $stmt->execute();
        while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
            if($row['NombreCategoria'] == $nombreCategoria || $row['Alias'] == $nombreAlias){
                $boolean = false;
            }
        }
        $stmt = null;
        $con = null;
        return $boolean;
  }//fin metodo


	public function devolverNumeroLibrosCategoria(int $idCategoria) :int{
      include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
      $sql = "SELECT COUNT(Libros.IdLibro) AS NUMERO_LIBROS FROM Libros
							JOIN SubCategorias ON SubCategorias.IdSubCategoria = Libros.IdSubCategoria
							JOIN Categorias ON Categorias.IdCategoria = SubCategorias.IdCategoria
							WHERE Categorias.IdCategoria = ?";
      $n = 0;
  	  $con = (new ConexionBaseDatos)->getConexion();
  	  $stmt = $con->prepare($sql);
      $stmt->bindParam(1,$idCategoria,PDO::PARAM_INT);
  	  $stmt->execute();
  	  while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
  		  $n = $row['NUMERO_LIBROS'];
  	  }
  	  $stmt = null;
  	  $con = null;
	     return $n;
  }//fin metodo

}//fin clase
