<?php

class AlmacenRepositorio
{
	public function comprobarStockExistencias(int $idTienda,int $idEjemplar) :bool{
		$confirmacion =false;
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stock= 0;
		$sql = "SELECT stock FROM dbo.almacen WHERE idTienda LIKE ? AND idEjemplar LIKE ?;";
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$idTienda,PDO::PARAM_INT);
		$stmt->bindParam(2,$idEjemplar,PDO::PARAM_INT);
		$stmt->execute();
		while ( $row = $stmt->fetch( PDO::FETCH_ASSOC ) ){
			$stock = $row['stock'];
		}
		if($stock < 1){
			$confirmacion =false;
		}elseif($stock > 0){
			$confirmacion =true;
		}
		$con = null;
		$stmt = null;
		return $confirmacion;
	}//fin metodo

	public function devolverTodosLibrosAlmacen(int $tienda) :array{
		$sql = "SELECT ALMACEN_STOCK, TIENDAS_ID, LIBROS_IDLIBRO, ID_CATEGORIA, NOMBRE_CATEGORIA, ID_SUBCATEGORIA, NOMBRE_SUBCATEGORIA, LIBRO_TITULO, EJEMPLARES_YEARPUBLICACION,
					EJEMPLARES_FECHA_DISPONIBILIDAD ,AUTOR_NOMBRE , EJEMPLARES_ENCUADERNACION, EJEMPLARES_NUMERO_EDICION, EJEMPLARES_FORMATO, EJEMPLARES_IDIOMA, EJEMPLARES_ISBN,
					EJEMPLARES_PAGINAS, EJEMPLARES_PVP, LIBRO_DESCRIPCION, EJEMPLARES_PORTADA, EJEMPLARES_ID
			FROM libroIndividualAlmacen
			WHERE TIENDAS_ID = ? ORDER BY LIBRO_TITULO ASC;";
		$libro = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
				$con = (new ConexionBaseDatos)->getConexion();
				$stmt = $con->prepare($sql);
				$stmt->bindParam(1,$tienda,PDO::PARAM_INT);
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
				'EJEMPLARES_ID' => $row['EJEMPLARES_ID']
						];
				}
		$con = null;
		$stmt = null;
		return $libro;
	}//fin metodo

	public function devolverLibrosAlmacen(int $tienda,int $categoria,int $subcategoria) :array{
		//LLAMAMOS A LA VISTA libroIndividual
		$sql = "SELECT ALMACEN_STOCK, TIENDAS_ID, LIBROS_IDLIBRO, ID_CATEGORIA, NOMBRE_CATEGORIA, ID_SUBCATEGORIA, NOMBRE_SUBCATEGORIA, LIBRO_TITULO, EJEMPLARES_YEARPUBLICACION,
        	EJEMPLARES_FECHA_DISPONIBILIDAD ,AUTOR_NOMBRE , EJEMPLARES_ENCUADERNACION, EJEMPLARES_NUMERO_EDICION, EJEMPLARES_FORMATO, EJEMPLARES_IDIOMA, EJEMPLARES_ISBN,
        	EJEMPLARES_PAGINAS, EJEMPLARES_PVP, LIBRO_DESCRIPCION, EJEMPLARES_PORTADA, EJEMPLARES_ID
			FROM libroIndividualAlmacen
			WHERE TIENDAS_ID = ? AND ID_SUBCATEGORIA = ? AND ID_CATEGORIA = ? ORDER BY LIBRO_TITULO ASC;";
		$libro = [];
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
        $con = (new ConexionBaseDatos)->getConexion();
        $stmt = $con->prepare($sql);
        $stmt->bindParam(1,$tienda,PDO::PARAM_INT);
        $stmt->bindParam(2,$subcategoria,PDO::PARAM_INT);
        $stmt->bindParam(3,$categoria,PDO::PARAM_INT);
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
				'EJEMPLARES_ID' => $row['EJEMPLARES_ID']
            ];
        }
		$con = null;
		$stmt = null;
    return $libro;
	}//fin metodo

	public function devolverExistenciasStockEjemplar(int $idTienda,int $idEjemplar) :int{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stock= 0;
		$sql = "SELECT stock FROM dbo.almacen WHERE idTienda LIKE ? AND idEjemplar LIKE ?;";
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$idTienda,PDO::PARAM_INT);
		$stmt->bindParam(2,$idEjemplar,PDO::PARAM_INT);
		$stmt->execute();
		while ( $row = $stmt->fetch( PDO::FETCH_ASSOC ) ){
			$stock = $row['stock'];
		}
		$con = null;
		$stmt = null;
		return $stock;
	}//fin metodo

	public function compararPedidoExistenciaStockEjemplar(int $idTienda,int $idEjemplar, int $cantidad) :bool{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$stock= 0;$boolStock = true;
        $sql = "SELECT stock FROM dbo.almacen WHERE idTienda LIKE ? AND idEjemplar LIKE ?;";
		$stmt = $con->prepare($sql);
		$stmt->bindParam(1,$idTienda,PDO::PARAM_INT);
		$stmt->bindParam(2,$idEjemplar,PDO::PARAM_INT);
		$stmt->execute();
		while ( $row = $stmt->fetch( PDO::FETCH_ASSOC ) ){
			$stock = $row['stock'];
			if($cantidad > $stock){
				$boolStock = false;//si la cantidad es mayor que el stock
			}
		}
		$con = null;
		$stmt = null;
		return $boolStock;
	}//fin metodo

	public function modificarStock(int $idTienda,int $idEjemplar,int $stockModificado) :bool{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$boolStock= false;
		try{
			$con->beginTransaction();
			$sql = "UPDATE Almacen SET stock =  ? WHERE idTienda = ? AND idEjemplar = ?;";
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$stockModificado,PDO::PARAM_INT);
			$stmt->bindParam(2,$idTienda,PDO::PARAM_INT);
			$stmt->bindParam(3,$idEjemplar,PDO::PARAM_INT);
			if($stmt->execute()){
				$boolStock= true;
			}
			$con->commit();
			return $boolStock;
		}catch(PDOException  $eX ){
			echo "Error: ".$eX;
			$con->rollback();
		}finally {
			$con = null;
			$stmt = null;
		}
	}//fin metodo

	public function quitarStockExistencias(int $idTienda,int $idEjemplar,int $cantidad) :bool{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$boolStock= false;
		try{
			$con->beginTransaction();
			$sql = "UPDATE Almacen SET stock =  (stock - ?) WHERE idTienda = ? AND idEjemplar = ?;";
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$cantidad,PDO::PARAM_INT);
			$stmt->bindParam(2,$idTienda,PDO::PARAM_INT);
			$stmt->bindParam(3,$idEjemplar,PDO::PARAM_INT);
			if($stmt->execute()){
				$boolStock= true;
			}
			$con->commit();
			return $boolStock;
		}catch(PDOException  $eX ){
			echo "Error: ".$eX;
			$con->rollback();
		}finally {
			$con = null;
			$stmt = null;
		}
	}//fin metodo

	public function sumarCantidadStockExistencias(int $idTienda,int $idEjemplar,int $cantidad) :bool{
		include_once __DIR__ . '/../../core/conexionBaseDatos.inc';
		$con = (new ConexionBaseDatos)->getConexion();
		$boolStock= false;
		try{
			$con->beginTransaction();
			$sql = "UPDATE Almacen SET stock =  (stock + ?) WHERE idTienda = ? AND idEjemplar = ?;";
			$stmt = $con->prepare($sql);
			$stmt->bindParam(1,$cantidad,PDO::PARAM_INT);
			$stmt->bindParam(2,$idTienda,PDO::PARAM_INT);
			$stmt->bindParam(3,$idEjemplar,PDO::PARAM_INT);
			if($stmt->execute()){
				$boolStock= true;
			}
			$con->commit();
			return $boolStock;
		}catch(PDOException  $eX ){
			echo "Error: ".$eX;
			$con->rollback();
		}finally {
			$con = null;
			$stmt = null;
		}
	}//fin metodo



}//FIN CLASE
