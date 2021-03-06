<?php

class SubCategoriasRepositorio
{

  public function devolverSubCategorias(int $IdCategoria) :array{
      $sql = "SELECT  NUMERO_LIBROS, IdSubCategoria, NombreSubCategoria, Descripcion, IdCategoria
        FROM librosPorSubcategorias WHERE IdCategoria = ?;";
        $subCategorias = [];$arraySubCategorias=[];
        include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
    	$con = (new ConexionBaseDatos)->getConexion();
    	$stmt = $con->prepare($sql);
    	$stmt->bindParam(1,$IdCategoria,PDO::PARAM_INT);
    	$stmt->execute();
    	while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
    		$subCategorias  = [
    			'NUMERO_LIBROS' => $row['NUMERO_LIBROS'],
    			'IdSubCategoria' => $row['IdSubCategoria'],
    			'NombreSubCategoria' => $row['NombreSubCategoria'],
    			'Descripcion' => $row['Descripcion']
    		];
    		$arraySubCategorias[]=$subCategorias;
    	}
    	$stmt = null;
    	$con = null;
    	return $arraySubCategorias;
  }//fin metodo

  public function verSubCategoriasAdministrador() :array{
      $sql = "SELECT IdSubCategoria,NombreSubCategoria,Descripcion,IdCategoria,Alias FROM SubCategorias;";
      $listaSubCategoria = [];
        include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
        include_once __DIR__ . '/../../fuente/Modelo/subCategorias.inc';
  	  $con = (new ConexionBaseDatos)->getConexion();
  	  $stmt = $con->prepare($sql);
  	  $stmt->execute();
  	  while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
  		  $subCategoria = new SubCategorias($row);
  		  $listaSubCategoria[] = $subCategoria;
  	  }
  	  $stmt = null;
  	  $con = null;
	  return $listaSubCategoria;
  }//fin metodo

  public function borrarSubCategoriaAdministrador(int $idSubCategoria) :bool{
      $sql = "DELETE FROM SubCategorias WHERE IdSubCategoria = ?;";
      $boolean = false;
      include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
      try{
          $con = (new ConexionBaseDatos)->getConexion();
          $con->beginTransaction();
          $stmt = $con->prepare($sql);
          $stmt->bindParam(1,$idSubCategoria,PDO::PARAM_INT);
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

  public function devolverSubCategoriasPorId(int $idSubCategoria) :array{
    include_once __DIR__ . '/../../fuente/Modelo/SubCategorias.inc';
    $sql = "SELECT  IdSubCategoria,NombreSubCategoria,Descripcion,IdCategoria,Alias FROM SubCategorias WHERE IdSubCategoria =?;";
    $arraySubCategorias=[];
    include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
          $con = (new ConexionBaseDatos)->getConexion();
          $stmt = $con->prepare($sql);
          $stmt->bindParam(1,$idSubCategoria,PDO::PARAM_INT);
          $stmt->execute();
          while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
              $subCategoria = new SubCategorias($row);
              $arraySubCategorias[] = $subCategoria;
          }
	$stmt = null;
	$con = null;
	return $arraySubCategorias;
  }//fin metodo

  public function modificarSubCategoriaAdministradorId(int $idSubCategoria,string $nombreSubCategoria,string $descripcion) :bool{
    $sql = "UPDATE SubCategorias SET NombreSubCategoria = ?, Descripcion = ? WHERE IdSubCategoria = ?;";
    $boolean = false;
    include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
    try{
        $con = (new ConexionBaseDatos)->getConexion();
        $con->beginTransaction();
        $stmt = $con->prepare($sql);
        $stmt->bindParam(1,$nombreSubCategoria,PDO::PARAM_STR);
        $stmt->bindParam(2,$descripcion,PDO::PARAM_STR);
        $stmt->bindParam(3,$idSubCategoria,PDO::PARAM_INT);
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

  public function introducirSubCategoriaAdministrador($nombreSubCategoria,$nombreAlias,$descripcion,$idCategoria) :bool{
    $sql = "INSERT INTO SubCategorias(NombreSubCategoria,Descripcion,IdCategoria,Alias) VALUES(?,?,?,?);";
    $boolean = false;
    include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
    try{
        $con = (new ConexionBaseDatos)->getConexion();
        $con->beginTransaction();
        $stmt = $con->prepare($sql);
        $stmt->bindParam(1,$nombreSubCategoria,PDO::PARAM_STR);
        $stmt->bindParam(2,$descripcion,PDO::PARAM_STR);
        $stmt->bindParam(3,$idCategoria,PDO::PARAM_INT);
        $stmt->bindParam(4,$nombreAlias,PDO::PARAM_STR);
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

  public function crearCarpetaSubCategoria(string $nombreAlias,array $categoria){
			$boolean = false;
      $aliasCategoria = $categoria[0]->getAlias();
			$carpeta = 'C:/xampp/htdocs/ProyectoLibrosHector1/Imagenes/'.$aliasCategoria.'/'.$nombreAlias;
			if (!file_exists($carpeta)) {
					mkdir($carpeta, 0777, true);
					$boolean = true;
			}
			return $boolean;
	}//fin metodo

  public function comprobarDuplicadosNombresSubCategorias(string $nombreSubCategoria,string $nombreAlias) :bool{
        $sql = "SELECT NombreSubCategoria,Alias FROM SubCategorias;";
        $boolean = true;
        include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
        $con = (new ConexionBaseDatos)->getConexion();
        $stmt = $con->prepare($sql);
        $stmt->execute();
        while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
            if($row['NombreSubCategoria'] == $nombreSubCategoria || $row['Alias'] == $nombreAlias){
                $boolean = false;
            }
        }
        $stmt = null;
        $con = null;
        return $boolean;
  }//fin metodo

  public function devolverArrayNombresCategorias(array $subCategorias) :array{
        $arrayNombres = [];
        include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
        $sql = "SELECT NombreCategoria FROM Categorias WHERE IdCategoria = ?";
        foreach ($subCategorias as $key => $value) {
            $idCategoria  = (int)$value->getIdCategoria();
            $con = (new ConexionBaseDatos)->getConexion();
            $stmt = $con->prepare($sql);
            $stmt->bindParam(1,$idCategoria,PDO::PARAM_INT);
            $stmt->execute();
            while ( $row = $stmt->fetch( PDO::FETCH_ASSOC ) ){
              $arrayNombres[] = $row['NombreCategoria'];
            }
            $stmt =null;
            $con=null;
        }
        return $arrayNombres;
  }//fin metodo


  public function devolverNumeroLibrosSubCategoria(int $idSubCategoria) :int{
      include_once __DIR__ . '/../../core/ConexionBaseDatos.inc';
      $sql = "SELECT COUNT(Libros.IdLibro) AS NUMERO_LIBROS FROM Libros
      JOIN SubCategorias ON SubCategorias.IdSubCategoria = Libros.IdSubCategoria
      WHERE SubCategorias.IdSubCategoria = ?";
      $n = 0;
  	  $con = (new ConexionBaseDatos)->getConexion();
  	  $stmt = $con->prepare($sql);
      $stmt->bindParam(1,$idSubCategoria,PDO::PARAM_INT);
  	  $stmt->execute();
  	  while($row =$stmt->fetch(PDO::FETCH_ASSOC)){
  		  $n = $row['NUMERO_LIBROS'];
  	  }
  	  $stmt = null;
  	  $con = null;
	     return $n;
  }//fin metodo

}///fin clase
